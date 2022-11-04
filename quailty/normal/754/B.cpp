#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[10][10];
bool check()
{
    for(int i=0;i<4;i++)
    {
        bool isok=1;
        for(int j=0;j<3;j++)
            isok&=(s[i][j]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=1;j<4;j++)
            isok&=(s[i][j]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=0;j<3;j++)
            isok&=(s[j][i]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=1;j<4;j++)
            isok&=(s[j][i]=='x');
        if(isok)return 1;
    }
    for(int i=-7;i<7;i++)
    {
        bool isok=1;
        for(int j=0;j<3;j++)
            isok&=(i+j>=0 && i+j<4 && s[i+j][j]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=1;j<4;j++)
            isok&=(i+j>=0 && i+j<4 && s[i+j][j]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=0;j<3;j++)
            isok&=(i-j>=0 && i-j<4 && s[i-j][j]=='x');
        if(isok)return 1;
        isok=1;
        for(int j=1;j<4;j++)
            isok&=(i-j>=0 && i-j<4 && s[i-j][j]=='x');
        if(isok)return 1;
    }
    return 0;
}
int main()
{
    for(int i=0;i<4;i++)
        scanf("%s",s[i]);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(s[i][j]=='.')
            {
                s[i][j]='x';
                if(check())return 0*printf("YES\n");
                s[i][j]='.';
            }
    return 0*printf("NO\n");
}