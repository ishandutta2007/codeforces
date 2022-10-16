#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 250004;

int ft[MAX], n, m;

void init() {
	ft[0] = 1;
	for (int i = 1; i <= 250000; i++) {
		ft[i] = (ft[i-1]*i) % m;
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n >> m) {
		init();
	
		int ans = 0;
		for (int len = 1, p = n; len <= n; len++, p--) {
			int f1 = (p*p) % m;
			int f2 = (ft[len]*ft[n - len]) % m;

			ans = (ans + f1*f2) % m;
		}
		cout << ans << '\n';
	}

	return 0;
}