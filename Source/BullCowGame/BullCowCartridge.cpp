// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
        Super::BeginPlay();

        SetupGame();

        //PrintLine(TEXT("The HiddenWord is: %s. \nit's %i characters long"), *HiddenWord, HiddenWord.Len());
}
void UBullCowCartridge::OnInput(const FString& Input)
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}
void UBullCowCartridge::SetupGame()
{

        PrintLine(TEXT("Welcome to the Bull Cows game"));
        
        HiddenWord = (TEXT("bonks"));
        Lives = HiddenWord.Len();
        bGameOver = false;

        PrintLine(TEXT("Guess the %i letter Word"), HiddenWord.Len());
        PrintLine(TEXT("\nGuess then press Enter to conitnue"));
}
void UBullCowCartridge::EndGame()
    {
        
        bGameOver = true;
        PrintLine(TEXT("Press enter to play again."));
    }

void UBullCowCartridge::ProcessGuess(FString Guess)
{
        if (HiddenWord == Guess && Lives > 0)
        {
            PrintLine(TEXT("\nYou've won!"));
            EndGame();

        }
        else
        {
            --Lives;
            PrintLine(TEXT("You typed the wrong word \nBecause of that You've lost a life"));
            if (Lives > 0)
            {
                PrintLine(TEXT("\nYou now have %i lives remaining"), Lives);
            }
            else
            {
                PrintLine(TEXT("You've lost the game!"));
                EndGame();
            }
        }
}