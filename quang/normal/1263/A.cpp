#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int> a(3);
		for (int &u : a) cin >> u;
		sort(a.begin(), a.end());
		int tot = a[0] + a[1] + a[2];
		if (a[2] > a[0] + a[1]) tot = (a[0] + a[1]) * 2;
		if (tot & 1) tot ^= 1;
		cout << tot / 2 << endl;
	}
	return 0;
}