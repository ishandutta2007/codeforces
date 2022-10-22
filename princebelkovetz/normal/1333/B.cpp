#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, f, k;
		bool ch = true;
		cin >> n;
		f = n;
		k = n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1) {
				k = min(k, i);
			}
			else if (a[i] == -1) {
				f = min(i, f);
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		if (a[0] != b[0]) {
			ch = false;
		}
		for (int i = 1; i < n; i++) {
			if (b[i] > a[i] and k >= i) {
				ch = false;
				break;
			}
			else if (b[i] < a[i] and f >= i) {
				ch = false;
				break;
			}
		}
		if (ch) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}

	return 0;
}