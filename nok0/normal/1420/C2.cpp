#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll res;
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll res = 0;
		int n, q;
		cin >> n >> q;
		vector a(n + 2, 0);
		for(int i = 1; i <= n; i++) cin >> a[i];

		auto f = [&a](int i) { return max(0, a[i] - a[i + 1]); };

		for(int i = 0; i < n + 1; i++) res += f(i);
		cout << res << '\n';

		while(q--) {
			int l, r;
			cin >> l >> r;
			res -= f(l) + f(l - 1) + f(r) + (r - l != 1 ? f(r - 1) : 0);
			swap(a[l], a[r]);
			res += f(l) + f(l - 1) + f(r) + (r - l != 1 ? f(r - 1) : 0);
			cout << res << '\n';
		}
	}
	return 0;
}