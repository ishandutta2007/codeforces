#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=300005;
const int MAXV=1000005;
int a[MAXN],d[MAXV];
int mx[MAXN<<2];
ll sum[MAXN<<2];
void push_up(int n)
{
    mx[n]=max(mx[n<<1],mx[n<<1|1]);
    sum[n]=sum[n<<1]+sum[n<<1|1];
}
void build(int l,int r,int n)
{
    if(l==r)
    {
        mx[n]=sum[n]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}
void update(int ql,int qr,int l,int r,int n)
{
    if(mx[n]<=2)return;
    if(l==r)
    {
        mx[n]=sum[n]=d[mx[n]];
        return;
    }
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,l,m,n<<1);
    else if(ql>m)update(ql,qr,m+1,r,n<<1|1);
    else
    {
        update(ql,m,l,m,n<<1);
        update(m+1,qr,m+1,r,n<<1|1);
    }
    push_up(n);
}
ll query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return sum[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}
int main()
{
    for(int i=1;i<MAXV;i++)
        for(int j=i;j<MAXV;j+=i)
            d[j]++;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int ty,l,r;
        scanf("%d%d%d",&ty,&l,&r);
        if(ty==1)update(l,r,1,n,1);
        else printf("%lld\n",query(l,r,1,n,1));
    }
    return 0;
}