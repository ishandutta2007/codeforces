#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	i64 k; cin >> k;
	
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(begin(a), end(a));

	vector<i64> s(n+1);
	for (int i = 0; i < n; i++) {
		s[i+1] = s[i] + a[i];
	}

	i64 res = 1e18;
	for (i64 set = 0; set < n; set++) {
		i64 dec = max(0LL, (a[0]*set + s[n-set] - k + set) / (set+1));
		res = min(res, dec+set);
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}