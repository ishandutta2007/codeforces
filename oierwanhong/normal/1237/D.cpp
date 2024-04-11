//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 300011
struct ST
{
    ll f[19][MAXN],lg[MAXN];
    void build(ll* arr,ll n)
    {
        lg[1]=0;
        for(ll i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
        for(ll i=1;i<=n;++i)f[0][i]=arr[i];
        for(ll i=1;i<=lg[n];++i)
            for(ll j=1;j+(1<<i)-1<=n;++j)
                f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
    }
    ll Query(ll l,ll r)
    {
        ll k=lg[r-l];
        return max(f[k][l],f[k][r-(1<<k)+1]);
    }
}maxv,lb;
ll a[MAXN],f[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=a[n+i]=a[n+n+i]=read();
    maxv.build(a,n+n+n);
    for(ll i=1;i<=n+n+n;++i)
    {
        un l=0,r=i,mid;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(a[i]<(maxv.Query(i-mid+1,i)+1)/2)r=mid-1;
            else l=mid;
        }
        f[i]=i-l+1;
    }
    lb.build(f,n+n+n);
    for(ll i=1;i<=n;++i)
    {
        un l=0,r=n+n+n-i+1,mid;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(lb.Query(i,i+mid-1)>i)r=mid-1;
            else l=mid;
        }
        if(l>n+n)printf("-1 ");
        else printf("%u ",l);
    }
}