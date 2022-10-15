#include <iostream>

using namespace std;

int a[55], b[55];

int main() {
	int t;
	cin >> t;
	for (int h = 1; h <= t; h++) {
		int n, m;
		cin >> n >> m;
		int nc = 0, mc = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				if (!x) continue;
				if (a[i] != h) {a[i] = h; nc++;}
				if (b[j] != h) {b[j] = h; mc++;}
			}
		}
		n -= nc; m -= mc;
		int u = min(n,m);
		if (u%2 == 0) cout << "Vivek\n";
		else cout << "Ashish\n";
	}
}