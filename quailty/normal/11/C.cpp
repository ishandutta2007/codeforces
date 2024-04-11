#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=255;
const int d[8][2]=
{
    {1,1},{1,-1},{-1,-1},{-1,1},
    {0,1},{1,0},{0,-1},{-1,0}
};
char s[MAXN][MAXN];
int res,tot,vis[MAXN][MAXN];
queue<int>qx,qy,sx,sy;
int bfs(int x,int y,int n,int m)
{
    vis[x][y]=++tot;
    qx.push(x);
    qy.push(y);
    sx.push(x);
    sy.push(y);
    while(!qx.empty())
    {
        int ux=qx.front();
        qx.pop();
        int uy=qy.front();
        qy.pop();
        for(int i=0;i<8;i++)
        {
            int tx=ux+d[i][0];
            int ty=uy+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty]=='1' && !vis[tx][ty])
            {
                vis[tx][ty]=tot;
                qx.push(tx);
                qy.push(ty);
                sx.push(tx);
                sy.push(ty);
            }
        }
    }
    int len=0,f=0;
    if(y<m-1 && vis[x][y+1]==vis[x][y])f=1;
    for(int i=x,j=y;i<n && j<m;i+=d[4*f][0],j+=d[4*f][1])
    {
        if(s[i][j]=='1')len++;
        else break;
    }
    if(len<2)
    {
        while(!sx.empty())
        {
            sx.pop();
            sy.pop();
        }
        return 0;
    }
    int isok=1;
    for(int i=0;i<4;i++)
        for(int j=1;j<len;j++)
        {
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y]!=tot)isok=0;
            else vis[x][y]=0;
            x+=d[4*f+i][0];
            y+=d[4*f+i][1];
        }
    while(!sx.empty())
    {
        int ux=sx.front();
        sx.pop();
        int uy=sy.front();
        sy.pop();
        if(!vis[ux][uy])vis[ux][uy]=tot;
        else isok=0;
    }
    return isok;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        res=tot=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='1' && !vis[i][j])
                    res+=bfs(i,j,n,m);
        printf("%d\n",res);
    }
    return 0;
}