//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y),t=x;
	x=y,y=t-a/b*y;
	return g;
}
ll n,m,g,ans=0;
vector<ll> v1[N],v2[N];
void solve(ll nl,ll nr,vector<ll> vl,vector<ll> vr)
{
	ll inv,_114514,i;
	exgcd(nr,nl,inv,_114514);
	inv=(inv+nl)%nl;
	vector<pair<ll,pair<ll,ll> > > tmp,nds;
	for(i=0;i<vl.size();i++)
	{
		tmp.push_back(make_pair(((vl[i]/g)*inv)%nl,make_pair(vl[i],1)));
	}
	for(i=0;i<vr.size();i++)
	{
		tmp.push_back(make_pair(((vr[i]/g)*inv)%nl,make_pair(vr[i],0)));
	}
	sort(tmp.begin(),tmp.end());
	for(i=0;i<tmp.size();i++)
	{
		if((!nds.empty())&&tmp[i].F==nds[nds.size()-1].F)
		{
			nds[nds.size()-1].S.F=min(nds[nds.size()-1].S.F,tmp[i].S.F);
			nds[nds.size()-1].S.S|=tmp[i].S.S;
		}
		else
		{
			nds.push_back(tmp[i]);
		}
	}
	for(i=0;i<nds.size();i++)
	{
		ll gp=(nds[(i+1)%nds.size()].F+nl-nds[i].F-1)%nl;
		if(gp==0&&nds[i].S.S==1)
		{
			continue;
		}
		ans=max(ans,nds[i].S.F+nr*g*gp);
	}
	return;
}
int main(){
//	freopen("epidemic.in","r",stdin);
//	freopen("epidemic.out","w",stdout);
	ll i,x,y;
	scanf("%lld%lld",&n,&m);
	g=__gcd(n,m);
	if(g>=N)
	{
		puts("-1");
		return 0;
	}
	scanf("%lld",&x);
	for(i=0;i<x;i++)
	{
		scanf("%lld",&y);
		v1[y%g].push_back(y);
	}
	scanf("%lld",&x);
	while(x--)
	{
		scanf("%lld",&y);
		v2[y%g].push_back(y);
	}
	for(i=0;i<g;i++)
	{
		if(v1[i].empty()&&v2[i].empty())
		{
			puts("-1");
			return 0;
		}
		solve(n/g,m/g,v1[i],v2[i]);
		solve(m/g,n/g,v2[i],v1[i]);
	}
	printf("%lld\n",ans);
	return 0;
}