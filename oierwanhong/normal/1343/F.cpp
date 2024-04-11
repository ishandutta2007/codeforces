//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
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
#define MAXN 211
std::set<ll>s[MAXN],p[MAXN];
ll a[MAXN];bool vis[MAXN];
void work()
{
    ll n=read();
    for(ll i=2;i<=n;++i)
    {
    	s[i].clear();
        ll l=read();
        while(l--)s[i].insert(read());
    }
    for(ll x=1;x<=n;++x)
    {
        ll cnt=0,v;
        for(ll i=2;i<=n;++i)
        {
        	vis[i]=0;
            p[i]=s[i];
            if(p[i].count(x))vis[i]=1,p[i].erase(x);
            if(p[i].size()==1)v=*p[i].begin(),++cnt;
        }
        if(cnt>1)continue;
        a[1]=x;
        bool flag=0;
        for(ll pos=2;pos<=n;++pos)
        {
            a[pos]=v;
            cnt=0;
            for(ll i=2;i<=n;++i)
            {
            	if(p[i].count(a[pos]))vis[i]=1,p[i].erase(a[pos]);
            	else if(p[i].size()&&vis[i]){cnt=2;break;}
                if(p[i].size()==1)v=*p[i].begin(),++cnt;
            }
            if(cnt>1){flag=1;break;}
        }
        if(!flag)
        {
            for(ll i=1;i<=n;++i)printf("%lld ",a[i]);
            puts("");
            return;
        }
    }
}
int main()
{
    ll t=read();
    while(t--)work();
}