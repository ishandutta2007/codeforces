#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 50000;
int tab[N][3];
vector <pair <int, int> > res;

int solve (vector <int> &wek, int lvl) //zawsze parzysta liczba
{
	int n = (int)wek.size();
	if (n==0) return -1; //nie mam spadow
	
	vector <pair <int, int> > rob(n);
	rep(i,0,n) rob[i] = mp(tab[wek[i]][lvl], wek[i]);
	
	sort(rob.begin(), rob.end());
	
	debug ("solve (%d): ", lvl);
	for (int y: wek) debug ("%d ", y);
	debug ("\n");
	
	if (lvl==2)
	{
		rep(i,0,n/2) res.pb(mp(rob[i*2].se, rob[i*2+1].se));
		if (n%2==0) return -1;
		return rob.back().se;
	}
	
	vector <int> buffer, curr;
	
	int y = rob[0].fi;
	
	
	for (auto p: rob)
	{
		if (p.fi==y) curr.pb(p.se);
		else
		{	
			int s = solve(curr, lvl+1);
			if (s>=0) buffer.pb(s);
			curr.clear();
			curr.pb(p.se);
			y = p.fi;
		}
	}
	
	
	int s = solve(curr, lvl+1);
	curr.clear();
	
	if (s>=0) buffer.pb(s);
	
	rep(i,0,(int)buffer.size()/2) res.pb(mp(buffer[i*2], buffer[i*2+1]));
	
	if ((int)buffer.size()%2==0) return -1;
	return buffer.back();
}
int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,0,n) rep(j,0,3) scanf ("%d", &tab[i][j]);
	
	vector <int> all(n);
	rep(i,0,n) all[i] = i;
	solve(all, 0);
	
	for (auto p: res) printf ("%d %d\n", p.fi+1, p.se+1);
	
}