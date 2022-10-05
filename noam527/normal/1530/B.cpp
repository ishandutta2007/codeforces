#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, m;
vector<pair<int, int>> pos;
int a[25][25];

bool can(int i, int j) {
	for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) {
		if (a[i + dx][j + dy]) return false;
	}
	return true;
}

int work(int x) {
	for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++) a[i][j] = 0;
	int ans = 0;
	for (int i = x; i < pos.size(); i++) {
		int p = pos[i].first, q = pos[i].second;
		if (can(p, q)) {
			ans++;
			a[p][q] = 1;
		}
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	pos.clear();
	for (int j = 1; j <= m; j++) pos.emplace_back(1, j);
	for (int i = 2; i <= n; i++) pos.emplace_back(i, m);
	for (int j = m - 1; j >= 1; j--) pos.emplace_back(n, j);
	for (int i = n - 1; i > 1; i--) pos.emplace_back(i, 1);

	int best = -1, bestans = -1;
	for (int i = 0; i <= 2; i++) {
		int res = work(i);
		if (res > bestans) {
			bestans = res;
			best = i;
		}
	}
	work(best);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << a[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}