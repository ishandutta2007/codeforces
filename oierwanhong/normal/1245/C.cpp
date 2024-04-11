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
const ll INF=1ll<<58;
/**********/
#define MAXN 100011
char s[MAXN];
ll f[MAXN];
const ll mod=ll(1e9)+7;
int main()
{
    f[0]=f[1]=1;
    for(ll i=2;i<MAXN;++i)f[i]=(f[i-2]+f[i-1])%mod;
    scanf("%s",s+1);
    ll n=strlen(s+1),ans=1;
    for(ll i=1;i<=n;++i)
    {
        if(s[i]=='u'||s[i]=='n')
        {
            ll j=i;
            while(s[j]==s[i])++j;
            (ans*=f[j-i])%=mod;
            i=j-1;
        }
        else if(s[i]=='m'||s[i]=='w')ans=0;
    }
    printf("%lld",ans);
}