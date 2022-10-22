#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		int last = 2 * k - n;
		for (int i = 1; i < last; ++i) cout << i << " ";
		for (int i = k; i >= last; --i) cout << i << " ";
		cout << "\n";
	}
	return 0;
}