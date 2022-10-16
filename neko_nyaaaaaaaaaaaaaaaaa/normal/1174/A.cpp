#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == a[2*n - 1]) {
		cout << "-1";
	} else {
		for (int i: a) {
			cout << i << ' ';
		}
	}

	return 0;
}