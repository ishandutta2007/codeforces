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
typedef long double ld;

vector <pair <int, int> > tab;
vector <pair <int, int> > res; //oto moj wynik
int main ()
{
	tab.resize(3);
	rep(i,0,3) scanf ("%d %d", &tab[i].fi, &tab[i].se);
	sort(tab.begin(), tab.end());
	pair <int, int> pos=tab[0];
	res.pb(pos);
	while (pos.fi<tab[1].fi)
	{
		pos.fi++;
		res.pb(pos);
	}
	while (pos.se<tab[1].se)
	{
		pos.se++;
		res.pb(pos);
	}
	while (pos.se>tab[1].se)
	{
		pos.se--;
		res.pb(pos);
	}
	//idziemy w gore i w dol
	int dol=min(tab[0].se, tab[1].se);
	int gora=max(tab[0].se, tab[1].se);
	if (tab[2].se<dol)
	{
		pos=mp(tab[1].fi, dol);
		while (pos.se>tab[2].se)
		{
			pos.se--;
			res.pb(pos);
		}
	}
	if (tab[2].se>=dol && tab[2].se<=gora)
	{
		pos=mp(tab[1].fi, tab[2].se);
	}
	if (tab[2].se>gora)
	{
		pos=mp(tab[1].fi, gora);
		while (pos.se<tab[2].se)
		{
			pos.se++;
			res.pb(pos);
		}
	}
	while (pos.fi<tab[2].fi)
	{
		pos.fi++;
		res.pb(pos);
	}
	printf ("%d\n", (int)res.size());
	rep(i,0,(int)res.size()) printf ("%d %d\n", res[i].fi, res[i].se);
}