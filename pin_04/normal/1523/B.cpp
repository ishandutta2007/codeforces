#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5; 



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
		}


		cout << 3 * n << "\n";

		for (int i = 1; i <= n; i += 2) {
			for (int j = 0; j < 2; j++) {
				cout << 1 << " " << i << " " << i + 1 << "\n";
				cout << 2 << " " << i << " " << i + 1 << "\n";
				cout << 1 << " " << i << " " << i + 1 << "\n";
			}
		}
	}
	return 0;
}