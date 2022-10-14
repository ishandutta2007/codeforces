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


const int N = 1000;
ll tab[N][N], ans[N];
int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,0,n) rep(j,0,n) scanf ("%lld", &tab[i][j]);
	
	ll x = 0;
	rep(i,1,n) x = __gcd(x, tab[0][i]);
	
	ll p = 1;
	vector <ll> dziel;
	while (p*p<=x)
	{
		if (x%p==0)
		{
			dziel.pb(p);
			dziel.pb(x/p);
		}
		p++;
	}
	
	for (ll d: dziel)
	{
		ans[0] = d;
		rep(i,1,n) ans[i] = tab[0][i]/d;
		bool ok = true;
		rep(i,0,n) if (ok) rep(j,i+1,n) if (ans[i] * ans[j] !=tab[i][j])
		{
			ok = false;
			break;
		}
		if (ok) 
		{
			rep(i,0,n) printf ("%lld ", ans[i]);
			printf ("\n");
			break;
		}
	}
}