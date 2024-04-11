#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int L = 18;
ll G[L][N+N];

int main ()
{
	int t;
	scanf ("%d", &t);
	rep(tc,0,t) {
		int n;
		scanf ("%d", &n);
		ll a, b;
		scanf ("%lld", &a);
		rep(i,0,n-1) {
			scanf ("%lld", &b);
			G[0][i] = abs(a - b);
			a = b;
		}
		
		rep(l,0,L-1) rep(i,0,n-1) if (i + 2*(1<<l) < n) {
			G[l+1][i] = __gcd(G[l][i], G[l][i+(1<<l)]);
		}
		
		int best = 0;
		
		rep(i,0,n-1) {
			ll g = 0;
			int len = 0;
			int v = i;
			for (int l = L-1; l >=0; l--) if (v + (1<<l) < n) if (__gcd(g, G[l][v]) > 1) {
				g = __gcd(g, G[l][v]);
				len += (1<<l);
				v += (1<<l);
			}
			
			best = max(best, len);
		}
		
		printf ("%d\n", best+1);
	}
}