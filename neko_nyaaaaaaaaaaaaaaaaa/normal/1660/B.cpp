#include<bits/stdc++.h>

using namespace std;

#define int long long 

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &i: a) cin >> i;

		a.push_back(0);
		sort(a.begin(), a.end());
		n = a.size();
		if (a[n-1] > a[n-2]+1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}