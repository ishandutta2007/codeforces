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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXK 20
ll g[MAXK][MAXK],f[1<<MAXK];
std::vector<ll>a[MAXK];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[read()-1].push_back(i);
    for(ll i=0;i<MAXK;++i)
        for(ll j=0;j<MAXK;++j)
        {
            if(i==j)continue;
            ll it=0;
            for(auto x:a[i])
            {
                while(it<a[j].size()&&a[j][it]<x)++it;
                g[i][j]+=it;
            }
        }
    ll all=(1<<20)-1;
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(ll s=0;s<=all;++s)
        for(ll i=0;i<MAXK;++i)
            if(!(s&1<<i))
            {
                ll cur=0;
                for(ll j=0;j<MAXK;++j)
                    if(s&1<<j)cur+=g[j][i];
                umin(f[s|(1<<i)],f[s]+cur);
            }
    printf("%lld",f[all]);
    return 0;
}