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
		int n, x;
		cin >> n >> x;
		int ans = 1, large = 2;
		while(large < n) {
			large += x;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}