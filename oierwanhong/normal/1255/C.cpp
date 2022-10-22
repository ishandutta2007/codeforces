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
const ll INF=1<<28;
/**********/
#define MAXN 200011
std::vector<ll>c[MAXN],a[MAXN],p;
bool vis[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n-2;++i)
    {
        ll x=read(),y=read(),z=read();
        a[i].push_back(x),a[i].push_back(y),a[i].push_back(z);
        c[x].push_back(i),c[y].push_back(i),c[z].push_back(i);
    }
    ll s,pre,cur;
    for(ll i=1;i<=n;++i)
        if(c[i].size()==1u){s=i;break;}
    p.push_back(s);
    for(ll x:a[c[s].front()])
        if(c[x].size()==2)pre=x;
    vis[s]=vis[pre]=1;
    while(p.size()<n-1)
    {
        for(auto g:c[pre])
        {
            ll f1=0,f2=0;
            for(ll x:a[g])
                if(x==p.back())f1=1;
                else if(!vis[x])f2=x;
            if(f1&&f2)
            {
                p.push_back(pre);
                pre=f2,vis[f2]=1;
                break;
            }
        }
    }
    p.push_back(pre);
    for(ll x:p)printf("%lld ",x);
    return 0;
}