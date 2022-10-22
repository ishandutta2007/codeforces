#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n); for (int& i : a) cin >> i;
		sort(a.rbegin(), a.rend());
		ll alice = 0;
		ll bob = 0;
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) alice += a[i] * (a[i] % 2 == 0);
			else bob += a[i] * (a[i] % 2 == 1);
		}
		if (bob == alice) cout << "Tie\n";
		else cout << (alice > bob ? "Alice" : "Bob") << "\n";
	}
	return 0;
}