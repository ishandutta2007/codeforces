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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,d;
vector<pair<ll,ll> > vt;
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	if(max(x.F,x.S)!=max(y.F,y.S))
	{
		return (max(x.F,x.S)<max(y.F,y.S));
	}
	return (min(x.F,x.S)<min(y.F,y.S));
}
int main(){
	ll i,x,y,ans=0;
	n=rint(),d=rint();
	for(i=0;i<n;i++)
	{
		x=rint(),y=rint();
		vt.push_back(make_pair(x,y));
	}
	sort(vt.begin(),vt.end(),cmp);
	for(i=0;i<n;i++)
	{
		if(vt[i].F>=d)
		{
			ans++;
			d=max(d,vt[i].S);
		}
	}
	printf("%lld\n",ans);
	return 0;
}