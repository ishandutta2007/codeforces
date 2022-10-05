#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	vector<pair<int, int>> b;
	for (auto &i : a) {
		if (!b.size() || b.back().first != i)
			b.emplace_back(i, 1);
		else
			b.back().second++;
	}
	for (int it = 1; it < n; it++) {
		int m = b.size();
		vector<pair<int, int>> c;
		if (b[0].second > 1)
			c.emplace_back(0, b[0].second - 1);
		for (int j = 1; j < m; j++) {
			if (b[j].second > 1)
				c.emplace_back(0, b[j].second - 1);
			c.emplace_back(b[j].first - b[j - 1].first, 1);
		}
		sort(c.begin(), c.end());
		b.clear();
		for (auto &i : c) {
			if (!b.size() || b.back().first != i.first)
				b.emplace_back(i);
			else
				b.back().second += i.second;
		}
		if (!OO) {
			cout << "after it:\n";
			for (const auto &i : b) cout << i.first << " " << i.second << '\n';
		}
	}
	cout << b[0].first << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}