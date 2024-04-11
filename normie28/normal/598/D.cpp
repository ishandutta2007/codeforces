#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
int n,m,k;
char mp[1005][1005];
int vis[1005][1005];
int ans[1005][1005];
 int dir[4][2]={0,1,0,-1,-1,0,1,0};
int all=0;
int cnt;
struct node
{
    int x,y;
};
node f[1000005];
void dfs(int x,int y )
{
    vis[x][y]=1;
    cnt++;
    f[cnt].x=x,f[cnt].y=y;
    int tx,ty;
    for(int i=0;i<4;i++)
    {
        tx=x+dir[i][0],ty=y+dir[i][1];
        if(tx<=n&&tx>0&&ty<=m&&ty>0&& !vis[tx][ty])
        {
            if(mp[tx][ty]=='.')
                dfs(tx,ty);
            else
                all++;
        }
    }
    return ;
}
 
int main()
{
    scanf("%d%d%d",&n,&m,&k);
 
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&mp[i][1]);
    }
 
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]==0&&mp[i][j]=='.')
            {
                cnt=0,all=0;
                dfs(i,j);
                for(int k=1;k<=cnt;k++)
                    ans[f[k].x ][f[k].y ]=all;
            }
        }
    }
 
    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[x][y]);
    }
 
}