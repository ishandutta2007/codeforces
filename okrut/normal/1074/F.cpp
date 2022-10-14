#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
vector <vector <int> > graf, desc;
vector <pair <int, int> > dzial;
vector <vector <pair <int, int> > > syny;
int n, m;
set <pair <int, int> > wor; //zdana z krawedzi nie moze go psuc
struct baum
{
	vector <pair <int, int> > tree;
	vector <int> chan;
	void maketree(int a=1, int lewy=0, int prawy=n-1)
	{
		if (a==1) 
		{
			tree.resize(n*2+10, mp(0,0));
			chan.resize(n*2+10, 0);
		}
		while (tree.size()<=a)
		{
			tree.pb(mp(0,0));
			chan.pb(0);
		}
		tree[a].se=prawy-lewy+1;
		if (lewy<prawy)
		{
			maketree(a*2, lewy, mitte);
			maketree(a*2+1, mitte+1, prawy);
		}
	}
	int ile ()
	{
		if (tree[1].fi<(int)wor.size()) return 0;
		return tree[1].se;
	}
	void up (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			chan[a*2]+=chan[a];
			chan[a*2+1]+=chan[a];
		}
		tree[a].fi+=chan[a];
		chan[a]=0;
	}
	void update (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			chan[a*2]+=chan[a];
			chan[a*2+1]+=chan[a];
			up(a*2, lewy, mitte);
			up(a*2+1, mitte+1, prawy);
			tree[a].fi=max(tree[a*2].fi, tree[a*2+1].fi);
			tree[a].se=0;
			if (tree[a].fi==tree[a*2].fi) tree[a].se+=tree[a*2].se;
			if (tree[a].fi==tree[a*2+1].fi) tree[a].se+=tree[a*2+1].se;
		}
		else
		{
			tree[a].fi+=chan[a];
		}
		chan[a]=0;
	}
	void mark (int left, int right, int x, int a=1, int lewy=0, int prawy=n-1)
	{
		update(a,lewy, prawy);
		if (left<=lewy && right>=prawy) chan[a]+=x;
		else
		{
			if (left<=mitte) mark(left, right, x, a*2, lewy, mitte);
			if (right>mitte) mark(left, right, x, a*2+1, mitte+1, prawy);
		}
		update(a,lewy,prawy);
	}
	void check (int a=1, int lewy=0, int prawy=n-1)
	{
		debug ("%d [%d %d] - %d %d +%d\n", a, lewy, prawy, tree[a].se, tree[a].fi, chan[a]);
		if (lewy<prawy)
		{
			check (a*2, lewy, mitte);
			check(a*2+1, mitte+1, prawy);
		}
	}
};
baum tree;
int t;
void dfs0 (int a, int b=-1)
{
	dzial[a].fi=t;
	t++;
	for (int s: graf[a]) if (s!=b) 
	{
		dfs0(s,a);
		syny[a].pb(dzial[s]);
		desc[a].pb(s);
	}
	dzial[a].se=t-1;
}
bool syn (int a, int b) //czy a jest synem b
{
	return (dzial[b].fi<dzial[a].fi && dzial[a].se<=dzial[b].se);
}
int brat (int a, int b) //syn a - umiesc b
{
	int lewy=0, prawy=syny[a].size()-1;
	while (lewy<prawy)
	{
		if (syny[a][mitte+1].fi>b) prawy=mitte;
		else lewy=mitte+1;
	}
	return desc[a][lewy];
}
int main ()
{
	t=0;
	int q, a, b;
	pair <int, int> p;
	scanf ("%d %d", &n, &q);
	tree.maketree();
	graf.resize(n+1);
	desc.resize(n+1);
	syny.resize(n+1);
	dzial.resize(n+1);
	rep(i,1,n)
	{
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs0(1);
	rep(i,0,q)
	{
		scanf ("%d %d", &p.fi, &p.se);
		if (p.se<p.fi) swap(p.fi,p.se);
		if (wor.count(p)==0) 
		{
			a=1;
			wor.insert(p);
		}
		else
		{
			a=-1;
			wor.erase(p);
		}
		if (syn(p.fi, p.se))
		{
			//if (n==150000) if (i+1==4350) printf ("syn_(%d_%d)_ojcec(%d_%d)\n", dzial[p.fi].fi, dzial[p.fi].se, dzial[p.se].fi, dzial[p.se].se);
			tree.mark(0,n-1,a);
			b=brat(p.se, dzial[p.fi].fi);
			debug ("ojciec %d, syn %d - brat %d\n", p.se, p.fi, b);
			tree.mark(dzial[b].fi, dzial[b].se,-a);
			tree.mark(dzial[p.fi].fi, dzial[p.fi].se,a);
		}
		else if (syn(p.se, p.fi))
		{
			//if (n==150000) if (i+1==4350) printf ("syn_(%d_%d)_ojcec(%d_%d)\n", dzial[p.se].fi, dzial[p.se].se, dzial[p.fi].fi, dzial[p.fi].fi);
			tree.mark(0,n-1,a);
			b=brat(p.fi, dzial[p.se].fi);
			debug ("ojciec %d, syn %d - brat %d\n", p.fi, p.se, b);
			tree.mark(dzial[b].fi, dzial[b].se,-a);
			tree.mark(dzial[p.se].fi, dzial[p.se].se, a);
		}
		else
		{
			//if (n==150000) if (i+1==4350) printf ("jednak_poddrzewa\n");
			debug ("dwa sobne podrzewa+: [%d %d] oraz [%d %d]\n", dzial[p.fi].fi, dzial[p.fi].se, dzial[p.se].fi, dzial[p.se].se);
			tree.mark(dzial[p.fi].fi, dzial[p.fi].se, a);
			tree.mark(dzial[p.se].fi, dzial[p.se].se,a);
		}
	//	tree.check();
		printf ("%d\n", tree.ile());
	}
}