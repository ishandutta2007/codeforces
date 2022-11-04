#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],sum[MAXN<<1],mx[MAXN<<1];
inline int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void pushUp(int n,int ls,int rs)
{
    sum[n]=sum[ls]+sum[rs];
    mx[n]=max(mx[ls],mx[rs]);
}
void build(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        sum[n]=mx[n]=a[l];
        return;
    }
    build(l,m);
    build(m+1,r);
    pushUp(n,getId(l,m),getId(m+1,r));
}
ll query(int ql,int qr,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)return sum[n];
    if(qr<=m)return query(ql,qr,l,m);
    if(ql>m)return query(ql,qr,m+1,r);
    return query(ql,m,l,m)+query(m+1,qr,m+1,r);
}
void modulo(int ql,int qr,int &v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(mx[n]<v)return;
    if(l==r)
    {
        sum[n]%=v;
        mx[n]%=v;
        return;
    }
    if(qr<=m)modulo(ql,qr,v,l,m);
    else if(ql>m)modulo(ql,qr,v,m+1,r);
    else
    {
        modulo(ql,m,v,l,m);
        modulo(m+1,qr,v,m+1,r);
    }
    pushUp(n,getId(l,m),getId(m+1,r));
}
void setVal(int &p,int &v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        sum[n]=mx[n]=v;
        return;
    }
    if(p<=m)setVal(p,v,l,m);
    else setVal(p,v,m+1,r);
    pushUp(n,getId(l,m),getId(m+1,r));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    build(1,n);
    while(m--)
    {
        int ty,l,r,k,x;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d%d",&l,&r);
            printf("%I64d\n",query(l,r,1,n));
        }
        else if(ty==2)
        {
            scanf("%d%d%d",&l,&r,&x);
            modulo(l,r,x,1,n);
        }
        else
        {
            scanf("%d%d",&k,&x);
            setVal(k,x,1,n);
        }
    }
    return 0;
}