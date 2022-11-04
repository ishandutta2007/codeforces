#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=300005;
const ll INF=(1LL<<60)-1;
ll a[MAXN],b[MAXN];
struct func
{
    ll l,m,r;
    func(){}
    func(ll _l,ll _m,ll _r):l(_l),m(_m),r(_r){}
    func operator + (const func &t)const
    {
        return func(max(l,t.l),max(m,t.m),max(r,t.r));
    }
    ll get(ll x)
    {
        return max({-2*x+l,m,2*x+r});
    }
}s[MAXN<<2];
inline void push_up(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}
void update(int p,int l,int r,int n)
{
    if(l==r)
    {
        ll t=fabs(b[l])+fabs(b[l-1]);
        s[n]=func(-b[l]+b[l-1]-t,abs(b[l]+b[l-1])-t,b[l]-b[l-1]-t);
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,l,m,n<<1);
    else update(p,m+1,r,n<<1|1);
    push_up(n);
}
func query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll sum=0;
    for(int i=1;i<n;i++)
        b[i]=a[i]-a[i+1],sum+=abs(b[i]);
    for(int i=2;i<n;i++)
        update(i,2,n-1,1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int ty,l,r;
        ll x;
        scanf("%d%d%d%lld",&ty,&l,&r,&x);
        if(ty==1)
        {
            ll res=-INF;
            if(l==1)res=max(res,sum-abs(b[1])+abs(b[1]+x)),l++;
            if(r==n)res=max(res,sum-abs(b[n-1])+abs(b[n-1]-x)),r--;
            if(l<=r)res=max(res,sum+query(l,r,2,n-1,1).get(x));
            printf("%lld\n",res);
        }
        else
        {
            if(l>1)
            {
                sum-=abs(b[l-1]),b[l-1]-=x,sum+=abs(b[l-1]);
                if(l-1>1)update(l-1,2,n-1,1);update(l,2,n-1,1);
            }
            if(r<n)
            {
                sum-=abs(b[r]),b[r]+=x,sum+=abs(b[r]);
                if(r+1<n)update(r+1,2,n-1,1);update(r,2,n-1,1);
            }
        }
    }
    return 0;
}