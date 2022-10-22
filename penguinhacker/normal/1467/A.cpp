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
		string ans(n, '9');
		if (n >= 2) ans[1] = '8';
		for (int i = 2; i < n; ++i) {
			ans[i] = ans[i - 1] + 1;
			if (ans[i] > '9') ans[i] -= 10;
		}
		cout << ans << "\n";
	}
	return 0;
}