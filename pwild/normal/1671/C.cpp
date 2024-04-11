#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &y: a) cin >> y;
	sort(begin(a), end(a));

	i64 sum = accumulate(begin(a), end(a), 0LL), k = n, day = 0, res = 0;
	while (k > 0) {
		i64 nday = sum <= x ? (x-sum)/k : -1;
		if (nday >= day) {
			res += (nday+1-day) * k;
			day = nday+1;
		}
		sum -= a[--k];
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}