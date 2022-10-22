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
		int l, r;
		cin >> l >> r;
		int x = r / 2 + 1;
		cout << (l >= x ? "YES" : "NO") << "\n";
	}
	return 0;
}