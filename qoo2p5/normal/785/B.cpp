#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;

#define sz(x) (int) (x).size()

void run();

signed main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

int n, m;

void run() {
	int X = INF;
	int Y = -INF;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		X = min(X, r);
		Y = max(Y, l);
	}
	
	int ans = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		ans = max(ans, l - X);
		ans = max(ans, Y - r);
	}
	
	cout << ans << endl;
}