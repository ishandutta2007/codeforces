#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MAXN = 100000;
const int MAGIK = 100;
const int MC = MAXN/MAGIK;

// an INTEGER arithmetic progression
// brute on the common difference?
// 5s ---> sqrt??????
// for small d, how to brute?
// - index
// for large d? (solve in O(sqrtN) or less)
// the indices we keep can only belong to a small window
// dp probably

int solve(int n, vector<int> a) {
	int ans = 1;
	for (int d = 0; d <= MAGIK; d++) {
		gp_hash_table<int, int, custom_hash> mp;
		for (int i = 0; i < n; i++) {
			mp[a[i] - i*d]++; ans = max(ans, mp[a[i] - i*d]);
		}
	}

	vector<int> dp(n, 1);
	vector<pair<int, int>> adj[MAXN+1];
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n && j-i <= MC; j++) {
			int dif = a[j] - a[i], dist = j-i;
			if (dif < 0) continue;
			if (dif % dist) continue;
			if (dif/dist <= MAGIK) continue;

			adj[dif/dist].emplace_back(i, j);
		}
	}

	for (int d = MAGIK+1; d <= MAXN; d++) {
		for (auto [u, v]: adj[d]) {
			dp[v] = max(dp[v], dp[u] + 1);
			ans = max(ans, dp[v]);
		}
		for (auto [u, v]: adj[d]) {
			dp[u] = dp[v] = 1;
		}
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = solve(n, a);
	reverse(a.begin(), a.end());
	ans = max(ans, solve(n, a));
	cout << n-ans << '\n';

	return 0;
}