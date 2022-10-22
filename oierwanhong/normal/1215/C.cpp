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
#define MAXN 200011
char s[MAXN],t[MAXN];
std::vector<pll>a;
int main()
{
    ll n=read();scanf("%s%s",s+1,t+1);
    ll p1=0,p2=0;
    for(ll i=1;i<=n;++i)
        if(s[i]!=t[i])
        {
            if(s[i]=='a')
            {
                if(p1)a.push_back(pll(i,p1)),p1=0;
                else p1=i;
            }
            else
            {
                if(p2)a.push_back(pll(i,p2)),p2=0;
                else p2=i;
            }
        }
    if((p1&&p2))
    {
        a.push_back(pll(p2,p2)),a.push_back(pll(p2,p1));
        printf("%u\n",a.size());
        for(auto x:a)printf("%lld %lld\n",x.first,x.second);
    }
    else if(!p1&&!p2)
    {
        printf("%u\n",a.size());
        for(auto x:a)printf("%lld %lld\n",x.first,x.second);
    }
    else puts("-1");
    return 0;
}