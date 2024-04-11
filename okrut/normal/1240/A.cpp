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



int main ()
{
	int q;
	scanf ("%d", &q);
	rep(t,0,q)
	{
		debug ("\ntest %d\n", t);
		int n;
		scanf ("%d", &n);
		vector <ll> tab(n);
		for (ll &x: tab) scanf ("%lld", &x);
		sort(tab.begin(), tab.end());
		reverse(tab.begin(), tab.end());
		ll x, y, a, b, k;
		scanf ("%lld %lld %lld %lld %lld", &x, &a, &y, &b, &k);
		ll g = (a*b)/__gcd(a,b);
		k*=100LL;
		if (x<y)
		{
			swap(x,y);
			swap(a,b);
		}
		int l = 1, r = n+1;
		while (l<r)
		{
			int mid = (l+r)/2;
			
			int pxy = mid/g;
			int px = mid/a - pxy;
			int py = mid/b - pxy;
			
			ll cost = 0;
			if (mid==n+1) cost = k;
			else
			{
				rep(i,0,pxy) cost+=tab[i]*(x+y);
				rep(i,pxy,pxy+px) cost+=tab[i]*x;
				rep(i,pxy+px,pxy+px+py) cost+=tab[i]*y;
			}
			
			if (cost>=k) r = mid;
			else l = mid+1;
			
			debug ("testuje %d: %d %d %d = %lld\n", mid, pxy, px, py, cost);
		}
		if (l==n+1) printf ("-1\n");
		else printf ("%d\n", l);
	}
}