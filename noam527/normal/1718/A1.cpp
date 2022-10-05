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
	int ans = n;
	set<int> s;
	s.insert(0);
	for (int i = 1; i < n; i++) a[i] ^= a[i - 1];
	for (auto &x : a) {
		if (s.count(x)) {
			ans--;
			s.clear();
			s.insert(x);
			continue;
		}
		s.insert(x);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}