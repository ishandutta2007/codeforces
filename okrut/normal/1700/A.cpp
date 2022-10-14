#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		ll n, m;
		scanf ("%lld %lld", &n, &m);
		
		ll right = m * (m - 1) / 2 + m * (1 + n) * n / 2;
		ll left = m * (n - 1) * n + m * (m + 1) / 2;
		if (n > 1)
			left += n - 1 + m * (n - 1) * (n-2) / 2;
		
		printf ("%lld\n", min(left, right));
	}
}