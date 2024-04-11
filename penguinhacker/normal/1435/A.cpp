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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; i += 2) {
			int x = a[i], y = a[i + 1];
			cout << -y << " " << x << " ";
		}
		cout << "\n";
	}
	return 0;
}