//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
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
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    ll n=read(),g=n;
    for(ll i=2;i*i<=n;++i)
        if(n%i==0)
        {
            g=gcd(g,i);
            while(n%i==0)n/=i;
        }
    if(n>1)g=gcd(g,n);
    printf("%lld",g);
}