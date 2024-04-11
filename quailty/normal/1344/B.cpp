#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int n,m;
char str[MAXN][MAXN];
int vis[MAXN][MAXN];
void dfs(int x,int y,int id)
{
    vis[x][y]=id;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            if(abs(i)+abs(j)!=1)continue;
            int tx=x+i,ty=y+j;
            if(tx<1 || tx>n || ty<1 || ty>m)continue;
            if(str[tx][ty]=='#' && !vis[tx][ty])
                dfs(tx,ty,id);
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='#' && !vis[i][j])
                dfs(i,j,++cnt);
    int emp_x=0,emp_y=0;
    for(int i=1;i<=n;i++)
    {
        int las=0;
        for(int j=1;j<=m;j++)
            if(vis[i][j]>0 && vis[i][j]!=vis[i][j-1])
            {
                if(las)return 0*printf("-1\n");
                las=vis[i][j];
            }
        if(!las)emp_x++;
    }
    for(int j=1;j<=m;j++)
    {
        int las=0;
        for(int i=1;i<=n;i++)
            if(vis[i][j]>0 && vis[i][j]!=vis[i-1][j])
            {
                if(las)return 0*printf("-1\n");
                las=vis[i][j];
            }
        if(!las)emp_y++;
    }
    if((emp_x>0 && emp_y>0) || (emp_x==0 && emp_y==0))
        printf("%d\n",cnt);
    else printf("-1\n");
    return 0;
}