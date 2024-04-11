#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

int n;
vector<ll> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	for (int i = 0; i < n; i += 2) {
		ll mn = inf;
		ll cursum = a[i];
		for (int j = i + 1; j < n; j++) {
			mn = min(mn, cursum);
			if ((j - i) % 2 == 0) {
				cursum += a[j];
				continue;
			}
			cursum -= a[j];

			if (OO) {
				cout << i << " " << j << ": " << mn << " " << cursum << '\n';
			}

			if (mn < 0) continue;

			ll atmost = min(mn, min(a[i] - 1, cursum + a[j] - 1));
			ll atleast = max(0LL, cursum);
			if (atmost >= atleast)
				ans += atmost - atleast + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}