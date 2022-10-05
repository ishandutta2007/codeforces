#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

void solve() {
	int n, d;
	vector<int> a;
	cin >> n >> d;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 1; i < n; i++) {
		while (d >= i && a[i] > 0) {
			a[i]--;
			a[0]++;
			d -= i;
		}
	}
	cout << a[0] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}