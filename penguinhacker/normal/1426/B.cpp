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
		int n, m;
		cin >> n >> m;
		bool good = 0;
		for (int i = 0; i < n; ++i) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			good |= b == c;
		}
		cout << (m % 2 == 0 && good ? "YES" : "NO") << "\n";
	}
	return 0;
}