#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

static inline ll query(int l, int r)
{
	printf ("? %d %d\n", l, r);
	fflush(stdout);
	ll x;
	scanf ("%lld", &x);
	return 2*x;
}

ll get_len(int l, int n)
{
	ll x = query(l, n);
	ll y = query(l+1, n);
	return (x - y + 3) / 2;
}

int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		
		ll x = query(1,n);
		
		int l = 1, r = n;
		while (l < r) {
			int mid = (l+r)/2;
			
			if (query(mid+1, n) == x) l = mid+1;
			else r = mid;
		}
		
		int i = l;
		int l1 = get_len(i,n);
		int l2 = get_len(i+l1,n);
		printf ("! %d %d %d\n", i, i+l1, i+l1+l2-1);
		fflush(stdout);
		
	}
}