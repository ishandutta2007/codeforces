//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
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
#define MAXL 111
ll pw3[MAXL],vis[MAXL];
int main()
{
    ll len=0;
    pw3[0]=1;
    while(pw3[len]<=ll(1e18))pw3[len+1]=pw3[len]*3,++len;
    ll task=read();
    while(task--)
    {
        for(ll i=0;i<=len;++i)vis[i]=0;
        ll n=read();
        for(ll i=len;i>=0;--i)
        {
            ll x=n/pw3[i];
            if(x>=2)
            {
                for(ll j=i+1;j<=len;++j)
                    if(!vis[j]){vis[j]=1;break;}
                    else vis[j]=0;
                break;
            }
            vis[i]=x;
            n%=pw3[i];
        }
        ll ans=0;
        for(ll i=0;i<=len;++i)ans+=vis[i]*pw3[i];
        printf("%lld\n",ans);
    }
}