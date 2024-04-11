#include <iostream>

using namespace std;

int a[555];
int b[555];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < a[i-1]) ok = false;
		}
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			if (b[i] == 0) c0 = 1;
			if (b[i] == 1) c1 = 1;
		}
		if (c0 && c1) ok = true;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}