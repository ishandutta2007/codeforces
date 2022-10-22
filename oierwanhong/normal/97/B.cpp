#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
#define MAXN 200011
pll a[MAXN],tmp[MAXN];
std::set<pll>s;
ll n;
void solve(ll l,ll r)
{
	if(l==r)return;
	ll mid=(l+r)>>1,split_line=a[mid+1].first;
	solve(l,mid),solve(mid+1,r);
	for(ll i=l;i<=r;++i)s.insert(pll(split_line,a[i].second));
}
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i].first=read(),a[i].second=read(),s.insert(a[i]);
	std::sort(a+1,a+n+1);
	solve(1,n);
	std::cout<<s.size()<<'\n';
	for(auto x:s)printf("%lld %lld\n",x.first,x.second );
	return 0;
}