#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf  = 1e9;

ll check (ll p, ll &q, ll pr)
{
	ll x = p;
	int cnt = 0;
	while (q%pr == 0)
	{
		cnt++;
		q/=pr;
	}
			
	if (cnt==0) return 1;
	
	int cnt2 = 0;
	while (x%pr==0) {
		cnt2++;
		x/=pr;
	}
			
	rep(i,0,min(cnt2, cnt-1)) x*=pr;
			
	return x;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(ts,0,t)
	{
		ll p, q;
		scanf ("%lld %lld", &p, &q);
		
		ll best = 1;
		
		
		for (ll pr = 2; pr*pr <=q; pr++)
		{
			
			
			best = max(best, check(p, q, pr));
		}
		
		if (q>1) best = max(best, check(p, q, q));
		
		
		printf ("%lld\n", best);
	}
	
}