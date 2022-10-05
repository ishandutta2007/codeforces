#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 31607;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;
vector<pair<int, int>> a;

bool bet(int x, int v, int y) {
	return x < v && v < y;
}

void solve() {
	cin >> n >> k;
	a.resize(k);
	for (auto &i : a) {
		cin >> i.first >> i.second;
		--i.first, --i.second;
	}
	vector<int> vis(2 * n, 1);
	for (auto &i : a) {
		vis[i.first] = vis[i.second] = 0;
	}
	vector<int> left;
	for (int i = 0; i < 2 * n; i++)
		if (vis[i]) left.push_back(i);
	int m = left.size();
	for (int i = 0; 2 * i < m; i++) {
		a.emplace_back(left[i], left[i + m / 2]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<int, int> x = a[i], y = a[j];
			if (x.first > x.second) swap(x.first, x.second);
			if (y.first > y.second) swap(y.first, y.second);
			int tmp = 0;
			if (bet(y.first, x.first, y.second)) tmp++;
			if (bet(y.first, x.second, y.second)) tmp++;
			if (tmp == 1) {
				//cout << "here " << x.first << " " << x.second << " " << y.first << " " << y.second << '\n';
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}