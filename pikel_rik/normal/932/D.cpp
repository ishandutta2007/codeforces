#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 4e5 + 5;

int n = 1, w[N];
int up1[N][20], up2[N][20], val1[N][20];
ll val2[N][20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q, last = 0;
	cin >> Q;

	while (Q--) {
		ll t, p, q;
		cin >> t >> p >> q;

		if (t == 1) {
			++n;
			int r = p ^ last;
			w[n] = q ^ last;
			up1[n][0] = r;
			val1[n][0] = w[r];
			for (int i = 1; i < 20; i++) {
				up1[n][i] = up1[up1[n][i - 1]][i - 1];
				int x = val1[n][i - 1], y = val1[up1[n][i - 1]][i - 1];
				val1[n][i] = max(x, y);
			}

			int x = n;
			for (int i = 19; i >= 0; i--) {
				if (up1[x][i] && val1[x][i] < w[n]) {
					x = up1[x][i];
				}
			}

			r = up1[x][0];
			if (r) {
				up2[n][0] = r;
				val2[n][0] = w[r];
				for (int i = 1; i < 20; i++) {
					up2[n][i] = up2[up2[n][i - 1]][i - 1];
					val2[n][i] = val2[n][i - 1] + val2[up2[n][i - 1]][i - 1];
				}
			}
		} else {
			int r = p ^ last;
			ll x = q ^ last;
			if (x < w[r]) {
				last = 0;
			} else {
				x -= w[r];
				last = 0;
				for (int i = 19; i >= 0; i--) {
					if (up2[r][i] && val2[r][i] <= x) {
						last |= (1 << i);
						x -= val2[r][i];
						r = up2[r][i];
					}
				}
				last++;
			}
			cout << last << '\n';
		}
	}
	return 0;
}