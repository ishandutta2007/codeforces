#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n+3);

	for (int i = 2, k = 1; i <= n; i++) {
		if (a[i] == 0) {
			for (int j = i; j <= n; j += i) {
				a[j] = k;
			}
			k++;
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}