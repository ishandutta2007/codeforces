#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
vector<pair<int, int>> a;

void solve() {
	cin >> n >> k;
	a.resize(n);
	ll ans = 0, cnt = 1;
	for (int i = 0; i < k; i++) ans += n - i;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend());
	vector<int> ind;
	for (int i = 0; i < k; i++) ind.push_back(a[i].second);
	sort(ind.begin(), ind.end());

	for (int i = 0; i + 1 < ind.size(); i++) {
		cnt = (cnt * (ind[i + 1] - ind[i])) % md;
	}
	cout << ans << " " << cnt << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
}