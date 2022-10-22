#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9 + 7;

namespace Hashing {

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const ar<int, 2> base = {BDIST(rng), BDIST(rng)};

ar<int, 2> operator+ (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] += b[i]) >= MOD)
			a[i] -= MOD;
	return a;
}
ar<int, 2> operator- (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] -= b[i]) < 0)
			a[i] += MOD;
	return a;
}
ar<int, 2> operator* (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		a[i] = (ll)a[i] * b[i] % MOD;
	return a;
}
ar<int, 2> make_hash(char c) {
	return {c, c};
}

vector<ar<int, 2>> pows = {{1, 1}};
void extend(int len) {
	while(pows.size() <= len)
		pows.push_back(base * pows.back());
}

struct hstring {
	string s;
	vector<ar<int, 2>> pre = {{0, 0}};
	void add(string t) {
		s += t;
		for (char c : t)
			pre.push_back(base * pre.back() + make_hash(c));
	}
	ar<int, 2> hash(int l, int r) {
		assert(0 <= l && l <= r && r < s.size());
		int len = r - l + 1;
		extend(len);
		return pre[r + 1] - pows[len] * pre[l];
	}
};

}
using namespace Hashing;

int n, m, k, dp[100000][31];
string s, t;
hstring hs, ht;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> m >> t >> k;
	hs.add(s), ht.add(t);
	for (int j = 1; j <= k; ++j) {
		for (int i = 0; i < n; ++i) {
			int start = 0;
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (i) {
				start = dp[i - 1][j - 1];
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			if (m - start > n - i) continue;
			int l = 0, r = m - start;
			while(l < r) {
				int mid = (l + r + 1) / 2;
				if (hs.hash(i, i + mid - 1) == ht.hash(start, start + mid - 1)) l = mid;
				else r = mid - 1;
			}
			if (l == m - start) {
				cout << "YES";
				return 0;
			}
			if (l) dp[i + l - 1][j] = max(dp[i + l - 1][j], start + l);
		}
	}
	cout << "NO";
	return 0;
}