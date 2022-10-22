//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 200011
char s[MAXN],t[MAXN];
ll pre[MAXN],suf[MAXN];
int main()
{
    scanf("%s%s",s+1,t+1);
    ll n=strlen(s+1),m=strlen(t+1);
    ll it=1;
    for(ll i=1;i<=n;++i)
    {
        if(s[i]==t[it])++it;
        pre[i]=it-1;
    }
    it=m;suf[n+1]=m+1;
    for(ll i=n;i;--i)
    {
        if(s[i]==t[it])--it;
        suf[i]=it+1;
    }
    ll l=1,r=1,ans=0;
    while(l<=n)
    {
        while(r<=n&&pre[l-1]>=suf[r+1]-1)++r;
        umax(ans,r-l);
        ++l;
    }
    printf("%lld",ans);
    return 0;
}