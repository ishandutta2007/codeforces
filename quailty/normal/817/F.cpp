#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll t[MAXN],l[MAXN],r[MAXN],x[MAXN<<2];
int v[MAXN<<4],lz[MAXN<<4];
void push_up(int n)
{
    v[n]=v[n<<1]+v[n<<1|1];
}
void push_down(int l,int r,int n)
{
    if(lz[n]<0)return;
    int m=(l+r)/2;
    if(lz[n]<2)
    {
        v[n<<1]=lz[n]*(m-l+1);
        v[n<<1|1]=lz[n]*(r-m);
        lz[n<<1]=lz[n];
        lz[n<<1|1]=lz[n];
    }
    else
    {
        v[n<<1]=(m-l+1)-v[n<<1];
        v[n<<1|1]=(r-m)-v[n<<1|1];
        lz[n<<1]=1-lz[n<<1];
        lz[n<<1|1]=1-lz[n<<1|1];
    }
    lz[n]=-1;
}
void update(int ql,int qr,int op,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        if(op<2)
        {
            v[n]=(1-op)*(r-l+1);
            lz[n]=1-op;
        }
        else
        {
            v[n]=(r-l+1)-v[n];
            lz[n]=1-lz[n];
        }
        return;
    }
    push_down(l,r,n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,op,l,m,n<<1);
    else if(ql>m)update(ql,qr,op,m+1,r,n<<1|1);
    else
    {
        update(ql,m,op,l,m,n<<1);
        update(m+1,qr,op,m+1,r,n<<1|1);
    }
    push_up(n);
}
int query(int l,int r,int n)
{
    if(l==r)return l;
    push_down(l,r,n);
    int m=(l+r)/2;
    if(v[n<<1]<m-l+1)return query(l,m,n<<1);
    else return query(m+1,r,n<<1|1);
}
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    x[++cnt]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&t[i],&l[i],&r[i]);
        x[++cnt]=l[i],x[++cnt]=r[i],x[++cnt]=r[i]+1;
    }
    sort(x+1,x+cnt+1);
    cnt=unique(x+1,x+cnt+1)-(x+1);
    for(int i=1;i<=n;i++)
    {
        int tl=lower_bound(x+1,x+cnt+1,l[i])-x;
        int tr=lower_bound(x+1,x+cnt+1,r[i])-x;
        update(tl,tr,t[i]-1,1,cnt,1);
        printf("%lld\n",x[query(1,cnt,1)]);
    }
    return 0;
}