#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, m;
int L[202][202], R[202][202];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		L[i][j] = R[i][j] = md;
	for (int i = 0; i < n; i++)
		L[i][i] = R[i][i] = 0;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		--u, --v;
		if (w == 0) {
			L[u][v] = L[v][u] = -1;
			R[u][v] = R[v][u] = 1;
		}
		else {
			L[u][v] = R[u][v] = 1;
			L[v][u] = R[v][u] = -1;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (L[i][k] == md || L[k][j] == md) continue;
				int resL = L[i][k] + L[k][j];
				int resR = R[i][k] + R[k][j];
				if (L[i][j] == md) {
					L[i][j] = resL;
					R[i][j] = resR;
				}
				else {
					if ((L[i][j] - resL) % 2 != 0) {
						cout << "NO\n";
						return;
					}
					L[i][j] = max(L[i][j], resL);
					R[i][j] = min(R[i][j], resR);
					if (L[i][j] > R[i][j]) {
						cout << "NO\n";
						return;
					}
				}
			}
		}
	}
	cout << "YES\n";
	int from = 0, to = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (R[i][j] > R[from][to]) {
			from = i;
			to = j;
		}
	}
	cout << R[from][to] << '\n';
	for (int i = 0; i < n; i++) {
		cout << R[from][i] << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}