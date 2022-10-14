#pragma GCC optimize "O3"
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

const int T = 1<<21;
const ll inf = 2e18;
const ll alot = 1e12;

pair <ll, ll> Tree[T+T];

void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		Tree[a*2].se += Tree[a].se;
		Tree[a*2+1].se += Tree[a].se;
	}
	Tree[a].fi+=Tree[a].se;
	Tree[a].se = 0;
}
void update (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		Tree[a*2].se+=Tree[a].se;
		Tree[a*2+1].se+=Tree[a].se;
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		Tree[a].fi = min(Tree[a*2].fi, Tree[a*2+1].fi);
		Tree[a].se = 0;
	}
	else up(a, lewy, prawy);
}

void add (int left, int right, ll x, int a=1, int lewy = 0, int prawy = T-1)
{
	if (left<=lewy and right>=prawy) Tree[a].se+=x;
	else
	{
		if (left<=mitte) add(left, right, x, a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a,lewy, prawy); 
}

void ustaw (int x, ll y, int a=1, int lewy=0, int prawy = T-1)
{
	up(a, lewy, prawy);
	if (lewy==prawy) Tree[a].fi = y;
	else
	{
		if (x<=mitte) ustaw(x, y, a*2, lewy, mitte);
		else ustaw(x, y, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}


ll Suf[T][2]; //ile kosztuje optymalne zrobienie sufiksu

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	ll r1, r2, r3, d;
	scanf ("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
	
	vector <ll> A(n);
	for (ll &a: A) scanf ("%lld", &a);
	vector <pair <ll, ll> > cost(n);
	rep(i,0,n)
	{
		cost[i].fi = min(r1 * A[i] + r3, alot);
		cost[i].se = min(r1*(A[i]+1), r2) + r1; //+ pozniejsze dobicie
		
		cost[i].se = min(cost[i].fi, cost[i].se); //koszt, gdybym byl > 1
		
		debug ("For %d: %lld %lld\n", i, cost[i].fi, cost[i].se);
	}
	
	ll base  = d*ll(n-1);
	
	//to jest full
	for (auto c: cost) base += c.fi;
	
	
	ll res = base;
	
	Suf[n-1][1] = cost[n-1].fi;
	Suf[n-1][0] = cost[n-1].fi;
	
	for (int i=n-2; i>=0; i--)
	{
		Suf[i][1] = Suf[i+1][1] + 2*d + cost[i].se;
		Suf[i][0] = min(Suf[i+1][0], Suf[i+1][1]) + d + cost[i].fi;
	}
	
	rep(i,0,T+T) Tree[i].fi  = inf;
	
	/*
	debug ("Sufiksy: \n");
	rep(i,0,n) debug ("%lld %lld\n", Suf[i][0], Suf[i][1]);
	*/
	
	res = min(res, min(Suf[0][0], Suf[0][1]));
	
	
	ustaw(0, cost[0].se + 3LL*d);
	
	ll prv = cost[0].fi;
	
	debug ("For now %lld\n", res);
	
	rep(i,1,n)
	{
		ll best = Tree[1].fi;
		
		assert(best>0);
		
		ll s = min(Suf[i][0] - cost[i].fi, Suf[i][1] - cost[i].se);
		
		ll natrzy = best + s + cost[i].se;
		
		debug ("For %d: %lld+%lld+%lld\n", i, best, s, cost[i].se);
		
		res = min(res, natrzy);
		
		
		ustaw(i, prv + d);
		
		prv = min(prv + d + cost[i].fi, best + cost[i].se);
		
		add(0,i, 3LL*d + cost[i].se);
	}
	
	printf ("%lld\n", res);
	
}