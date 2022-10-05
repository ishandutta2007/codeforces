#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int cnt = 0;
	ll sum = 0;
	for (int i = 1; i < n - 1; i++) {
		cnt += a[i] % 2;
		sum += a[i];
	}
	if (n == 3 && cnt == n - 2) {
		cout << "-1\n";
		return;
	}
	if (cnt < n - 2) {
		cout << (sum + cnt) / 2 << '\n';
		return;
	}
	if (sum == cnt) {
		cout << "-1\n";
		return;
	}
	cout << (sum + cnt) / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}