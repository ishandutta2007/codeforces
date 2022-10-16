#include <bits/stdc++.h>
using namespace std;

#define int long long

void brut(int k) {
	int ans = 0;
	for (int i = 1; i*i <= k; i++) {
		if (k % i == 0) {
			int a = k/i;
			int b = i;
			if (a != k) ans = max(ans, __gcd(k & a, k ^ a));
			if (b != k) ans = max(ans, __gcd(k & b, k ^ b));
		}
	}
	cout << ans << '\n';
}

void solve(int n) {
	int k = 1;
	while (k - 1 < n) {
		k *= 2;
	}
	k--;
	if (k == n) {brut(k);}
	else cout << k << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> q;
	int x = 1;
	while (q--) {
		cin >> x;
		solve(x);
	}

	return 0;
}