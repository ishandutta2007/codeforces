#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m;
string s;

void solve() {
	cin >> n >> m >> s;
	vector<int> ans(n * m, 0);
	// columns
	vector<int> taken(m, 0);
	for (int i = 0; i < n * m; i++) {
		if (s[i] == '0') continue;
		if (taken[i % m]) continue;
		taken[i % m] = 1;
		ans[i]++;
	}
	for (int i = 1; i < n * m; i++)
		ans[i] += ans[i - 1];
	// rows
	vector<int> rows(n * m, 0);
	int lst = -md;
	for (int i = 0; i < n * m; i++) {
		if (s[i] == '1') lst = i;
		if (i - lst < m)
			rows[i]++;
	}
	for (int i = m; i < n * m; i++)
		rows[i] += rows[i - m];
	
	for (int i = 0; i < n * m; i++)
		ans[i] += rows[i];
	for (auto &i : ans) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}