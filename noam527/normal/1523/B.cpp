#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	cout << 3 * n << '\n';
	vector<int> op = { 1, 2, 2, 1, 2, 2 };
	for (int i = 1; i <= n; i += 2) {
		for (auto x : op) {
			cout << x << " " << i << " " << i + 1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}