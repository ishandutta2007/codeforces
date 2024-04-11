#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;



int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	vector <ll> tab(n);
	for (ll &x: tab) scanf ("%lld", &x);
	
	if (n<=3)
	{
		rep(i,0,n)
		{
			printf ("%d %d\n", i+1, i+1);
			printf ("%lld\n", -tab[i]);
		}
		rep(i,n,3) printf ("1 1\n0\n");
		return 0;
	}
	
	
	printf ("1 %d\n", n);
	
	rep(i,0,n-1) 
	{
		printf ("%lld ", -ll(n)*tab[i]);
	}
	printf ("0\n");
	
	printf ("1 %d\n", n-1);
	rep(i,0,n-1)
	{
		printf ("%lld ", ll(n-1)*tab[i]);
	}
	printf ("\n%d %d\n%lld\n", n, n, -tab[n-1]);
	
	
	
}