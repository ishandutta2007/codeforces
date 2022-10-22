#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int m = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, m, u, v; cin >> n >> m;
	vector <set <int>> a(n + 1);
	vector <int> m1, m2, m3;
	vector <bool> used(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		a[u].insert(v);
		a[v].insert(u);
	}
	m1.push_back(1);
	used[1] = true;
	for (int i = 2; i <= n; ++i) {
		if (a[1].find(i) == a[1].end()) {
			m1.push_back(i);
			used[i] = true;
		}
	}
	for (int i = 2; i < n; ++i) {
		if (used[i]) continue;
		m2.push_back(i);
		used[i] = true;
		break;
	}
	if (!m2.size()) { cout << -1 << endl; return 0; }
	for (int i = 2; i <= n; ++i) {
		if (a[m2[0]].find(i) == a[m2[0]].end() and !used[i]) {
			m2.push_back(i);
			used[i] = true;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (used[i]) continue;
		m3.push_back(i);
		used[i] = true;
		break;
	}
	/*for (auto x : m1) cout << x << " ";
	cout << endl;
	for (auto x : m2) cout << x << " ";
	cout << endl;
	for (auto x : m3) cout << x << " ";
	cout << endl;*/
	if (!m3.size()) { cout << -1 << endl; return 0; }
	for (int i = 2; i <= n; ++i) {
		if (a[m3[0]].find(i) == a[m3[0]].end() and !used[i]) {
			m3.push_back(i);
			used[i] = true;
		}
	}
	if (m1.size() + m2.size() + m3.size() != n) {
		cout << -1 << endl; return 0;
	}
	for (int i = 0; i < m1.size(); ++i) {
		for (int j = 0; j < m2.size(); ++j) {
			if (a[m1[i]].find(m2[j]) == a[m1[i]].end()) {
				cout << -1 << endl; return 0;
			}
		}
	}
	for (int i = 0; i < m2.size(); ++i) {
		for (int j = 0; j < m3.size(); ++j) {
			if (a[m2[i]].find(m3[j]) == a[m2[i]].end()) {
				cout << -1 << endl; return 0;
			}
		}
	}
	for (int i = 0; i < m1.size(); ++i) {
		for (int j = 0; j < m3.size(); ++j) {
			if (a[m1[i]].find(m3[j]) == a[m1[i]].end()) {
				cout << -1 << endl; return 0;
			}
		}
	}
	if (m != m1.size() * m2.size() + m2.size() * m3.size() + m1.size() * m3.size()) {
		cout << -1 << endl;
		return 0;
	}
	vector <int> ans(n + 1);
	for (auto x : m1) ans[x] = 1;
	for (auto x : m2) ans[x] = 2;
	for (auto x : m3) ans[x] = 3;
	for (int i = 1; i <= n; ++i) cout << ans[i] << " ";

	return 0;
}