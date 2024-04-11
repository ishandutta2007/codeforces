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
	
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t)
	{
		ll x;
		scanf ("%lld", &x);
		
		int res = 0;
		
		for (ll l = 1, used = 1; x>=used; l += l +1)
		{
			x-=used;
			res++;
			if (x < used*2LL) break;
			
			used  = used * 2 + (l+1)*(l+1);
		}
		
		printf ("%d\n", res);
	}
	
}