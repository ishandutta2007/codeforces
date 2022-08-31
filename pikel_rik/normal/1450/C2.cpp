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
				if (a[i][j] != '.') {
					c[(i + j) % 3]++;
				}
			}
		}

		int to_do = max_element(c.begin(), c.end()) - c.begin();

		vector<int> cntx(3), cnto(3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 3 != to_do) {
					if (a[i][j] == 'X') {
						cntx[(i + j) % 3]++;
					} else if (a[i][j] == 'O') {
						cnto[(i + j) % 3]++;
					}
				}
			}
		}

		int to_dox = 0, to_doo = 1, best = 1e6;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != to_do && j != to_do && i != j) {
					if (cntx[i] + cnto[j] < best) {
						to_dox = i;
						to_doo = j;
						best = cntx[i] + cnto[j];
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 3 == to_dox && a[i][j] == 'X') {
					a[i][j] = 'O';
				} else if ((i + j) % 3 == to_doo && a[i][j] == 'O') {
					a[i][j] = 'X';
				}
			}
			cout << a[i] << '\n';
		}
	}
	return 0;
}