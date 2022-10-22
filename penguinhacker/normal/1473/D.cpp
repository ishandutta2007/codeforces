#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		string s; cin >> s;
		vector<int> pre(n + 1);
		for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + (s[i] == '+' ? 1 : -1);
		vector<pair<int, int>> ls(n + 1), rs(n + 1);
		for (int i = 1; i <= n; ++i) {
			ls[i] = ls[i - 1];
			ls[i].first = min(ls[i].first, pre[i]);
			ls[i].second = max(ls[i].second, pre[i]);
		}
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			rs[i] = rs[i - 1];
			cur -= s[n - i] == '+' ? 1 : -1;
			rs[i].first = min(rs[i].first, cur);
			rs[i].second = max(rs[i].second, cur);
		}
		cur = 0;
		for (int i = 1; i <= n; ++i) {
			cur -= s[n - i] == '+' ? 1 : -1;
			rs[i].first -= cur;
			rs[i].second -= cur;
		}
		for (int i = 0; i < m; ++i) {
			int l, r; cin >> l >> r, --l;
			pair<int, int> a = ls[l];
			pair<int, int> b = rs[n - r];
			b.first += pre[l], b.second += pre[l];
			//cout << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";
			int lb = min(a.first, b.first), rb = max(a.second, b.second);
			cout << rb - lb + 1 << "\n";
		}
	}
	return 0;
}