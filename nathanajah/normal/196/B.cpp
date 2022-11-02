#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int n,m;
int i,j;
char c[2000][2000];
int sx,sy;
int sudah[2000][2000];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool bisa;

void dfs(int x, int y, int lapis)
{
    if (bisa)
        return;
    int i;
    int nx,ny,nlapis;
    for (i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        nlapis=lapis;
        if (nx<0)
        {
            nx+=n;
            nlapis-=5000;
        }
        if (nx>=n)
        {
            nx-=n;
            nlapis+=5000;
        }
        if (ny<0)
        {
            ny+=m;
            nlapis-=1;
        }
        if (ny>=m)
        {
            ny-=m;
            nlapis+=1;
        }
        if (c[nx][ny]=='.')
        {
            if (sudah[nx][ny]==-2000000000)
            {
                sudah[nx][ny]=nlapis;
                dfs(nx,ny,nlapis);
            }
            else if (sudah[nx][ny]!=nlapis)
                bisa=true;
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for (i=0;i<n;++i)
    {
        for (j=0;j<m;++j)
        {
            sudah[i][j]=-2000000000;
            cin >> c[i][j];
            if (c[i][j]=='S')
            {
                sx=i;
                sy=j;
                c[i][j]='.';
            }
        }
    }
    dfs(sx,sy,0);
    if(bisa)
        printf("Yes\n");
    else
        printf("No\n");
}