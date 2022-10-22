//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
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
int main()
{
    ll n=read(),k=read(),ans=0,lim=ll(1e5);
    std::map<ll,ll>p;
    while(n--)
    {
        ll x=read(),cur=1,rest=1;
        for(ll i=2;i*i<=x;++i)
            if(x%i==0)
            {
                ll c=0;
                while(x%i==0)x/=i,++c;
                ll p=c%k;
                while(p)--p,rest*=i;
                p=(c%k?k-c%k:0);
                while(p&&cur<=lim)--p,cur*=i;
            }
        if(x>1)
        {
        	rest*=x;
        	ll p=k-1;
            while(p>0&&cur<=lim)--p,cur*=x;
		}
        if(cur<=lim)ans+=p[cur];
        ++p[rest];
    }
    printf("%lld",ans);
    return 0;
}