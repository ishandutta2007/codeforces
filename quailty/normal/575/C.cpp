#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25;
const int INF=0x3f3f3f3f;
int g[2][MAXN][MAXN],c[MAXN];
int lx[MAXN],ly[MAXN],match[MAXN],pre[MAXN],visy[MAXN],slack[MAXN];
int tlx[MAXN][MAXN],tly[MAXN][MAXN],tmatch[MAXN][MAXN];
void augment(int root,int n)
{
    memset(visy,0,sizeof(visy));
    memset(slack,INF,sizeof(slack));
    int py;
    match[py=n]=root;
    do
    {
        visy[py]=1;
        int x=match[py],delta=INF,yy=n;
        for(int y=0;y<n;y++)if(!visy[y])
        {
            int tmp=lx[x]+ly[y]-g[c[x]][x][y];
            if(tmp<slack[y])
            {
                slack[y]=tmp;
                pre[y]=py;
            }
            if(slack[y]<delta)
            {
                delta=slack[y];
                yy=y;
            }
        }
        for(int y=0;y<=n;y++)
        {
            if(visy[y])
            {
                lx[match[y]]-=delta;
                ly[y]+=delta;
            }
            else slack[y]-=delta;
        }
        py=yy;
    }while(match[py]!=-1);
    do
    {
        int p=pre[py];
        match[py]=match[p];
        py=p;
    }while(py!=n);
}
void solve(int x,int n,int tot,int &res)
{
    if(x==n)
    {
        if(tot==n/2)
        {
            int now=0;
            for(int i=0;i<n;i++)
                now+=lx[i],now+=ly[i];
            res=max(res,now);
        }
        return;
    }
    memcpy(tlx[x],lx,sizeof(lx));
    memcpy(tly[x],ly,sizeof(ly));
    memcpy(tmatch[x],match,sizeof(match));
    for(int _=0;_<2;_++)
    {
        if(tot+_>n/2)continue;
        if(n-1-x+tot+_<n/2)continue;
        c[x]=_;
        for(int j=0;j<n;j++)
            lx[x]=max(lx[x],g[c[x]][x][j]);
        augment(x,n);
        solve(x+1,n,tot+_,res);
        memcpy(lx,tlx[x],sizeof(tlx[x]));
        memcpy(ly,tly[x],sizeof(tly[x]));
        memcpy(match,tmatch[x],sizeof(tmatch[x]));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int _=0;_<2;_++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&g[_][i][j]);
    memset(match,-1,sizeof(match));
    int res=0;
    solve(0,n,0,res);
    printf("%d\n",res);
    return 0;
}