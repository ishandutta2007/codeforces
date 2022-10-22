#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n, m, k; cin >> n >> m >> k;
		ll c = (k + n - 1) / n;
		ll r = (k - 1) % n + 1;
		cout << (r - 1) * m + c << "\n";
	}
	return 0;
}