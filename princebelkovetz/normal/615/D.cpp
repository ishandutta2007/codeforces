#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 2e5 + 3;

int bp(int a, int b) {
	if (!b) return 1ll;
	if (b & 1) return a * bp(a, b - 1) % mod;
	int t = bp(a, b / 2);
	return t * t % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	
	int n; cin >> n;
	vector <int> a(n), cnt(N, 1), pref(N, 1), suf(N, 1);
	for (auto& x : a) 
		cin >> x, cnt[x]++;
	for (int i = 1; i < N; ++i)
		pref[i] = (pref[i - 1] * cnt[i]) % (mod - 1);
	for (int i = N - 2; i >= 0; --i) {
		suf[i] = (suf[i + 1] * cnt[i]) % (mod - 1);
	}
	int ans = 1;
	for (int i = 0; i < N; ++i) {
		if (cnt[i] == 1) continue;
		int lft = pref[i - 1] * suf[i + 1] % (mod - 1);
		for (int j = 1; j <= cnt[i] - 1; ++j) {
			ans *= bp(bp(i, j), lft);
			ans %= mod;
		}
	}

	cout << ans << '\n';

	return 0;
}