#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;



void solve() {
	int n, q;
	cin >> n >> q;
	int cnt = 0;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
		if (i) cnt++;
	}
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			x--;
			cnt -= a[x];
			a[x] ^= 1;
			cnt += a[x];
		}
		else {
			if (x <= cnt) cout << "1\n";
			else cout << "0\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	while (tst--) solve();
}