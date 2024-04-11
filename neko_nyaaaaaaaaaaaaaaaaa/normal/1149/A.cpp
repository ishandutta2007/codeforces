#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	int o = 0, t = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 1) o++;
		else t++;
	}

	if (o == 0) {
		while (t--) {
			cout << "2 ";
		}
		return 0;
	} else if (t == 0) {
		while (o--) {
			cout << "1 ";
		}
		return 0;
	} else {
		t--; o--;
		cout << "2 1 ";
		while (t--) {
			cout << "2 ";
		}
		while (o--) {
			cout << "1 ";
		}
	}
	
	return 0;
}