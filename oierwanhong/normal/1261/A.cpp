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
#define MAXN 2011
char a[MAXN],b[MAXN];
std::vector<pll>p;
int main()
{
    ll task=read();
    while(task--)
    {
        p.clear();
        ll n=read(),k=read();scanf("%s",a+1);
        ll l=n-2*(k-1);
        for(ll i=1;i<=l/2;++i)b[i]='(';
        for(ll i=l/2+1;i<=l;++i)b[i]=')';
        for(ll i=l+1;i<=n;++i)b[i]=(i&1?'(':')');
        for(ll i=1;i<=n;++i)
            if(a[i]!=b[i])
            {
                ll t;
                for(ll j=i+1;j<=n;++j)
                    if(a[j]==b[i]){t=j;break;}
                p.push_back({i,t});
                std::reverse(a+i,a+t+1);
            }
        std::cout<<p.size()<<'\n';
        for(auto x:p)printf("%lld %lld\n",x.first,x.second);
    }
    return 0;
}