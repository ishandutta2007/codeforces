//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 1000011
#define MAXK 20
ll f[1<<MAXK];char a[MAXN];
int main()
{
    scanf("%s",a);
    ll n=strlen(a);
    for(ll i=0;i<n;++i)
    {
        ll s=0,c=0;
        for(ll j=i;j<n;++j)
            if(s&(1<<(a[j]-'a')))break;
            else s|=1<<(a[j]-'a'),++c,f[s]=c;
    }
    ll all=(1<<MAXK)-1;
    for(ll s=1;s<=all;++s)
        for(ll x=0;x<MAXK;++x)
            if(s&(1<<x))umax(f[s],f[s^(1<<x)]);
    ll ans=0;
    for(ll i=0;i<n;++i)
    {
        ll s=0,c=0;
        for(ll j=i;j<n;++j)
            if(s&(1<<(a[j]-'a')))break;
            else s|=1<<(a[j]-'a'),++c,umax(ans,c+f[all^s]);
    }
    printf("%lld",ans);
}