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
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1011
char s[MAXN];
ll a[MAXN],b[MAXN];
int main()
{
    ll n=read(),ans=0;scanf("%s",s+1);
    for(ll i=1;i<=n;++i)a[i]=read(),b[i]=read();
    for(ll i=0;i<=200000;++i)
    {
        ll t=0;
        for(ll j=1;j<=n;++j)
        {
            if(i<b[j])t+=(s[j]=='1');
            else t+=((i-b[j])/a[j]+1+(s[j]-'0'))%2;
        }
        umax(ans,t);
    }
    std::cout<<ans;
}