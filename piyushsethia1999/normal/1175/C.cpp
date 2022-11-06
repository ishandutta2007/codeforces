#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--) {
		int mind = 10000000000000ll;
		int x = -1;
		int n; cin >> n;
		int k; cin >> k;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n - k; ++i) {
			if (((a[i + k] - a[i] + 1ll) / 2ll) < mind) {
				mind = ((a[i + k] - a[i] + 1ll) / 2ll);
				x = (a[i + k] + a[i]) / 2ll;
			}
		}
		cout << x << "\n";
	}
}