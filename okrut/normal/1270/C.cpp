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
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		ll x=0, s=0;
		rep(i,0,n)
		{
			ll a;
			scanf ("%lld", &a);
			x = x^a;
			s += a;
		}
		
		ll a=1,b=0, c=0;
		rep(i,0,50) a = a*2LL;
		
		if (s%2LL==1) 
		{
			a+= 1;
		}
		
		s+=a;
		x^=a;
		
		assert(s <= 2LL*x);
		ll r = 2LL*x - s;
		b=r/2LL;
		c=r/2LL;
		printf ("3\n%lld %lld %lld\n", a, b, c);
	}
}