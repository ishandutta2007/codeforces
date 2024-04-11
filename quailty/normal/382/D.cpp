#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2005;
const int INF=0x3f3f3f3f;
char s[MAXN][MAXN];
int dis[MAXN][MAXN],vis[MAXN][MAXN];
int ex[MAXN][MAXN],ey[MAXN][MAXN];
void dfs(int x,int y)
{
    if(vis[x][y]==1)
    {
        if(!dis[x][y])dis[x][y]=INF;
        return;
    }
    vis[x][y]=1;
    int tx=x,ty=y;
    if(s[x][y]=='v')tx++;
    if(s[x][y]=='^')tx--;
    if(s[x][y]=='>')ty++;
    if(s[x][y]=='<')ty--;
    if(s[tx][ty]=='#')
    {
        dis[x][y]=1;
        ex[x][y]=x;
        ey[x][y]=y;
    }
    else
    {
        dfs(tx,ty);
        dis[x][y]=min(dis[tx][ty]+1,INF);
        ex[x][y]=ex[tx][ty];
        ey[x][y]=ey[tx][ty];
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]!='#' && !vis[i][j])
                dfs(i,j);
    int mx=0,lx=0,ly=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mx<dis[i][j])
            {
                mx=dis[i][j];
                lx=ex[i][j];
                ly=ey[i][j];
            }
    if(mx==INF)return 0*printf("-1");
    int buf=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            buf&=!(dis[i][j]==mx && (ex[i][j]!=lx || ey[i][j]!=ly));
    printf("%d",max(0,2*mx-buf));
    return 0;
}