#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf = 1e10;



int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n; ll k;
		scanf ("%d %lld", &n, &k);
		vector <ll> tab(n);
		
		for (ll &x: tab) scanf ("%lld", &x);
		
		k--;
		ll d = -inf;
		for (ll x: tab) d = max(d, x);
		for (ll &x: tab) x = d-x;
		
		ll l = inf, r = -inf;
		
		for (ll x: tab)
		{
			l = min(l, x);
			r = max(r, x);
		}
		
		//w dwoch krokach odejmuje minimum
		
		if (k>=2)
		{
			for (ll &x: tab) x-=l;
			k-=2;
		}
		
		if (k&1)
		{
			d = -inf;
			for (ll x: tab) d = max(d, x);
			for (ll &x: tab) x = d-x;
		}
		
		for (ll x: tab) printf ("%lld ", x);
		printf ("\n");
	}
	
}