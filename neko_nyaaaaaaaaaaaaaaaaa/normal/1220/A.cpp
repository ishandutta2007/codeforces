#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	int z = 0;
	for (char c: s) {
		z += (c == 'z');
	}
	int o = (n - z*4)/3;
	while (o--) cout << "1 ";
	while (z--) cout << "0 ";

	return 0;
}