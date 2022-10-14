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


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	vector <ll> V(n), T(n);
	for (ll &v: V) scanf ("%lld", &v);
	for (ll &t: T) scanf ("%lld", &t);
	
	set <pair <ll, int> > wor;
	ll already = 0LL;
	
	rep(i,0,n)
	{
		wor.insert({already + V[i], i});
		
		ll res = 0;
		while (!wor.empty() && wor.begin()->fi <= already + T[i])
		{
			pair <ll, int> p = *wor.begin();
			ll v = p.fi;
			wor.erase(p);
			
			res += v - already;
		}
		
		res += ll(wor.size()) * T[i];
		already += T[i];
		printf ("%lld ", res);
	}
	printf ("\n");
}