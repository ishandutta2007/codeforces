#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> c(3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'X') {
					c[(i + j) % 3]++;
				}
			}
		}

		int to_do = min_element(c.begin(), c.end()) - c.begin();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'X' && (i + j) % 3 == to_do) {
					a[i][j] = 'O';
				}
			}
			cout << a[i] << '\n';
		}
	}
	return 0;
}