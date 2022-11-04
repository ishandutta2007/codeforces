#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[15][15];
int main()
{
    for(int i=0;i<8;i++)
        scanf("%s",s[i]);
    bool flag=0;
    int x,y;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(s[i][j]=='W')
            {
                flag=1;
                x=i;
                y=j;
            }
    if(!flag)return 0*printf("8");
    int res=0;
    for(int i=0;i<8;i++)
        res+=s[i][y]=='B';
    for(int j=0;j<8;j++)
        res+=s[x][j]=='B';
    return 0*printf("%d",res);
}