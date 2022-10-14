#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi fist
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;
//1.obliczamy najtansze koszty dojscia do pierwszych a punktow
vector <ll> koszt;
ll m, a, b;
int main ()
{
	scanf ("%lld %lld %lld", &m, &a, &b);
	koszt.resize(a, -1LL); //nie da sie;
	ll pay=0LL;
	ll spot=0LL;
	while (koszt[spot]==-1LL)
	{
		koszt[spot] = pay;
		
		while (spot<b)
		{
			spot += max( 1LL, (b - spot)/a) * a;
		}
		pay = max (pay, spot);
		while (spot>=a + b) spot-=b;
		spot-=b;		
	}
	//koszty sa policzone - -1 iff inaccessible
	ll res=0LL;
	rep(i,0,a) if (koszt[i]<=m && koszt[i]>=0)
	{
		ll p = (m - koszt[i] +1 ) * (koszt[i] /a + (koszt[i]%a>ll(i))); //ostro wczesniejsze
		res+=p;
		ll d = koszt[i] + ((ll (i) + a - koszt[i]%a) %a);
		//dorzucamy co d
		debug ("\nkoszty %d (%lld): %lld ",i,  koszt[i], p);
				
		if (d>m) continue; //nie ma sensu
		res += ((m-d+1LL + (m -d +1LL)%a) * ((m-d+1LL)/a + 1LL)) /2LL;
		
		debug ("i %lld (od %lld)", ((m-d+1LL + (m -d +1LL)%a) * ((m-d+1LL)/a + 1LL)) /2LL, d);
		
	}
	debug ("\n");
	printf ("%lld\n", res);
}