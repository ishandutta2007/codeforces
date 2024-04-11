#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;

void solve() {
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cout << x + mx << " ";
		mx = max(mx, x + mx);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
}