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

ll ile[31], pot[31];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	pot[0] = 1LL;
	rep(i,1,31) pot[i] = pot[i-1] + pot[i-1];
	
	rep(q,0,t)
	{
		ll d, m;
		scanf ("%lld %lld", &d, &m);
		rep(i,0,31)
		{
			ile[i] = max(0LL,min(d, pot[i]));
			d -= pot[i];
		}
		
		ll res = 1LL;
		rep(i,0,31) res = res * (ile[i]+1LL) % m;
		printf ("%lld\n", (res - 1LL + m)%m);
	}
}