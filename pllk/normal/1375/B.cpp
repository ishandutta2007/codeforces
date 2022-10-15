#include <iostream>

using namespace std;

int n, m;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				int c1 = i == 1 || i == n;
				int c2 = j == 1 || j == m;
				if (c1 && c2 && x > 2) ok = false;
				if ((c1 || c2) && x > 3) ok = false;
				if (x > 4) ok = false;
			}
		}
		if (!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int c1 = i == 1 || i == n;
				int c2 = j == 1 || j == m;
				if (c1 && c2) cout << "2 ";
				else if (c1 || c2) cout << "3 ";
				else cout << "4 ";
			}
			cout << "\n";
		}
	}
}