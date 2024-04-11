#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int b[MAXN],dp[17][MAXN],lg[MAXN];
void rmq_init(int n)
{
    lg[0]=-1;
    for(int i=1;i<=n;i++)
        dp[0][i]=b[i],lg[i]=lg[i-1]+((i&(i-1))==0);
    for(int i=1;i<=lg[n];i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
}
int rmq_query(int l,int r)
{
    int k=lg[r-l+1];
    return min(dp[k][l],dp[k][r-(1<<k)+1]);
}
int val[MAXN<<7],lz[MAXN<<7],ls[MAXN<<7],rs[MAXN<<7],tot;
int cal_empty(int l,int r,int n)
{
    int bl=(l-1)/n+1,br=(r-1)/n+1;
    int cl=(l-1)%n+1,cr=(r-1)%n+1;
    if(bl==br)return rmq_query(cl,cr);
    if(bl+1<br)return rmq_query(1,n);
    return min(rmq_query(cl,n),rmq_query(1,cr));
}
void push_up(int n)
{
    val[n]=min(val[ls[n]],val[rs[n]]);
}
void push_down(int n)
{
    if(lz[n]==INF)return;
    val[ls[n]]=val[rs[n]]=lz[n];
    lz[ls[n]]=lz[rs[n]]=lz[n];
    lz[n]=INF;
}
void update(int ql,int qr,int v,int l,int r,int p,int &n)
{
    if(ql==l && qr==r)
    {
        val[n]=v;
        lz[n]=v;
        return;
    }
    int m=(l+r)/2;
    if(!ls[n])
    {
        ls[n]=++tot;
        val[ls[n]]=cal_empty(l,m,p);
        lz[ls[n]]=INF;
    }
    if(!rs[n])
    {
        rs[n]=++tot;
        val[rs[n]]=cal_empty(m+1,r,p);
        lz[rs[n]]=INF;
    }
    push_down(n);
    if(qr<=m)update(ql,qr,v,l,m,p,ls[n]);
    else if(ql>m)update(ql,qr,v,m+1,r,p,rs[n]);
    else
    {
        update(ql,m,v,l,m,p,ls[n]);
        update(m+1,qr,v,m+1,r,p,rs[n]);
    }
    push_up(n);
}
int query(int ql,int qr,int l,int r,int p,int n)
{
    if(ql==l && qr==r)return val[n];
    int m=(l+r)/2;
    if(!ls[n])
    {
        ls[n]=++tot;
        val[ls[n]]=cal_empty(l,m,p);
        lz[ls[n]]=INF;
    }
    if(!rs[n])
    {
        rs[n]=++tot;
        val[rs[n]]=cal_empty(m+1,r,p);
        lz[rs[n]]=INF;
    }
    push_down(n);
    if(qr<=m)return query(ql,qr,l,m,p,ls[n]);
    if(ql>m)return query(ql,qr,m+1,r,p,rs[n]);
    return min(query(ql,m,l,m,p,ls[n]),query(m+1,qr,m+1,r,p,rs[n]));
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    rmq_init(n);
    int q,rt=++tot;
    val[rt]=rmq_query(1,n);
    lz[rt]=INF;
    scanf("%d",&q);
    while(q--)
    {
        int ty,l,r;
        scanf("%d%d%d",&ty,&l,&r);
        if(ty==1)
        {
            int x;
            scanf("%d",&x);
            update(l,r,x,1,n*k,n,rt);
        }
        else printf("%d\n",query(l,r,1,n*k,n,rt));
    }
    return 0;
}