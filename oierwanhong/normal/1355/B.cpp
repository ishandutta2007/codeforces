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
#define MAXN 200011
ll cnt[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),cur=0,ans=0;
        for(ll i=1;i<=n;++i)cnt[i]=0;
        for(ll i=1;i<=n;++i)++cnt[read()];
        for(ll i=1;i<=n;++i)
        {
            cur+=cnt[i];
            while(cur>=i)++ans,cur-=i;
        }
        printf("%lld\n",ans);
    }
}