#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int D(int k, int n) {
	if (k == 0) return 1;
	if (k == 1) return 0;
	if (k == 2) return (n * (n - 1ll)) / 2ll;
	if (k == 3) return (n * (n - 1ll) * (n - 2)) / 3ll;
	return (n * (n - 1ll) * (n - 2) * (n - 3) * 3ll) / 8ll;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	int ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans += D(i, n);
	}
	cout << ans;
}