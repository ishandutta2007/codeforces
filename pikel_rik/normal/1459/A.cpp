#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string r, b;
		cin >> r >> b;

		int larger = 0, smaller = 0;
		for (int i = 0; i < n; i++) {
			larger += r[i] > b[i];
			smaller += r[i] < b[i];
		}

		if (larger == smaller) {
			cout << "EQUAL\n";
		} else if (larger > smaller) {
			cout << "RED\n";
		} else {
			cout << "BLUE\n";
		}
	}
	return 0;
}