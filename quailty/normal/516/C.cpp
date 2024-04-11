#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
struct Data
{
    ll mx1,mx2,res;
    Data(){}
    Data(ll _mx1,ll _mx2,ll _res):mx1(_mx1),mx2(_mx2),res(_res){}
    Data operator + (const Data& rhs)const
    {
        return Data(max(mx1,rhs.mx1),max(mx2,rhs.mx2),max({res,rhs.res,mx1+rhs.mx2}));
    }
};
ll d[MAXN],h[MAXN];
Data s[MAXN<<2];
void build(int l,int r,int n)
{
    if(l==r)
    {
        s[n]=Data(2*h[l]-d[l-1],2*h[l]+d[l-1],-INF);
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    s[n]=s[n<<1]+s[n<<1|1];
}
Data query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&d[i]),d[i+n]=d[i];
    for(int i=1;i<=2*n;i++)
        d[i]+=d[i-1];
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]),h[i+n]=h[i];
    build(1,2*n,1);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",query(b+1,a+(a<=b)*n-1,1,2*n,1).res);
    }
    return 0;
}