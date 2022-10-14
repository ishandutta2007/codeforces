#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
vector <set <pair <long long, int> > > wory;
vector <int> nr, tab, res;
vector <vector <pair <int, long long> > > graf;
void dfs (int a, long long d=0)
{
	pair <int, int> best=mp(0,0);
	rep(i,0,(int)graf[a].size())
	{
		dfs(graf[a][i].fi, d+graf[a][i].se);
		if (wory[nr[graf[a][i].fi]].size()>best.fi) best=mp(wory[nr[graf[a][i].fi]].size(), graf[a][i].fi);
	}
	if (best.fi>0) //mamy synow
	{
		set <pair <long long, int> >::iterator it;
		pair <long long, int> p;
		nr[a]=nr[best.se];
		rep(i,0,(int)graf[a].size()) if (graf[a][i].fi!=best.se)
		{
			for (it=wory[nr[graf[a][i].fi]].begin(); it!=wory[nr[graf[a][i].fi]].end(); it++) wory[nr[a]].insert(*it);
		}
		it=wory[nr[a]].begin();
		while ((it!=wory[nr[a]].end()) && (-it->fi>d))
		{
			p=*it;
			it++;
			wory[nr[a]].erase(p);
		}
		res[a]=wory[nr[a]].size();
	}
	else nr[a]=a;
	wory[nr[a]].insert(mp(tab[a]-d, a));
}
int n;
int main ()
{
	scanf ("%d", &n);
	graf.resize(n+1);
	tab.resize(n+1);
	wory.resize(n+1);
	nr.resize(n+1);
	res.resize(n+1, 0);
	rep(i,1,n+1) scanf ("%d", &tab[i]);
	int a, b;
	rep(i,2,n+1)
	{
		scanf ("%d %d", &a, &b);
		graf[a].pb(mp(i,b));
	}
	dfs(1);
	rep(i,1,n+1) printf ("%d ", res[i]);
	printf ("\n");
}