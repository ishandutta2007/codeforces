#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << max({min(a, b) * min(c, d), min(a, c) * min(b, d), min(a, d) * min(b, c)}) << "\n";
	}
	return 0;
}