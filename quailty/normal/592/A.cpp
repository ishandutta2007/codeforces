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
    int res[2]={10,10};
    for(int j=0;j<8;j++)
    {
        for(int i=0;i<8;i++)
            if(s[i][j]!='.')
            {
                if(s[i][j]=='W')res[0]=min(res[0],i+1);
                break;
            }
        for(int i=7;i>=0;i--)
            if(s[i][j]!='.')
            {
                if(s[i][j]=='B')res[1]=min(res[1],8-i);
                break;
            }
    }
    if(res[0]<=res[1])printf("A");
    else printf("B");
    return 0;
}