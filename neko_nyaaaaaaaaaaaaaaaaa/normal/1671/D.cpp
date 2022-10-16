#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (*min_element(a.begin(), a.end()) > x) {
		int ans = INF;
		// LMAO nice case

		int score = 0;
		for (int i = 1; i < n; i++) {
			score += abs(a[i] - a[i-1]);
		}

		ans = min(ans, score + (a[0]-1));
		ans = min(ans, score + (a[n-1]-1));
		for (int i = 1; i < n; i++) {
			ans = min(ans, score + 2*(min(a[i], a[i-1])-1));
		}
		cout << ans << '\n';

		return;
	}

	int ans = INF;
	// insert 1 into first
	{
		vector<int> b = a;
		b.insert(b.begin(), 1);
		int score = 0;
		for (int i = 1; i < b.size(); i++) {
			score += abs(b[i] - b[i-1]);
		}
		ans = min(ans, score + abs(x - b[0]));
		ans = min(ans, score + abs(x - b.back()));
		for (int i = 1; i < b.size(); i++) {
			if ((b[i-1] - x)*(b[i] - x) <= 0) ans = min(ans, score);
			ans = min(ans, score + 2*abs(x - max(b[i], b[i-1])));
		}
	}

	// insert 1 into last
	{
		vector<int> b = a;
		b.push_back(1);
		int score = 0;
		for (int i = 1; i < b.size(); i++) {
			score += abs(b[i] - b[i-1]);
		}
		ans = min(ans, score + abs(x - b[0]));
		ans = min(ans, score + abs(x - b.back()));
		for (int i = 1; i < b.size(); i++) {
			if ((b[i-1] - x)*(b[i] - x) <= 0) ans = min(ans, score);
			ans = min(ans, score + 2*abs(x - max(b[i], b[i-1])));
		}
	}

	// insert 1 into middle
	{
		vector<int> b = a;
		int score = 0;
		for (int i = 1; i < b.size(); i++) {
			score += abs(b[i] - b[i-1]);
		}
		int mn1 = INF, mnx = INF;
		mnx = min(mnx, abs(x - b[0]));
		mnx = min(mnx, abs(x - b.back()));
		for (int i = 1; i < b.size(); i++) {
			mn1 = min(mn1, 2*abs(1 - min(b[i], b[i-1])));
			if ((b[i-1] - x)*(b[i] - x) <= 0) mnx = 0;
			else mnx = min(mnx, 2*abs(x - max(b[i], b[i-1])));
		}
		ans = min(ans, score+mn1+mnx);
	}

	// output
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}