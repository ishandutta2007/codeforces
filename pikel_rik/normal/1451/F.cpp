#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 100 + 5;

int n, m, a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		vector<int> xor_sum(n + m - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				xor_sum[i + j] ^= a[i][j];
			}
		}

		if (*max_element(xor_sum.begin(), xor_sum.end()) == 0) {
			cout << "Jeel\n";
		} else {
			cout << "Ashish\n";
		}
	}
	return 0;
}