#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
std::vector<std::vector<ll> > graph;
std::vector<ll> value;
pair<ll, ll> dfs(ll p, ll u)
{
	ll maxinc = 0;
	ll maxdecr = 0;
	pair<ll, ll> p1;
	for (ll v : graph[u])
	{
		if(v != p)
		{
			p1 = dfs(u, v);
			if(p1.first > maxinc)
				maxinc = p1.first;
			if(p1.second > maxdecr)
				maxdecr = p1.second;
		}
	}
	ll change = maxinc - maxdecr;
	if(value[u]+change > 0)
	{
		maxdecr += (value[u]+change);
	}
	else if(value[u]+change < 0)
	{
		maxinc -= (value[u]+change);
	}
	return mp(maxinc, maxdecr);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n;
	cin >> n;
	ll x, y;
	graph.resize(n);
	value.resize(n);
	for (ll i = 0; i < n-1; ++i)
	{
		cin>>x>>y;
		x--; y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for (ll i = 0; i < n; ++i)
	{
		cin>>value[i];
	}
	pair<ll, ll> p1;
	p1 = dfs(-1, 0);
	cout<<(p1.first+p1.second)<<"\n";
}