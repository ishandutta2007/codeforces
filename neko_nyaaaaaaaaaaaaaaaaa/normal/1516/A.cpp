#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, k, t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
	vector<int> a(n, 0);
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	for (int j = 0 ; j < k ; j++) {
		for (int i = 0 ; i < n ; i++) {
			if (a[i] > 0) {
				a[i]--;
				a[n - 1]++;
				break;
			}
		}
	}
	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	}
	return 0;
}