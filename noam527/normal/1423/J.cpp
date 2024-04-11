#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

void solve() {
	ll m;
	cin >> m;
	if (m == 1) {
		cout << "1\n";
		return;
	}
	ll n = m / 2;
	if (n & 1) {
		ll x = (n / 2 + 1) % md;
		cout << x * (x + 1) % md << '\n';
	}
	else {
		ll x = (n / 2 + 1) % md;
		cout << x * x % md << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}