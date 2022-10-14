#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
vector <pair <pair <int, int>, int> > tab;
void tabtest (int a, int b)
{
	debug ("siec z %d do %d \n", a, b);
	for (pair <pair <int, int>, int> p: tab) debug ("(%d %d) - %d\n", p.fi.fi, p.fi.se, p.se);
}
namespace flow
{
	pair <int, int> main (int n, int m, vector <pair <pair <int, int>, int> > &tab, int z=1, int u=-1)
	{
		if (u==-1) u=n;
		pair <int, int> p=mp(0,0);
		bool flag=true, f;
		while (flag)
		{
			flag=false; f=true;
			vector <int> dist(n+1, 1e6);
			vector <int> from(n+1,0);
			dist[z]=0;
			rep(j,0,n+1) if (f)
			{
				f=false;
				rep(i,0,m) if (dist[tab[i].fi.fi]<1e6) if (dist[tab[i].fi.se]>dist[tab[i].fi.fi]+tab[i].se)
				{
					f=true;
					dist[tab[i].fi.se]=dist[tab[i].fi.fi]+tab[i].se;
					from[tab[i].fi.se]=i;
				}
			}
			
			if (dist[u]<1e6)
			{
				flag=true;
				p.fi++;
				p.se+=dist[u];
				int x=u;
				while (x!=z)
				{
					tab[from[x]].se*=-1;
					swap(tab[from[x]].fi.fi, tab[from[x]].fi.se);
					x=tab[from[x]].fi.se;
					
				}
			}
			//debug ("wynik to %d\n", p.fi);
		}
		return p;
	}
}

vector <pair <string, int> > cards;
vector <int> num;

int n, m;

int main ()
{
	scanf ("%d %d", &n, &m);
	cards.resize(n);
	num.resize(m);
	rep(i,0,n) cin>>cards[i].fi >>cards[i].se;
	rep(i,0,m) cin>>num[i];
	//zrobmy sobie wszystkie karty
	rep(j,0,m) rep(i,0,n)
	{
		if (cards[i].fi=="ATK") if (num[j]>=cards[i].se)
		{
			tab.pb(mp(mp(i, j+n), cards[i].se));
		}
		if (cards[i].fi=="DEF") if (num[j]>cards[i].se)
		{
			tab.pb(mp(mp(i,j+n), num[j]));
		}
	}
	debug ("wczytano\n");
	rep(j,0,m) tab.pb(mp(mp(j+n, n+m+1), 0));
	rep(i,0,n) tab.pb(mp(mp(m+n, i),0));
	pair <int, int> p=flow::main(m+n+2, (int)tab.size(), tab, m+n,  m+n+1);
	int sum=0;
	int res=0;
	debug ("po pierwszym %d %d\n", p.fi, p.se);
	if (p.fi==n)
	{
		rep(j,0,m) sum+=num[j];
		res=max(res, sum-p.se);
		debug ("wynik za full = %d\n", res);
	}
	
	tab.clear();
	//nie robimy wszystkich kart
	
	int x=0;
	//moze byc za duzo wierzcholkow
	rep(j,0,m) rep(i,0,n) if (cards[i].fi=="ATK") if (cards[i].se<num[j])
	{
		tab.pb(mp(mp(j+n, i), cards[i].se-num[j]));
	}
	rep(i,0,n) if (cards[i].fi=="ATK") tab.pb(mp(mp(i,2*m+n+1), 0));
	rep(j,0,m) 
	{
		tab.pb(mp(mp(2*m+n, j+n), 0));
		tab.pb(mp(mp(j+n, j+n+m), 0));
		tab.pb(mp(mp(j+n+m, 2*m+n+1), 0));
	}
	
	//tabtest(2*m+n, 2*m+n+1);
	
	p=flow::main(m*2+n+2, (int)tab.size(), tab, m*2+n, 2*m+n+1);
	
	res=max(res, -p.se);
	debug ("matching - %d %d\n", p.fi, p.se);
	printf ("%d\n", res);
}