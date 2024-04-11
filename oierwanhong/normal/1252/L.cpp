//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
ll prime[200011],cnt[200011],minv[200011],sec[200011], tot=0;
bool vis[200011];
void sieve(ll n)
{
    vis[1]=1;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i])prime[++tot]=i;
        for(ll j=1;j<=tot&&prime[j]*i<=n;++j)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a;
        a*=a;
        p>>=1;
    }
    return res;
}
int main()
{
    sieve(200000);
    for(ll i=1;i<=tot;++i)minv[i]=sec[i]=INF;
    ll n=read();
    for(ll w=1;w<=n;++w)
    {
        ll x=read();
        for(ll i=1;prime[i]*prime[i]<=x;++i)
            if(x%prime[i]==0)
            {
                ++cnt[i];
                ll c=0;
                while(x%prime[i]==0)x/=prime[i],++c;
                if(c<minv[i])sec[i]=minv[i],minv[i]=c;
                else umin(sec[i],c);
            }
        if(x>1)
        {
            ll i=std::lower_bound(prime+1,prime+tot+1,x)-prime;
            ++cnt[i];
            if(1<minv[i])sec[i]=minv[i],minv[i]=1;
            else umin(sec[i],1);
        }
    }
    ll ans=1;
    for(ll i=1;i<=tot;++i)
        if(cnt[i]==n)ans*=Qpow(prime[i],sec[i]);
        else if(cnt[i]==n-1)ans*=Qpow(prime[i],minv[i]);
    printf("%lld",ans);
    return 0;
}