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

vector <int> ojce, sum;



int main ()
{
	int n;
	scanf ("%d", &n);
	vector <pair <ll, ll> > tab(n);
	rep(i,0,n) scanf ("%lld", &tab[i].fi);
	rep(i,0,n) scanf ("%lld", &tab[i].se);
	
	sort(tab.begin(), tab.end());
	reverse(tab.begin(), tab.end());
	vector <bool> ok(n, false);
	
	ll sum = 0;
	
	rep(i,0,n-1) if (tab[i].fi==tab[i+1].fi) ok[i] = true;
	rep(i,0,n) if (ok[i])
	{
		sum+=tab[i].se;
		rep(j,i+1,n) if ((tab[j].fi|tab[i].fi)==tab[i].fi) ok[j] = true;
	}
	printf ("%lld\n", sum);	
}