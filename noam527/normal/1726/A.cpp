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
	if (n == 1) {
		cout << "0\n";
		return;
	}
	int ans = -100000;
	ans = max(ans, a[n - 1] - *min_element(a.begin(), a.end() - 1));
	ans = max(ans, *max_element(a.begin() + 1, a.end()) - a[0]);
	ans = max(ans, a[n - 1] - a[0]);
	for (int i = 1; i < n; i++) {
		ans = max(ans, a[i - 1] - a[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}