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
		int mn = *min_element(a.begin(), a.end());
		int ans = 0;
		for (int i : a) ans += i > mn;
		cout << ans << "\n";
	}
	return 0;
}