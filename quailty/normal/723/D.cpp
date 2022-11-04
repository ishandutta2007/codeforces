#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<vector<pair<int,int> > >world;
vector<pair<int,int> >lake;
void dfs(int x,int y,int n,int m)
{
    if(vis[x][y])return;
    vis[x][y]=1;
    lake.push_back(make_pair(x,y));
    for(int i=0;i<4;i++)
    {
        int tx=x+d[i][0];
        int ty=y+d[i][1];
        if(tx>0 && tx<=n && ty>0 && ty<=m && s[tx][ty]=='.')
            dfs(tx,ty,n,m);
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i][1] && s[i][1]=='.')
        {
            lake.clear();
            dfs(i,1,n,m);
        }
        if(!vis[i][m] && s[i][m]=='.')
        {
            lake.clear();
            dfs(i,m,n,m);
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(!vis[1][j] && s[1][j]=='.')
        {
            lake.clear();
            dfs(1,j,n,m);
        }
        if(!vis[n][j] && s[n][j]=='.')
        {
            lake.clear();
            dfs(n,j,n,m);
        }
    }
    world.clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[i][j] && s[i][j]=='.')
            {
                lake.clear();
                dfs(i,j,n,m);
                world.push_back(lake);
            }
    sort(world.begin(),world.end(),[](const vector<pair<int,int> >a,const vector<pair<int,int> >&b)
         {
             return a.size()<b.size();
         });
    int res=0;
    for(int i=0;i<(int)world.size()-k;i++)
    {
        res+=(int)world[i].size();
        for(int j=0;j<(int)world[i].size();j++)
        {
            int x=world[i][j].first,y=world[i][j].second;
            s[x][y]='*';
        }
    }
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
        printf("%s\n",s[i]+1);
    return 0;
}