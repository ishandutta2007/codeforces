//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
const ll INF=1ll<<28;
/**********/
#define MAXN 200011
ll a[MAXN],b[MAXN];
ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=read(),b[i]=a[i];
    std::sort(b+1,b+n+1);ll len=std::unique(b+1,b+n+1)-b-1;
    if(len==1){puts("0 0");return 0;}
    ll g=b[2]-b[1],maxv=b[len],ans=0;
    for(ll i=3;i<=len;++i)g=gcd(g,b[i]-b[i-1]);
    for(ll i=1;i<=n;++i)ans+=(maxv-a[i])/g;
    printf("%lld %lld",ans,g);
}