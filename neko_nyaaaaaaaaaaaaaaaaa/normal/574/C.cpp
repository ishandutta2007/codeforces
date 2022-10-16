#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (a[i] % 2 == 0) {
			a[i] /= 2;
		}
		while (a[i] % 3 == 0) {
			a[i] /= 3;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {cout << "No"; return 0;}
	}
	cout << "Yes";

	return 0;
}