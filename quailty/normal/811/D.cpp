#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=105;
const int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//LRUD
const char ty[]="LRUD";
char s[MAXN][MAXN];
pair<int,int> query(int d)
{
    printf("%c\n",ty[d]);
    fflush(stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    return make_pair(a,b);
}
int vis[MAXN][MAXN],go[MAXN][MAXN];
void bfs(int n,int m)
{
    int sx=1,sy=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='F')
                sx=i,sy=j;
    queue<int>qx,qy;
    qx.push(sx),qy.push(sy);
    vis[sx][sy]=1;
    while(!qx.empty())
    {
        int nx=qx.front(),ny=qy.front();
        qx.pop(),qy.pop();
        for(int i=0;i<4;i++)
        {
            int tx=nx+dir[i][0],ty=ny+dir[i][1];
            if(tx>0 && tx<=n && ty>0 && ty<=m && s[tx][ty]=='.' && !vis[tx][ty])
            {
                vis[tx][ty]=1;
                go[tx][ty]=i^1;
                qx.push(tx),qy.push(ty);
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    bfs(n,m);
    int x=1,y=1,slr=0,sud=0;
    while(s[x][y]!='F')
    {
        int dir=(go[x][y]&2 ? go[x][y]^slr : go[x][y]^sud);
        pair<int,int> nxt=query(dir);
        int tx=nxt.first,ty=nxt.second;
        if(x==tx && y==ty)
        {
            if(go[x][y]&2)slr=1;
            else sud=1;
        }
        x=tx,y=ty;
    }
    return 0;
}