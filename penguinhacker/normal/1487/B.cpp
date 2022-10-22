#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int INF = 1e9 + 5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		if (n % 2 == 1) {
			k += (k - 1) / ((n - 1) / 2);
		}
		int ans = k % n;
		if (ans == 0) ans = n;
		cout << ans << "\n";
	}
	return 0;
}