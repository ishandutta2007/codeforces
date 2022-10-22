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
		int a = 0, b = 0;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			a += x == 1;
			b += x == 2;
		}
		if ((a + 2 * b) % 2 == 1) {cout << "NO\n"; continue;}
		cout << ((a + 2 * b) % 4 == 0 || a ? "YES" : "NO") << "\n";
	}
	return 0;
}