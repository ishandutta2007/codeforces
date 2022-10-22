#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll n, m, sum;

void solve() {
	sum = 0;
	cin >> n >> m;
	multiset<int> a;
	for (int i=0, x; i<m; ++i) {
		cin >> x;
		a.insert(__builtin_ctz(x));
		sum += x;
	}
	if (sum < n) {
		cout << -1 << '\n';
		return;
	}

	int ans = 0;
	for (int i=0; i<(64 - __builtin_clzll(n)) && !a.empty(); ++i) {
		while (*a.begin() == i-1) {
			a.erase(a.begin());
			if (*a.begin() == i-1) {
				a.erase(a.begin());
				a.insert(i);
			}
		}
		if ((n>>i)&1) {
			while (*a.begin() > i) {
				int x = *a.begin();
				a.erase(a.begin());
				a.insert(x-1);
				a.insert(x-1);
				ans++;
			}
			a.erase(a.begin());
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}