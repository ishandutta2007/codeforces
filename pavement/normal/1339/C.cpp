#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;
 
int t, n, a[100005];
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int b = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1, mx = LLONG_MIN; i <= n; i++) {
			if (i > 1) {
				if (mx > a[i]) {
					b = max(b, (int)63 - (int)__builtin_clzll(mx - a[i]) + 1);
					a[i] = mx;
				}
			}
			mx = max(mx, a[i]);
		}
		cout << b << '\n';
	}
}