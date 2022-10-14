#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
int n;
typedef long long ll;
typedef pair <pair <ll, ll> , ll > para;
struct baum
{
	vector <pair <ll, ll> > tree; //moje fukncje z i x
	vector <ll> arg; //argumenty
	ll wart (int x, int a=1, int lewy=0, int prawy=n-1)
	{	
		debug ("czytaj (%d): %d [%d %d] - %lld %lld\n", x, a, lewy, prawy, tree[a].fi, tree[a].se);
		
		if (tree[a].fi!=-1) return max(0LL,tree[a].fi-arg[x]*tree[a].se);
		if (lewy<prawy)
		{
			if (x<=mitte) return wart(x,a*2,lewy,mitte);
			else return wart(x,a*2+1,mitte+1, prawy);
		}
		return 0;
	}
	void pro (int a, int lewy, int prawy)
	{
		if (tree[a].fi!=-1)
		{
			tree[a*2]=tree[a];
			tree[a*2+1]=tree[a];
		}
		tree[a]=mp(-1,-1);
	}
	void mark (int g, ll z, ll x, int a=1, int lewy=0, int prawy=n-1)
	{
		if (lewy<prawy) pro(a,lewy,prawy);
		if (lewy>=g) tree[a]=mp(z,x);
		else if (lewy<prawy)
		{
			if (g<=mitte) mark(g,z,x,a*2,lewy,mitte);
			mark(g,z,x,a*2+1,mitte+1, prawy);
		}
		
	}
	void init (vector <para> &tab)
	{
		arg.resize(n);
		rep(i,0,n) arg[i]=tab[i].fi.se;
		tree.resize(n*4+20,mp(-1,-1));
	}
};
baum tree;
vector <para> tab;
vector <ll> kara;
ll f (ll z, ll x, int g)
{
	return z-x*tab[g].fi.se;
}
int binsuche (ll z, ll x, int lewy=0, int prawy=n-1) //pierwszy indeks, gdzie moja nowa funkcja przewaza
{
	while (lewy<prawy)
	{
		if (tree.wart(mitte)<f(z,x,mitte)) prawy=mitte;
		else lewy=mitte+1;
	}
	if (tree.wart(mitte)<f(z,x,mitte)) return lewy;
	return n; //nie przewaza w zakresie
}
int main ()
{
	scanf ("%d", &n);
	kara.resize(n);
	tab.resize(n);
	rep(i,0,n) scanf ("%lld %lld %lld", &tab[i].fi.fi, &tab[i].fi.se, &tab[i].se);
	sort(tab.begin(), tab.end());
	tree.init(tab);
	ll maks=0;
	ll res=0;
	int g;
	ll p;
	rep(i,0,n)
	{
		p=tree.wart(i);
		debug ("licze %d: i pramia %lld\n", i, p);
		res=p+tab[i].fi.fi*tab[i].fi.se-tab[i].se;
		maks=max(maks, res);
		g=binsuche(res,tab[i].fi.fi);
		tree.mark(g, res, tab[i].fi.fi);
		
		debug ("for %d f: %lld %lld (from %d)\n", i, res, tab[i].fi.fi, g);
	}
	printf ("%lld\n", maks);
}