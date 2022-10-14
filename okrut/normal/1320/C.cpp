#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf = 1.5e9;

const int T = 1<<20;

ll tree[T+T], lazy[T+T];

void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
	}
	tree[a]+=lazy[a];
	lazy[a] = 0;
}
void update (int a, int lewy, int prawy)
{
	up(a, lewy, prawy);
	if (lewy<prawy)
	{
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		tree[a] = max(tree[a*2], tree[a*2+1]);
	}
}

void add (int left, int right, ll x, int a=1, int lewy=0, int prawy=T-1)
{
	up(a, lewy, prawy);
	if (left<=lewy and right >=prawy) lazy[a] +=x;
	else
	{
		if (left<=mitte) add(left, right, x, a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, m, p;
	scanf ("%d %d %d", &n, &m, &p);
	vector <pair <int, ll> > weap(n);
	vector <pair <int, pair <int, int> > > mon(p);
	for (auto &w: weap) scanf ("%d %lld", &w.fi, &w.se);
	
	ll wcheap = inf, acheap = inf;
	for (auto w: weap) wcheap = min(wcheap, w.se);
	
	rep(i,0,T+T) tree[i] = -inf;
	
	rep(i,0,m)
	{
		int b;
		ll c;
		scanf ("%d %lld", &b, &c);
		acheap = min(acheap, c);
		tree[T+b] = max(tree[T+b], -c);
	}
	
	for (int i=T-1; i>0; i--) tree[i] = max(tree[i*2], tree[i*2+1]);
	
	for (auto &pa: mon) scanf ("%d %d %d", &pa.fi, &pa.se.fi, &pa.se.se);
	
	sort(weap.begin(), weap.end());
	sort(mon.begin(), mon.end());
	auto monster = mon.begin();
	
	ll best = -(wcheap + acheap);
	
	debug ("cheapest: %lld\n", best);
	
	for (auto w: weap)
	{
		for(; monster!=mon.end() and monster->fi < w.fi; monster++)
		{
			debug ("add the monster %d %d %d\n", monster->fi, monster->se.fi, monster->se.se);
			add(monster->se.fi+1, T-1, monster->se.se);
		}
		
		
		ll curr = tree[1] - w.se;
		
		best = max(best, curr);
		
		debug ("With (%d %lld): %lld\n", w.fi, w.se, curr);
	}
	printf ("%lld\n", best);
	
}