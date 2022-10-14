#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3000;

vector <vector <pair <ll, ll> > > tab;
vector <ll> h;
int n;
int main ()
{
	scanf ("%d", &n);
	tab.resize(n);
	h.resize(n);
	rep(i,0,n) scanf ("%lld", &h[i]);
	rep(a,0,n) rep(b,0,n)
	{
		tab[a].pb(mp(h[b] + ll(a-b), -1));
	}
	rep(i,0,n) sort(tab[i].begin(), tab[i].end());
	
	for (pair <ll, ll> &p: tab[0]) p.se = abs( h[0] - p.fi);
	ll mini;
	rep(i,1,n)
	{
		debug ("rob %d (%lld)\n", i, h[i]);
		mini=1e18;
		int q = 0;
		for (pair <ll, ll> &p: tab[i])
		{
			while (q < tab[i-1].size() && tab[i-1][q].fi<p.fi) 
			{
				mini = min(mini, tab[i-1][q].se);
				q++;
			}
			
			debug("option for %lld : %lld + %lld \n", p.fi, mini, abs(h[i] - p.fi));
			p.se = mini + abs(h[i] - p.fi);
		}
	}
	
	mini = 1e18;
	
	for (pair <ll, ll> p: tab[n-1]) mini = min(mini, p.se);
	
	printf ("%lld\n", mini);
}