#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int res = -1e9;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u < 0) {
			res = max(res, u);
			continue;
		}
		int v = sqrt(u);
		if (v * v != u) {
			res = max(res, u);
		}
	}	
	cout << res << endl;
	return 0;
}