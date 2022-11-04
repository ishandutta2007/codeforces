#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int fa[MAXN*MAXN],sz[MAXN*MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    sz[fa[y]=x]+=sz[y];
}
ll a[MAXN][MAXN],res[MAXN][MAXN];
struct node
{
    int x,y;
    ll a;
    node(){}
    node(int _x,int _y,ll _a):x(_x),y(_y),a(_a){}
    bool operator < (const node &t)const
    {
        return a>t.a;
    }
}s[MAXN*MAXN];
void bfs(int sx,int sy,int n,int m,ll k,ll t)
{
    queue<int>qx,qy;
    qx.push(sx);
    qy.push(sy);
    res[sx][sy]=t;
    if(!(k-=t))return;
    while(!qx.empty())
    {
        int ux=qx.front();
        int uy=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<4;i++)
        {
            int tx=ux+d[i][0];
            int ty=uy+d[i][1];
            if(tx>=1 && tx<=n && ty>=1 && ty<=m && !res[tx][ty] && a[tx][ty]>=t)
            {
                res[tx][ty]=t;
                if(!(k-=t))return;
                qx.push(tx);
                qy.push(ty);
            }
        }
    }
}
int main()
{
    int n,m;
    ll k;
    scanf("%d%d%I64d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%I64d",&a[i][j]);
            s[(i-1)*m+j]=node(i,j,a[i][j]);
        }
    sort(s+1,s+n*m+1);
    bool isok=0;
    Init(n*m);
    for(int i=1;i<=n*m && !isok;i++)
    {
        int ux=s[i].x;
        int uy=s[i].y;
        for(int j=0;j<4;j++)
        {
            int tx=ux+d[j][0];
            int ty=uy+d[j][1];
            if(tx>=1 && tx<=n && ty>=1 && ty<=m && a[ux][uy]<=a[tx][ty])
                Union((ux-1)*m+uy,(tx-1)*m+ty);
        }
        if(k%s[i].a==0 && sz[Find((ux-1)*m+uy)]>=k/s[i].a)
        {
            isok=1;
            bfs(ux,uy,n,m,k,s[i].a);
        }
    }
    if(isok)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++,printf("\n"))
            for(int j=1;j<=m;j++)
                printf("%I64d ",res[i][j]);
    }
    else printf("NO\n");
    return 0;
}