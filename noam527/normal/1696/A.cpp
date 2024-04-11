#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, z;
vector<int> a;

void solve() {
	cin >> n >> z;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int mx = a[0] | z;
	for (auto &i : a)
		mx = max(mx, i | z);
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}