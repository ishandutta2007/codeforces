#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll a, b, n;

void solve() {
	cin >> a >> b >> n;
	if (a > b) swap(a, b);
	int cnt = 0;
	while (b <= n) {
		a += b;
		swap(a, b);
		cnt++;
	}
	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}