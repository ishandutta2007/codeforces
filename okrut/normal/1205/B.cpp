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
const int inf = 1e8;
vector <ll> tab;
const int L = 60;
int ile[L];
int n;



int main ()
{
	scanf ("%d", &n);
	
	rep(i,0,n) 
	{
		ll x;
		scanf ("%lld", &x);
		if (x>0) tab.pb(x);
	}
	n = (int)tab.size();
	
	for (ll x: tab)
	{
		rep(i,0,L) if (x&(1LL<<i)) if ((++ile[i])==3) 
		{
			printf ("3\n");
			return 0;
		}
	}
	//mamy malo wierzcholkow
	
	vector <vector <pair <int, int> > > graf(n);
	vector <pair <int, int> > edge;
	
	rep(i,0,n) rep(j,i+1,n) if ((tab[i]&tab[j])!=0)
	{
		graf[i].pb(mp(j, (int)edge.size()));
		graf[j].pb(mp(i, (int)edge.size()));
		edge.pb(mp(i,j));
	}
	int res = inf;
	rep(i,0,(int)edge.size())
	{
		vector <int> dist(n, inf);
		queue <int> kol;
		kol.push(edge[i].fi);
		dist[edge[i].fi]=1;
		while (!kol.empty())
		{
			int x = kol.front();
			kol.pop();
			for (auto p: graf[x]) if (p.se!=i && dist[p.fi]==inf) 
			{	
				dist[p.fi] = dist[x]+1;
				kol.push(p.fi);
			}
		}
		res = min(res, dist[edge[i].se]);
		
	}
	if (res==inf) printf ("-1\n");
	else printf ("%d\n", res);
}