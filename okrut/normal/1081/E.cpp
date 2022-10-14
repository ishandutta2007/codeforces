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

vector <ll> moz; //smallest possible
vector <ll> res;
int n;
int main ()
{
	scanf ("%d", &n);
	moz.resize(n/2, -1); //empty
	ll x, d, m;
	ll s=0; //minimal sum so far
	ll rob;
	rep(i,0,n/2)
	{
		scanf ("%lld", &x);
		//x = 2*dm+d^2 -for some d:
		//m=(x-d*d)/(2d)
		d=1;
		rob=-1;
		while (d*d<x)
		{
			if ((x-d*d)%(2LL*d)==0) //dopuszczalne
			{
				m=(x-d*d)/(2LL*d);
				if (m*m>s) 
				{
					debug ("a moze %lld ^2\n", m);
					rob=m*m; //my sum so far
				}
			}
			d++;
		} 
		if (rob==-1)
		{
			printf ("No\n");
			return 0;
		}
		res.pb(rob-s);
		res.pb(x);
		s=rob+x;
	}
	printf ("Yes\n");
	rep(i,0,n) printf ("%lld ", res[i]);
	printf ("\n");
}