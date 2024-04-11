//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 100011
std::priority_queue<ll,std::vector<ll>,std::greater<ll> >want;
std::queue<ll>wait;
std::set<ll>s;
pll a[MAXN];
ll ans[MAXN];
int main()
{
    ll n=read(),p=read(),now=0;
    for(ll i=1;i<=n;++i)a[i].first=read(),a[i].second=i;
    std::sort(a+1,a+n+1);
    s.insert(n+1);
    ll i=1;
    while(i<=n||!wait.empty()||!want.empty())
    {
    	if(!wait.empty())
    	{
    		now+=p,ans[wait.front()]=now;
    		while(i<=n&&a[i].first<now)
    		{
    			if(a[i].second<=*s.begin())wait.push(a[i].second),s.insert(a[i].second);
    			else want.push(a[i].second);
    			++i;
			}
			s.erase(wait.front()),wait.pop();
		}
		if(wait.empty()&&want.empty())umax(now,a[i].first);
		while(i<=n&&a[i].first<=now)want.push(a[i].second),++i;
		if(!want.empty()&&want.top()<*s.begin())
		{
			wait.push(want.top()),s.insert(want.top());
			want.pop();
		}
	}
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}