#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define int long long 
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7, p = 41, N = 1e7 + 2;
vector <int> re(N), pws(N, 1);
int get(int x) {
	vector <pair <int, int>> dels;
	while (re[x]) {
		if (!dels.empty() and dels.back().first == re[x])
			dels.back().second++;
		else
			dels.push_back({ re[x], 1 });
		x /= re[x];
	}
	int hh = 0;
	for (auto x : dels) {
		hh += pws[x.first] * (x.second % 2) % mod;
		hh %= mod;
	}
	return hh;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	for (int i = 2; i < N; ++i) {
		if (re[i]) continue;
		re[i] = i;
		for (int j = i * i; j < N; j += i) {
			if (!re[j]) re[j] = i;
		}
	}
	for (int i = 1; i < N; ++i) {
		pws[i] = (pws[i - 1] * p) % mod;
	}
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int ans = 1;
		set <int> cur = {};
		for (int i = 0; i < n; ++i) {
			int hh = get(a[i]);
			if (cur.find(hh) != cur.end()) {
				cur = { }, ans++;
			}
			cur.insert(hh);
		}
		cout << ans << '\n';
	}
}