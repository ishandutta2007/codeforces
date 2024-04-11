#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;



int main ()
{
	ll k, d, t;
	scanf ("%lld %lld %lld", &k, &d, &t);
	
	t*=2LL;
	ll q = (k + d -1LL) /d; //tyle czasu trwa cykl
	ll o = q*d;
	
	ll g = k + o;
	
	
	
	ld ile = ll(o) * ll( t/g);
	t%=g;
	
	if (t<k*2LL) {
		ile+=t/ld(2);
	}
	else {
		t-=k*2LL;
		ile+=k;
		ile+=t;
	}
	printf ("%Lf\n", ile);	
}