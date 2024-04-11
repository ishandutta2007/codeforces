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

const ll mod = 1e9+9;
 
ll pot (ll a, int k)
{
	ll ret = 1;
	a%=mod;
	while (k>0)
	{
		if (k%2==1) ret = ret * a % mod;
		a = a*a % mod;
		k/=2;
	}
	return ret;
}


int main ()
{
	int n, a, b, k;
	scanf ("%d %d %d %d", &n, &a, &b, &k);
	
	ll sk = 0LL;
	
	rep(i,0,k)
	{
		ll s;
		char c;
		scanf (" %c", &c);
		if (c=='+') s = 1;
		else s = -1;
		
		sk += mod + s * (pot(a, n-i) * pot(b, i) % mod);
		sk %=mod;
	}
	sk %= mod;
	
	ll coef = pot(pot(a, mod-2), k) * pot(b, k) % mod;
	
	debug ("pierwsze k: %lld, coef = %lld\n", sk, coef);
	
	ll res = ll( (n+1)/k) * sk % mod;
	if (coef != 1LL)
	{
		res = sk * pot( mod +1LL - coef, mod-2) % mod * ((mod +1LL - pot(coef, (n+1)/k)) % mod) % mod;
	}
	printf ("%lld\n", res % mod);
}