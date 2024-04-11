#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0; i < 30; ++i) {
			if ((a & (1 << i)) != (b & (1 << i))) {
				ans += 1 << i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}