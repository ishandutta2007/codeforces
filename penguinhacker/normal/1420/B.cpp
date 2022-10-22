#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> cnt(30);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			a = 31 - __builtin_clz(a);
			++cnt[a];
		}
		ll ans = 0;
		for (int i = 0; i < 30; ++i) {
			ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		}
		cout << ans << "\n";
	}
	return 0;
}