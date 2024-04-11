#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

ll num (ll n, ll pos)
{
	assert(pos < n);
	if (pos%2==0) return pos/2LL + 1LL;
	
	ll m = (pos+1LL) /2LL; //tyle przede mna
	
	ll p = pos+n - m;//skad byl ostatni skok
	
	return n/2LL + num ( (n+1LL)/2LL, p - (n/2LL) * 2LL);
}
int main ()
{
	ll n;
	 int q;
	scanf ("%lld %d", &n, &q);
	ll p;
	rep(i,0,q)
	{
		scanf ("%lld", &p);
		printf ("%lld\n", num(n, p-1LL));
	}
}