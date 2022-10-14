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
	int n;
	scanf ("%d", &n);
	vector <pair <int, ll> > tab(n);
	vector <int> ile(70, 0);
	rep(i,0,n)
	{
		scanf ("%lld", &tab[i].se);
		tab[i].fi = 0;
		ll dwa = 2LL;
		while(tab[i].se%dwa==0LL)
		{
			dwa*=2LL;
			tab[i].fi++;
		}
		ile[tab[i].fi]++;
	}
	int best = 0;
	rep(i,1,70) if (ile[best]<ile[i]) best = i;
	
	int k = n - ile[best];
	printf ("%d\n", k);
	rep(i,0,n) if (tab[i].fi!=best) printf ("%lld ", tab[i].se);
	if (k>0) printf ("\n");
}