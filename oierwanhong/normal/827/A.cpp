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
#define MAXN 2000011
char a[MAXN];
int main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    ll n,maxend=0;std::cin>>n;
    for(ll i=1;i<=n;++i)
    {
        str s;ll k;
		std::cin>>s>>k;
        ll len=s.size(),pre=-len;
        while(k--)
        {
        	ll pos;std::cin>>pos;
        	for(ll i=max(0,pre+len-pos);i<len;++i)a[pos+i]=s[i];
        	pre=pos;
		}
    }
    ll all=MAXN-1;
    while(!a[all])--all;
    for(ll i=1;i<=all;++i)putchar(a[i]?a[i]:'a');
    return 0;
}