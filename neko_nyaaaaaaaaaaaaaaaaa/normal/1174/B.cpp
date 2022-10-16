#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	int yes = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if ((a[i] % 2) != (a[0] % 2)) {
			yes = 1;
		}
	}

	if (yes) {
		sort(a.begin(), a.end());
	}

	for (int i: a) cout << i << ' ';

	return 0;
}