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
	if (*max_element(a.begin(), a.end()) == 0) {
		cout << "0\n";
		return;
	}
	int l = md, r = -md;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			l = min(l, i);
			r = max(r, i);
		}
	}
	for (int i = l; i <= r; i++) {
		if (a[i] == 0) {
			cout << "2\n";
			return;
		}
	}
	cout << "1\n";
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}