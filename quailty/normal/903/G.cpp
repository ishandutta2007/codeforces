#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int x[MAXN],y[MAXN];
struct Edge
{
    int s,t,w;
    bool operator < (const Edge &rhs)const
    {
        return s<rhs.s;
    }
}e[MAXN];
ll buf[MAXN],val[MAXN<<2],lz[MAXN<<2];
void push_up(int n)
{
    val[n]=min(val[n<<1],val[n<<1|1]);
}
void push_down(int n)
{
    if(!lz[n])return;
    val[n<<1]+=lz[n];
    val[n<<1|1]+=lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}
void build(int l,int r,int n)
{
    lz[n]=0;
    if(l==r)
    {
        val[n]=buf[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}
void update(int ql,int qr,ll v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        val[n]+=v;
        lz[n]+=v;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
    push_up(n);
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n-1;i++)
        scanf("%d%d",&x[i],&y[i]),buf[i]=y[i];
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].w);
    sort(e+1,e+m+1);
    build(0,n-1,1);
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=m && e[j].s<=i)
            update(0,e[j].t-1,e[j].w,0,n-1,1),j++;
        buf[i]=x[i]+val[1];
    }
    build(1,n,1);
    printf("%lld\n",val[1]);
    while(q--)
    {
        int v,w;
        scanf("%d%d",&v,&w);
        update(v,v,w-x[v],1,n,1),x[v]=w;
        printf("%lld\n",val[1]);
    }
    return 0;
}