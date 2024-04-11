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

vector <ll> a, g;
int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	ll maks = 0;
	ll bsum=0;
	ll mini = 1e9;
	a.resize(n);
	g.resize(m);
	rep(i,0,n)
	{
		scanf ("%lld", &a[i]);
		maks = max(a[i], maks);
		bsum+=a[i];
	}
	bsum*=ll (m);
	rep(i,0,m)
	{
		scanf ("%lld", &g[i]);
		if (g[i]<maks)
		{
			printf ("-1\n");
			return 0;
		}
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(g.begin(), g.end());
	
	if (g[0]==maks)
	{
		rep(i,0,m) bsum+=g[i] - a[0]; //od najlepszego chlopaka
		printf ("%lld\n", bsum);
		return 0;
	}
	else
	{
		bsum+=g[0] - a[1];
		rep(i,1,m) bsum+=g[i]-a[0];
		printf ("%lld\n", bsum);
	}
	//
}