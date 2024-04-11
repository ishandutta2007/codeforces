#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, k;
vector<ll> s;

void solve() {
	cin >> n >> k;
	s.resize(k);
	for (auto &i : s) cin >> i;
	if (k == 1) {
		cout << "Yes\n";
		return;
	}
	for (int i = 1; i + 1 < k; i++) {
		if (2 * s[i] > s[i - 1] + s[i + 1]) {
			cout << "No\n";
			return;
		}
	}
	ll d = s[1] - s[0];
	if (d * (n - k + 1) >= s[0]) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}