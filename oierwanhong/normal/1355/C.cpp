//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
/**********/
ll f(ll n){return n*(n+1)/2;}
int main()
{
    ll A=read(),B=read(),C=read(),D=read();
    ll ans=0;
    for(ll s=max(C+1,A+B);s<=B+C;++s)
    {
        ll maxx=min(s-B,B),minx=max(s-C,A);
        ans+=(min(D+1,s)-C)*(maxx-minx+1);
    }
    printf("%lld",ans);
    return 0;
}