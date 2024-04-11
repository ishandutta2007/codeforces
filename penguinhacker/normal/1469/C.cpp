#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> h(n); for (int& i : h) cin >> i;
		int l = h[0], r = h[0];
		bool b = 1;
		for (int i = 1; i < n; ++i) {
			l -= k - 1, r += k - 1;
			int cl = h[i], cr = i == n - 1 ? h[i] : h[i] + k - 1;
			l = max(l, cl), r = min(r, cr);
			if (l > r) {
				b = 0;
				break;
			}
		}
		cout << (b ? "YES" : "NO") << "\n";
	}
	return 0;
}