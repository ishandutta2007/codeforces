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


int main ()
{
	int t;
	scanf ("%d", &t);
	rep(i,0,t)
	{
		ll x;
		scanf ("%lld", &x);
		if (x < 14LL) 
		{
			printf ("NO\n");
			continue;
		}
		ll y = x%14LL;
		if (y>0 && y<7) printf ("YES\n");
		else printf ("NO\n"); 
	}
}