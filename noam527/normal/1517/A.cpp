#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int B = 2050;

ll n;

void solve() {
	cin >> n;
	if (n % B != 0) {
		cout << "-1\n";
		return;
	}
	ll b = B;
	ll cnt = 0;
	while (n > 0) {
		while (n % (10 * b) != 0) {
			n -= b;
			cnt++;
		}
		b *= 10;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}