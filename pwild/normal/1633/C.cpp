#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define div asdf
i64 div(i64 a, i64 b) { return (a+b-1) / b; }

void solve() {
	i64 hc, dc, hm, dm;
	cin >> hc >> dc >> hm >> dm;
	i64 n, w, a;
	cin >> n >> w >> a;

	bool res = false;
	for (i64 k = 0; k <= n; k++) {
		if (div(hc+k*a, dm) >= div(hm, dc+(n-k)*w)) res = true;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}