#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;



void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	n %= 3;
	if (n == 0) cout << a << '\n';
	else if (n == 1) cout << b << '\n';
	else cout << (a ^ b) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}