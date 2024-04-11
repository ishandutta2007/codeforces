#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool ok = true;
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			int ua, ub;
			cin >> ua >> ub;
			if (ua < a || ub < b) ok = false;
			if (ua-a < ub-b) ok = false;
			a = ua; b = ub;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}