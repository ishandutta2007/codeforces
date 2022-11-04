#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int d[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
char s[105];
bool vis[205][205];
int main()
{
    int x=101,y=101;
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        int lx=x,ly=y;
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        if(s[i]=='U')y--;
        if(s[i]=='D')y++;
        if(vis[x][y])return 0*printf("BUG");
        for(int j=0;j<5;j++)
            vis[lx+d[j][0]][ly+d[j][1]]=1;
    }
    return 0*printf("OK");
}