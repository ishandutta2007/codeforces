#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 3;
vector<pair<int, int>> a(N);

void solve() {
	int n;
	cin >> n;
	for (auto &i : a) {
		cin >> i.first >> i.second;
		i.first--, i.second--;
	}
	int x, y;
	cin >> x >> y;
	x--, y--;

	int cnt = 0;
	for (auto &i : a) {
		if (i.first == 0 || i.first == n - 1 || i.second == 0 || i.second == n - 1)
			cnt++;
	}

	if (cnt == 3) {
		if (!(x == 0 || x == n - 1 || y == 0 || y == n - 1)) {
			cout << "NO\n";
			return;
		}
		cnt = 0;
		for (auto &i : a) {
			if (i.first == x || i.second == y)
				cnt++;
		}
		if (cnt < 2) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		return;
	}

	for (auto &i : a) {
		if (x % 2 == i.first % 2 && y % 2 == i.second % 2) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}