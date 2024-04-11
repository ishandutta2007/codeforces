#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
vector <vector <pair <int, ll> >  > graf;
vector <ll> gas;
int n;
ll maks;
ll dfs (int a,int b=-1) //the maksimal amount of gas i can have
{
	pair <ll, ll> best=mp(0,0);
	vector <ll> tab;
	ll x;
	for (pair <int, ll> s: graf[a]) if (b!=s.fi)
	{
		x=dfs(s.fi, a)-s.se;
		if (best.se<x) best.se=x;
		if (best.fi<best.se) swap(best.fi, best.se);
		tab.pb(x);
	}
	for (ll g: tab)
	{
		if (g==best.fi) maks=max(maks, g+best.se+gas[a]);
		else  maks=max(maks, g+best.fi+gas[a]);
	}
	maks=max(maks, gas[a]);
	return best.fi+gas[a];
}
int main ()
{
	scanf ("%d", &n);
	graf.resize(n+1);
	gas.resize(n+1);
	rep(i,1,n+1) scanf ("%lld", &gas[i]);
	int a, b,c;
	rep(i,1,n)
	{
		scanf ("%d %d %d", &a, &b, &c);
		graf[a].pb(mp(b,c));
		graf[b].pb(mp(a,c));
	}
	maks=0;
	dfs(1);
	printf ("%lld\n", maks);
}