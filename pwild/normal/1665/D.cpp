#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int g; cin >> g;
	return g;
}

void solve() {
	int c = 0;
	for (int k = 0; k < 30; k++) {
		int p = 1 << k;
		int g = query(p-c, 3*p-c);
		if (g%(2*p) == 0) c += p;
	}
	cout << "! " << c << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}