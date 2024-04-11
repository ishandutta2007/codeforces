#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &y: a) cin >> y;

	x = max(x, *max_element(begin(a), end(a)));

	int imin = min_element(begin(a), end(a)) - begin(a);

	i64 res = 1e18;
	for (int i: {0,imin,n}) {
		vector<int> b = a;
		b.insert(begin(b)+i, 1);

		int jmax = max_element(begin(b), end(b)) - begin(b);
		for (int j: {0,jmax,n+1}) {
			vector<int> c = b;
			c.insert(begin(c)+j, x);

			i64 cur = 0;
			for (int k = 0; k+1 < ssize(c); k++) {
				cur += abs(c[k]-c[k+1]);
			}
			res = min(res,cur);
		}
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}