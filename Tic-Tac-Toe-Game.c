#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char  player1[15];
char  player2[15];

void SetColor(int ForgC);

char board[3][3]={
                   {'1','2','3'},
                   {'4','5','6'},
                   {'7','8','9'}
                 };
int player = 1;
int choice ;
int winner ;
int over = 0 ; // 0 Game is not over , 1 Game over
int movecount =0 ;
int m,n;
/*
print the board
*/

void printboard()
{
    system("cls");

SetColor(11);



    printf("\t(Tic Tac Toe Game)\t");
    int i , j ;
    SetColor(46);

    printf("\n................................\n");
    for(i=0 ; i<3 ; i++)
    {
        for (j=0 ; j<3 ;j++)
        printf("    |    %c"   , board[i][j]);
        printf(" \n") ;
        printf("................................\n") ;
    }
}

void play ()

{
    char value ;

     player = (player % 2) ? 1 : 2;

      SetColor(10);


      if(player==1){printf("%s is  ", player1);

      }

      else { printf("%s is  ", player2);}


    printf("player %d ,please choose a cell:" , player);
    scanf("%d" , &choice);
    value = (player == 1) ? 'X' : 'O';

    switch(choice)
    {
        case 1 :
            if (board [0][0] == 'X' || board [0][0] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[0][0] = value ;
                }
                break;
        case 2 :
            if (board [0][1] == 'X' || board [0][1] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[0][1] = value ;
                }
                break;
        case 3 :
            if (board [0][2] == 'X' || board [0][2] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[0][2] = value ;
                }
                break;
        case 4 :
            if (board [1][0] == 'X' || board [1][0] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[1][0] = value ;
                }
                break;
        case 5 :
            if (board [1][1] == 'X' || board [1][1] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[1][1] = value ;
                }
                break;
        case 6 :
            if (board [1][2] == 'X' || board [1][2] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[1][2] = value ;
                }
                break;
        case 7 :
            if (board [2][0] == 'X' || board [2][0] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[2][0] = value ;
                }
                break;
        case 8 :
            if (board [2][1] == 'X' || board [2][1] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[2][1] = value ;
                }
                break;
        case 9 :
            if (board [2][2] == 'X' || board [2][2] == 'O' ) {
                    printf ("invalid move");}
            else {
                board[2][2] = value ;
                }
                break;
        default:
            printf("Invalid move");
    }
    movecount++ ;
}
void gameover()
{
    //rows
    int i ;
    for ( i =0 ;i<3 ; i++)
        if((board[i][0]==board [i][1]) && (board[i][1]== board[i][2]))
        {
            if(board[i][0]=='X')
                           winner = 1 ;
                  else
                           winner = 2 ;
                 over = 1;
                return ;
        }
   //col
   int j ;
   for ( j =0 ;j<3 ; j++)
        if((board[0][j]==board [1][j]) && (board[1][j]== board[2][j]))

        {
            if(board[0][j]=='X')
                           winner = 1 ;
                  else
                           winner = 2 ;
                  over = 1;
                  return ;

       }

   //m dio
   if((board[0][0]==board [1][1]) && (board[1][1]== board[2][2]))

        {
            if(board[0][0]=='X')
                          winner = 1 ;
                    else
                          winner = 2 ;
                    over = 1;
                    return ;
        }
        if((board[0][2]==board [1][1]) && (board[1][1]== board[2][0]))

        {
            if(board[0][2]=='X')
                           winner = 1 ;
                   else
                           winner = 2 ;
                   over = 1;
                   return ;
        }

        //eg
        if (movecount ==8)
        {
            winner = 0;
            over = 1 ;
        }
}

int main()
{

    printf("Enter first player's name: %s", player1);
    scanf("%s", player1);

    printf("\nEnter second player's name: %s", player2);
    scanf("%s", player2);

    printboard();

    while (over !=1)
    {
        play();
        printboard();
        gameover();
        if(player == 1)
            player =2 ;
        else
            player =1 ;
    }
    if (winner == 0)
        printf("NO WINNER\n");
    else
        printf("player %d is the winner\n" , winner);

    return 0 ;

}

//for coloring the output in the terminal
void SetColor(int ForgC)

 {

 WORD wColor;

 //This handle is needed to get the current background attribute



HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

 CONSOLE_SCREEN_BUFFER_INFO csbi;

 //csbi is used for wAttributes word



if(GetConsoleScreenBufferInfo(hStdOut, &csbi))

 {

 //To mask out all but the background attribute, and to add the color

 wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);

 SetConsoleTextAttribute(hStdOut, wColor);

 }

 return;

 }
