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
 
const int T = 1<<19;
const ll inf = 1e17;
 
vector <pair <int, ll> > graf[T];
ll tree[T+T], lazy[T+T];
int kon[T];
 
int dfs (int a, ll d=0) 
{
	int ret = a;
	for (pair <int, ll> p: graf[a]) ret = max(ret, dfs (p.fi, d+p.se));
	
	if ((int)graf[a].size()==0) tree[a+T] = d;
	
	kon[a] = ret;
	return ret;
}
void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
	}
	tree[a]+=lazy[a];
	lazy[a] = 0LL;
}
void update (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		lazy[a] = 0;
		tree[a] = min(tree[a*2], tree[a*2+1]);
	}
	else up(a, lewy, prawy);
}
void add (int left, int right, ll x,  int a=1, int lewy=0, int prawy = T-1)
{
	if (left>right) return; //pusty przedzial
	
	update(a, lewy, prawy);
	if (left<=lewy && right>=prawy) lazy[a]+=x;
	else
	{
		if (left<=mitte) add(left, right, x, a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}
ll mini (int left, int right, int a=1, int lewy=0, int prawy = T-1)
{
	update(a, lewy, prawy);
	if (left<=lewy && right>=prawy) return tree[a];
	else
	{
		ll ret = inf;
		if (left<=mitte) ret = min(ret, mini(left, right, a*2, lewy, mitte));
		if (right>mitte) ret = min(ret, mini(left, right, a*2+1, mitte+1, prawy));
		return ret;
	}
}
vector <pair <int, pair <int, int> > > query[T];
ll ans[T];

void traw (int a, ll d = 0LL) //dodatek dla wszystkich
{
	for (auto q: query[a])
	{
		ans[q.fi] = d+mini(q.se.fi, q.se.se);
	}
	
	for (pair <int, ll> p: graf[a])
	{
		add(p.fi, kon[p.fi], - (2LL* p.se));
		traw(p.fi, d+p.se);
		add(p.fi, kon[p.fi], 2LL * p.se);
	}
}

int main ()
{
	int n, q;
	rep(i,0,T+T) tree[i] = inf;
	scanf ("%d %d", &n, &q);
	int p; ll w;
	rep(i,2,n+1)
	{
		scanf ("%d %lld", &p, &w);
		graf[p].pb(mp(i, w));
	}
	dfs(1);
	for (int a=T-1; a>0; a--) tree[a] = min(tree[a*2], tree[a*2+1]);
	
	rep(i,0,q)
	{
		int v, l, r;
		scanf ("%d %d %d", &v, &l, &r);
		query[v].pb(mp(i, mp(l, r)));
	}
	
	traw(1);
	rep(i,0,q) printf ("%lld\n", ans[i]);
}