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
vector <int> ciag, odwr;
int n, m, q;
vector <vector <int> > nast; //brak skoku
vector <int> best;
vector <int> zer; //najblizsza jedynka
int up (int a, int u)
{
	if (a==m) return m; //nigdy
	if (u<=0) return a; //jestesmy w indeksie a
	int c=1;
	int x=0;
	while (c*2 <=u)
	{
		if (nast[a][x]==m) return m;
		c*=2;
		x++;
	}
	return up (nast[a][x], u - c);
}
int main ()
{
	scanf ("%d %d %d", &n, &m, &q);
	odwr.resize(n+1);
	int a;
	rep(i,0,n) 
	{
		scanf ("%d", &a);
		odwr[a]=i;
	}
	ciag.resize(m);
	best.resize(n, m);
	rep(i,0,m)
	{
		scanf ("%d", &a);
		ciag[i] = odwr[a];
	}
	
	
	
	zer.resize(m, m); //nie ma na prawo
	for (int i=m-1; i>=0; i--)
	{
		if (ciag[i]==0) 
		{
			best[0] = i;
			zer[i] = i;
		}
		else
		{
			best[ciag[i]] = best[(ciag[i]+1)%n];
			
			if (best[ciag[i]]<m)
			{
				zer[i] = best[ciag[i]];
			}
		}
	}
	best.clear();
	best.resize(n, m);
	
	nast.resize(m+1);
	nast[m].pb(m);
	for (int i=m-1; i>=0; i--)
	{
		if (ciag[i]<n-1) //nie jestem ostatni
		{
			nast[i].pb(best[ciag[i]+1]);
		}
		else nast[i].pb(m); //do konca
		
		best[ciag[i]]=i;
	}
	bool f = true;
	int y=0;
	while (f)
	{
		f = false;
		rep(i,0,m+1)
		{
			nast[i].pb(nast[nast[i][y]][y]);
			if (nast[i][y+1]!=m) f = true;
		}
		y++;
	}
	
	
	debug ("po zamianie\n");
	rep(i,0,m) debug ("%d ", ciag[i]);
	debug ("\n");
	
	debug ("zera: ");
	rep(i,0,m) debug ("%d ", zer[i]);
	debug ("\n");
	
	vector <pair <int, int> > dobre;
	int kon;
	rep(i,0,m)
	{
		int z = zer[i];
		if (ciag[i]==0) kon = up(i, n-1);
		else kon = up(zer[i], ciag[i]-1);
		
		debug ("para: %d %d\n", i, kon);
		dobre.pb(mp(i, kon));
	}
	sort(dobre.begin(), dobre.end());
	//reverse(dobre.begin(), dobre.end());
	
	vector <pair <pair <int, int>, int> > ask;
	
	ask.resize(q);
	rep(i,0,q)
	{
		scanf ("%d %d", &ask[i].fi.fi, &ask[i].fi.se);
		ask[i].fi.fi--;
		ask[i].fi.se--;
		ask[i].se=i;
	}
	sort(ask.begin(), ask.end());
	reverse(ask.begin(), ask.end());
	vector <int> res(q, -1);
	int x= (int)dobre.size()-1;
	int mini = 1e6;
	for (auto p: ask)
	{
		while (x>=0 && dobre[x].fi>=p.fi.fi)
		{
			mini = min(mini, dobre[x].se);
			x--;
		}
		//if (x>=0) debug ("ostatnie %d %d\n", dobre[x].fi, dobre[x].se);
		//debug ("query %d %d %d - %d\n", p.fi.fi, p.fi.se, p.se, mini);
		if (p.fi.se >=mini) res[p.se] = 1;
		else res[p.se]=0;
	}
	
	rep(i,0,q) printf ("%d", res[i]);
	printf ("\n");
}