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
		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "-1\n";
			continue;
		}
		int big = *max_element(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			if (a[i] == big) {
				bool b = i > 0 && a[i - 1] < big;
				b |= i + 1 < n && a[i + 1] < big;
				if (b) {
					cout << i + 1 << "\n";
					break;
				}
			}
		}
	}
	return 0;
}