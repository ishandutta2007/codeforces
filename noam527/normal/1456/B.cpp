#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i + 2 < n; i++) {
		if (a[i] > (a[i + 1] ^ a[i + 2])) {
			cout << "1\n";
			return;
		}
	}
	for (int i = 1; i < n; i++) a[i] ^= a[i - 1];
	int ans = md;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int x1 = a[j];
				if (i > 0) x1 ^= a[i - 1];
				int x2 = a[k] ^ a[j];
				if (x1 > x2) ans = min(ans, k - i - 1);
			}
		}
	}
	if (ans < md) cout << ans << '\n';
	else cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}