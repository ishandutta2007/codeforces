#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, m;
vector<pair<int, int>> a;
vector<vector<int>> b;

void solve() {
	cin >> n >> m;
	a.clear();
	b.clear();
	vector<int> cnt(n, 0);
	a.reserve(n * m);
	b.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			a.emplace_back(b[i][j], i);
		}
		sort(b[i].begin(), b[i].end());
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++) {
		cnt[a[i].second]++;
	}
	int add = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << b[i][(j + add) % m] << " ";
		}
		cout << '\n';
		add -= cnt[i];
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}