#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const int OO = 1;
using namespace std;

int n, m;
vector<vector<int>> a, b;

void solve() {
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		b[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
		sort(b[i].begin(), b[i].end());
	}
	vector<int> d;
	for (int j = 0; j < m; j++) {
		bool found = false;
		for (int i = 0; !found && i < n; i++) {
			if (a[i][j] != b[i][j])
				found = true;
		}
		if (found)
			d.push_back(j);
	}
	if (d.size() == 0) {
		cout << "1 1\n";
		return;
	}
	if (d.size() == 2) {
		int x = d[0], y = d[1];
		for (int i = 0; i < n; i++) {
			if (a[i][x] != b[i][y] || a[i][y] != b[i][x]) {
				cout << "-1\n";
				return;
			}
		}
		cout << 1 + d[0] << " " << 1 + d[1] << '\n';
		return;
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}