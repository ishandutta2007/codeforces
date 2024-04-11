#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t, n, m, k, ans;
deque<int> a;

void solve() {
	int best=1e9;
	for (int i=0; i+n-m<n-k; ++i)
		best=min(best, max(a[i], a[i+n-m]));
	ans=max(ans, best);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		if (k>=m)
			k=m-1;
		a.resize(n-k);
		for (int i=0; i<n-k; ++i)
			cin >> a[i];

		ans=0;
		solve();
		for (int i=n-k, x; i<n; ++i) {
			cin >> x;
			a.pop_front();
			a.push_back(x);
			solve();
		}
		a.clear();
		cout << ans << '\n';
	}
	return 0;
}