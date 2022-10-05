#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int N = 505;

int n, m, k;
int H[N][N], V[N][N];
int res[11][N][N];

void solve() {
	cin >> n >> m >> k;
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << "-1 ";
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			cin >> H[i][j];
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> V[i][j];
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[0][i][j] = 0;
	for (int x = 1; x <= k / 2; x++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int z = md;
				if (i > 0) z = min(z, res[x - 1][i - 1][j] + V[i - 1][j]);
				if (i + 1 < n) z = min(z, res[x - 1][i + 1][j] + V[i][j]);
				if (j > 0) z = min(z, res[x - 1][i][j - 1] + H[i][j - 1]);
				if (j + 1 < m) z = min(z, res[x - 1][i][j + 1] + H[i][j]);
				res[x][i][j] = z;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << 2 * res[k / 2][i][j] << " ";
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}