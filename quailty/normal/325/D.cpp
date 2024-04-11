#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=3005;
const int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int g[MAXN][MAXN*2],id[MAXN][MAXN*2],fa[MAXN*MAXN*2],rk[MAXN*MAXN*2];
void Init(int n)
{
    for(int i=0;i<n;i++)
        fa[i]=i,rk[i]=0;
}
int Find(int x)
{
    while(x!=fa[x])x=fa[x];
    return x;
}
stack<pair<int*,int> >stk;
void Union(int x,int y,int on)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    if(rk[x]<=rk[y])
    {
        if(on)stk.push(make_pair(&fa[x],fa[x]));
        fa[x]=y;
        if(rk[x]==rk[y])
        {
            if(on)stk.push(make_pair(&rk[y],rk[y]));
            rk[y]++;
        }
    }
    else
    {
        if(on)stk.push(make_pair(&fa[y],fa[y]));
        fa[y]=x;
    }
}
void Rollback(int on)
{
    while(!stk.empty())
    {
        if(on)*stk.top().first=stk.top().second;
        stk.pop();
    }
}
void Addblock(int x,int y,int r,int c,int on)
{
    for(int j=0;j<8;j++)
    {
        int tx=x+dir[j][0],ty=y+dir[j][1];
        if(ty<1)ty+=2*c;
        if(ty>2*c)ty-=2*c;
        if(tx>=1 && tx<=r && g[tx][ty])
            Union(id[x][y],id[tx][ty],on);
    }
}
int main()
{
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    for(int i=1,t=0;i<=r;i++)
        for(int j=1;j<=2*c;j++)
            id[i][j]=t++;
    Init(r*2*c);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=g[x][y+c]=1;
        Addblock(x,y,r,c,1);
        Addblock(x,y+c,r,c,1);
        if(Find(id[x][y])==Find(id[x][y+c]))
        {
            Rollback(1);
            g[x][y]=g[x][y+c]=0;
        }
        else
        {
            Rollback(0);
            res++;
        }
    }
    printf("%d\n",res);
    return 0;
}