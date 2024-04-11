#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[10][10];
int main()
{
    for(int i=0;i<8;i++)
        scanf("%s",s[i]);
    int w=0,b=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(s[i][j]=='Q')w+=9;
            if(s[i][j]=='R')w+=5;
            if(s[i][j]=='B')w+=3;
            if(s[i][j]=='N')w+=3;
            if(s[i][j]=='P')w+=1;
            if(s[i][j]=='q')b+=9;
            if(s[i][j]=='r')b+=5;
            if(s[i][j]=='b')b+=3;
            if(s[i][j]=='n')b+=3;
            if(s[i][j]=='p')b+=1;
        }
    }
    if(w>b)printf("White");
    else if(w<b)printf("Black");
    else printf("Draw");
    return 0;
}