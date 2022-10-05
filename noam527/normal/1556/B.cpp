#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

ll check(int st) {
	int nxt = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == st) {
			ans += abs((ll)i - nxt);
			nxt += 2;
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	a.resize(n);
	int c[2] = {};
	for (auto &i : a) {
		cin >> i;
		i %= 2;
		c[i]++;
	}
	if (abs(c[0] - c[1]) >= 2) {
		cout << "-1\n";
		return;
	}
	if (c[0] == c[1]) {
		cout << min(check(0), check(1)) << '\n';
		return;
	}
	if (c[0] > c[1]) {
		cout << check(0) << '\n';
	}
	else
		cout << check(1) << '\n';
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}