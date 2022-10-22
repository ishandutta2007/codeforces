#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, cnt[100000];
vector<int> f[100000];

void solve() {
	cin >> n >> m;
	int mx = (m + 1) / 2;
	memset(cnt, 0, 4 * n);
	for (int i = 0; i < m; ++i) {
		int k; cin >> k;
		f[i].resize(k);
		for (int& j : f[i])
			cin >> j, --j;
		if (k == 1)
			++cnt[f[i][0]];
	}
	for (int i = 0; i < n; ++i)
		if (cnt[i] > mx) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
	for (int i = 0; i < m; ++i) {
		if (f[i].size() == 1)
			cout << f[i][0] + 1 << " ";
		else {
			int a = f[i][0], b = f[i][1];
			if (cnt[a] < mx)
				cout << a + 1 << " ", ++cnt[a];
			else
				cout << b + 1 << " ", ++cnt[b];
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}