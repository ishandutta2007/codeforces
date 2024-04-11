#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<50;
#define MAXN 200011
ll a[MAXN],b[MAXN];
int main()
{
    int n=read(),d=read(),m=read(), ca=0,cb=0;
    for(int i=1;i<=n;++i)
    {
        ll x=read();
        if(x<=m)a[++ca]=x;
        else b[++cb]=x;
    }
    std::sort(b+1,b+cb+1),std::reverse(b+1,b+cb+1);
    std::sort(a+1,a+ca+1),std::reverse(a+1,a+ca+1);
    for(int i=1;i<=ca;++i)a[i]+=a[i-1];
    ll ans=a[ca],now=0;
    for(int i=1;i<=cb;++i)
    {
        now+=b[i];
        int t=min(ca,n-((i-1)*(d+1)+1));
        if(t<0)break;
        umax(ans,now+a[t]);
    }
    printf("%lld\n",ans);
    return 0;
}