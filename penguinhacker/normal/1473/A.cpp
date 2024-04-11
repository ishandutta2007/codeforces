#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, d; cin >> n >> d;
		vector<int> a(n); for (int& i : a) cin >> i;
		sort(a.begin(), a.end());
		cout << (min(a.back(), a[0] + a[1]) <= d ? "YES" : "NO") << "\n";
	}
	return 0;
}