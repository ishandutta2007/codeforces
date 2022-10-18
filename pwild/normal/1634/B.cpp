#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x; i64 y;
	cin >> n >> x >> y;

	while (n--) {
		int a; cin >> a;
		x = (x+a) % 2;
	}

	cout << ((x+y)%2 == 0 ? "Alice" : "Bob") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}