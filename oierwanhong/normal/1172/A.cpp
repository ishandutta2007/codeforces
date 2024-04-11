//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 200011
ll a[MAXN],p[MAXN];
int main()
{
    ll n=read(),flag=0,pos1=0;;
    for(ll i=1;i<=n;++i)read();
    for(ll i=1;i<=n;++i)
    {
        a[i]=read();p[a[i]]=i;
        if(a[i]==1)pos1=i;
    }
    for(ll i=pos1+1;i<=n;++i)
        if(a[i]!=i-pos1+1)flag=1;
    for(ll i=1;i<pos1;++i)
        if(a[i]&&a[i]-a[n]<=i)flag=1;
    //printf("flag=%lld\n",flag);
    if(!flag)return printf("%lld",pos1-1),0;
    ll maxv=0;
    for(ll i=1;i<=n;++i)umax(maxv,p[i]-i+1+n);
    printf("%lld",maxv);
    return 0;
}