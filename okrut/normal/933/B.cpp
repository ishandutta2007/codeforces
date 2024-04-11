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

vector <ll> res;

int main ()
{
	ll p, k;
	scanf ("%lld %lld", &p, &k);
	ll znak = 1LL;
	int licz = 0;
	while (p>0)
	{
		ll rest = p%k; //ostatnia szansa, zeby to zrobic
		ll old = p;
		if (znak==1LL) 
		{
			p-=rest;
			res.pb(rest);
		}
		else
		{
			if (rest>0)
			{
				p+=(k-rest);
				res.pb(k-rest);
			}
			else res.pb(0);
		}
		znak*=-1LL;
		p/=k;
		if (old==p)
		{
			if ((licz++)>100)
			{
				printf  ("-1\n");
				return 0;
			}
		}
		else licz = 0;
	}
	printf ("%d\n", (int)res.size());
	for (ll x: res) printf ("%lld ", x);
	printf ("\n");
}