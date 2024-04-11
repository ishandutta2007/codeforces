#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct students {
	int n, k;
	i64 sum = 0;
	vector<int> a;

	bool check(int x) { return (sum+n-1)/n <= x; }

	bool operator<(const students &s) const { return sum*s.n < s.sum*n; }
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(begin(a), end(a));
	a.erase(begin(a), begin(a)+n-m);
	n = m;

	vector<students> b(n);
	int k = 0;
	for (auto &s: b) {
		cin >> s.n;
		s.k = k;
		s.a.resize(s.n);
		for (int &x: s.a) {
			cin >> x;
			s.sum += x;
			k++;
		}
	}
	sort(begin(b), end(b));

	vector<vector<int>> dp(3, vector<int>(n+1));
	for (int d = -1; d <= 1; d++) {
		for (int i = 0; i < n; i++) {
			// can class i be paired with teacher i+d?
			bool ok = i+d >= 0 && i+d < n && b[i].check(a[i+d]);
			dp[d+1][i+1] = dp[d+1][i] + ok;
		}
	}

	// is the range [i,j) ok if each k is paired with k+d?
	auto check = [&](int i, int j, int d) {
		return dp[d+1][j]-dp[d+1][i] == j-i;
	};
	
	string res(k,'?');
	for (int i = 0; i < n; i++) {
		auto s = b[i];
		k = s.k, s.n--;
		for (int x: s.a) {
			s.sum -= x;

			int j = lower_bound(begin(b), end(b), s) - begin(b);
			if (j > i) j--;

			bool ok = check(0, min(i,j), 0) && check(max(i,j)+1, n, 0);
			if (i < j) ok = ok && check(i+1, j+1, -1);
			if (i > j) ok = ok && check(j, i, 1);
			ok = ok && s.check(a[j]);

			res[k++] = '0' + ok;

			s.sum += x;
		}
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}