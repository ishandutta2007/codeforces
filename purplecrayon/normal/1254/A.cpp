#include <bits/extc++.h>
using namespace std;

string ct = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int r, c, k;
		cin >> r >> c >> k;
		vector<string> g(r);
		int cnt = 0;
		for (string& s : g) {
			cin >> s;
			for (char cc : s) {
				if (cc == 'R')
					cnt++;
			}
		}
		int n = cnt / k;
		int m = cnt % k;
		int cur = 0, kk = 0;
		for (int i = 0; i < r; ++i) {
			if (i & 1) {
				for (int j = c - 1; j >= 0; --j) {
					if (g[i][j] == 'R') cur++;
					g[i][j] = ct[min(k - 1, kk)];
					if (kk < m && cur == n + 1) {
						kk++;
						cur = 0;
					} else if (kk >= m && cur == n) {
						kk++;
						cur = 0;
					}
				}
			} else {
				for (int j = 0; j < c; ++j) {
					if (g[i][j] == 'R') cur++;
					g[i][j] = ct[min(k - 1, kk)];
					if (kk < m && cur == n + 1) {
						kk++;
						cur = 0;
					} else if (kk >= m && cur == n) {
						kk++;
						cur = 0;
					}
				}
			}
		}
		// assert(kk == k);
		// assert(cur == 0);
		// cout << "kk = " << kk << endl;
		for (string s : g) cout << s << '\n';
	}
}