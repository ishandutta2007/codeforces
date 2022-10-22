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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		bool good = 1;
		for (int i = 0; i < n; ++i) good &= a[i] + b[i] <= x;
		cout << (good ? "Yes" : "No") << "\n";
	}
	return 0;
}