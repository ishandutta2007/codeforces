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

int t, n, a[100005], b[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1, idx1 = 1, idx2 = n; i <= n; i++) {
			if (idx2 < idx1) break;
			if (i & 1) b[i] = a[idx1++];
			else b[i] = a[idx2--];
		}
		reverse(b + 1, b + 1 + n);
		for (int i = 1; i <= n; i++) cout << b[i] << ' ';
		cout << '\n';
	}
}