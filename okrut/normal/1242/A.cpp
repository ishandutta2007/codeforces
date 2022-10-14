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

vector <ll> primes;
const int MIL = (int)1e6+100;
bitset <MIL> rob;
int main ()
{
	rob.set();
	rep(i,2,MIL) if (rob[i])
	{
		primes.pb(i);
		int x = i*2;
		while (x < MIL)
		{
			rob[x] = false;
			x+=i;
		}
	}
	
	ll n;
	scanf ("%lld", &n);
	
	vector <ll> mydiv;
	for (ll x: primes) if (n%x==0) 
	{
		while (n%x==0LL) n/=x;
		mydiv.pb(x);
	}
	if (n>1LL) mydiv.pb(n);
	
	if ((int)mydiv.size()>1)
	{
		printf ("1\n");
		return 0;
	}
	else
	{
		if (mydiv.empty()) printf ("%lld\n", n);
		else printf ("%lld\n", mydiv[0]);
		return 0;
	}
}