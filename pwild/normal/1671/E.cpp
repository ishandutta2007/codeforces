#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// B            16
// A     A      2 4
// A  A  A  A   1 1 2 2
// AA BB AB AB  1 1 1 1 1 1 1 1

const int MOD = 998244353;

int main() {
	int n; cin >> n;
	string s; cin >> s;

	vector<i64> dp(1 << n, 1);
	vector<string> pre(1 << n);

	auto rec = [&](auto &self, int i) -> void {
		pre[i] = string(1, s[i-1]);
		int j = 2*i, k = j+1;
		if (j >= (1 << n)) return;
		self(self, j);
		self(self, k);
		dp[i] = dp[j] * dp[k] % MOD;
		if (pre[j] > pre[k]) swap(pre[j],pre[k]);
		if (pre[j] != pre[k]) dp[i] = 2*dp[i] % MOD;
		pre[i] += pre[j] + pre[k];
	};
	rec(rec, 1);

	cout << dp[1] << '\n';
}