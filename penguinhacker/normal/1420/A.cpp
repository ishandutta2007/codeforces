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
		int last = 2e9;
		bool bad = 1;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			bad &= a < last;
			last = a;
		}
		cout << (!bad ? "YES" : "NO") << "\n";
	}
	return 0;
}