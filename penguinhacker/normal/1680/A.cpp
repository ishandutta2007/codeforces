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
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		cout << min({l1+l2, l2<=l1&&l1<=r2?l1:69696969, l1<=l2&&l2<=r1?l2:69696969}) << "\n";
	}
	return 0;
}