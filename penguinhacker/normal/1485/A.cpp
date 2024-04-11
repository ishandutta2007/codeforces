#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int a, b; cin >> a >> b;
		int ans = 69696969;
		for (int i = 0; i < 10; ++i) {
			int x = b + i;
			if (x == 1) continue;
			int cur = a;
			int curans = i;
			while(cur > 0) {
				cur /= x;
				++curans;
			}
			ans = min(ans, curans);
		}
		cout << ans << "\n";
	}
	return 0;
}