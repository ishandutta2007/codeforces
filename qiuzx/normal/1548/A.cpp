//ANMHLIJKTJIY!
#pragma GCC optimize(2)
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
ll n,m,q,ans;
set<ll> vt[N];
ll calc(ll x)
{
	if(vt[x].empty())
	{
		return 1;
	}
	set<ll>::iterator it=vt[x].end();
	it--;
	if((*it)>x)
	{
		return 0;
	}
	return 1;
}
int main(){
	ll i,x,y,tp;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].insert(y);
		vt[y].insert(x);
	}
	ans=0;
	for(i=0;i<n;i++)
	{
		ans+=calc(i);
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&tp);
		if(tp==1)
		{
			scanf("%lld%lld",&x,&y);
			x--;
			y--;
			ans-=calc(x);
			ans-=calc(y);
			vt[x].insert(y);
			vt[y].insert(x);
			ans+=calc(x);
			ans+=calc(y);
		}
		else if(tp==2)
		{
			scanf("%lld%lld",&x,&y);
			x--;
			y--;
			ans-=calc(x);
			ans-=calc(y);
			vt[x].erase(vt[x].lower_bound(y));
			vt[y].erase(vt[y].lower_bound(x));
			ans+=calc(x);
			ans+=calc(y);
		}
		else
		{
			printf("%lld\n",ans);
		}
	}
	return 0;
}