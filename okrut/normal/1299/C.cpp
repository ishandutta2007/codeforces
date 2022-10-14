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



int main ()
{
	//ios_base::sync_with_stdio(false);
	vector <pair <ld, int> > tab;
	int n;
	scanf ("%d", &n);
	vector <int> input(n);
	for (int &a: input) scanf ("%d", &a);
	
	for (int a: input)
	{
		tab.pb({ld(a), 1});
		
		
		int s = (int)tab.size();
		while (s > 1 && tab[s-2].fi > tab[s-1].fi)
		{
			tab[s-2].fi = (tab[s-2].fi * ld(tab[s-2].se) + tab[s-1].fi * ld(tab[s-1].se)) / (tab[s-2].se + tab[s-1].se);
			tab[s-2].se += tab[s-1].se;
			tab.pop_back();
			s--;
		}
	}
	
	for (auto p: tab)
	{
		rep(i,0,p.se) printf ("%.13Lf\n", p.fi);
	}
}