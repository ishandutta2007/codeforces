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
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int sum = accumulate(a.begin(), a.end(), 0);
		sort(a.begin(), a.end());
		if (sum == 0) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (sum > 0) {
			for (int i = n - 1; i >= 0; --i) {
				cout << a[i] << " ";
			}
		}
		else {
			for (int i : a) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}