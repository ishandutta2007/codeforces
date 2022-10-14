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

const int N = 100;
bitset <N> on;

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	vector <ll> small;
	on.set();
	rep(i,2,N) if (on[i])
	{
		small.pb(i);
		int x = i+i;
		while (x<N) 
		{
			on[x] = 0;
			x+=i;
		}
	}
	int n;
	scanf ("%d", &n);
	while (n--) {
		ll p, q, b;
		scanf ("%lld %lld %lld", &p, &q, &b);
		
		ll g = __gcd(p,q);
		q/=g;
		
		for (ll s: small) if (b%s==0LL)
		{
			while (q%s==0LL) q/=s;
		}
		
		while ( (g = __gcd(q,b)) != 1LL) 
		{
			while (q % g == 0LL) q/=g;
		}
		
		if (q==1) printf ("Finite\n");
		else printf ("Infinite\n");
	}
}