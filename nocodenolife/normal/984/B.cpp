#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int row,col;
    cin>>row>>col;
    char board[row+2][col+2];
    for(int i=0;i<=row+1;i++)
    {
        board[i][0]='0';
        board[i][col+1]='0';
    }
    for(int i=0;i<=col+1;i++)
    {
        board[0][i]='0';
        board[row+1][i]='0';
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='.')
                board[i][j]='0';
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(board[i][j]=='*')
                continue;
            int find = (int) board[i][j]-'0';
            int ans=0;
            if(board[i-1][j]=='*')
                ans++;
            if(board[i-1][j-1]=='*')
                ans++;
            if(board[i-1][j+1]=='*')
                ans++;
            if(board[i][j-1]=='*')
                ans++;
            if(board[i][j+1]=='*')
                ans++;
            if(board[i+1][j-1]=='*')
                ans++;
            if(board[i+1][j]=='*')
                ans++;
            if(board[i+1][j+1]=='*')
                ans++;
            if(ans!=find)
            {
                row=-1;
                break;
            }
        }
    }
    if(row==-1)
        cout<<"NO";
    else
        cout<<"YES";
    
    return 0;
}