#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a, b, c;

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	for (auto &i : c) cin >> i;
	int lst = -1;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		if (lst != a[i]) {
			lst = a[i];
		}
		else {
			lst = b[i];
		}
		p[i] = lst;
	}
	if (a[n - 1] != p[n - 2] && a[n - 1] != p[0])
		p[n - 1] = a[n - 1];
	else if (b[n - 1] != p[n - 2] && b[n - 1] != p[0])
		p[n - 1] = b[n - 1];
	else
		p[n - 1] = c[n - 1];
	for (int i = 0; i < n; i++) cout << p[i] << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}