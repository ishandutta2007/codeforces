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

const ll mod = 998244353;

int main ()
{
	int n, k;
	scanf ("%d %d",&n, &k);
	vector <int> p(n);
	for (int &a: p) scanf ("%d", &a);
	
	ll sum = (ll(n + n - k +1) * ll(k)) / 2LL;
	ll ways = 1LL;
	
	ll len = 1;
	int ile = 0;
	
	for (int a: p)
	{
		if (a>n-k)
		{
			if ((ile++) > 0)
			{
				ways = ways * len % mod;
			}
			len = 1;
		}
		else len++;
	}
	
	printf ("%lld %lld\n", sum, ways);
}