#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a, b;
int can[10005], can2[10005];

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	for (int i = 0; i < 10005; i++) can[i] = 0;
	can[0] = 1;
	int sum = 0;
	for (auto &i : a) sum += i;
	for (auto &i : b) sum += i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10005; j++) can2[j] = 0;
		for (int j = 10001; j >= 0; j--) {
			if (j >= a[i]) can2[j] |= can[j - a[i]];
			if (j >= b[i]) can2[j] |= can[j - b[i]];
		}
		for (int j = 0; j < 10005; j++)
			can[j] = can2[j];
	}
	ll mn = inf;
	for (int i = 0; i < 20005; i++) {
		if (can[i]) mn = min(mn, (ll)i*i + (ll)(sum - i) * (sum - i));
	}
	for (int i = 0; i < n; i++) {
		mn += ll(n - 2) * (a[i] * a[i] + b[i] * b[i]);
	}
	cout << mn << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}