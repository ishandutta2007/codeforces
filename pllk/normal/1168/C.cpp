#include <iostream>

using namespace std;

#define Z 19

int n, q;
int t[303030];
int d[Z][Z];
int f[303030][Z];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int a = 0; a < Z; a++) {
		for (int b = 0; b < Z; b++) {
			d[a][b] = n+1;
		}
	}
	for (int i = n; i >= 1; i--) {
		int x = t[i];
		for (int a = 0; a < Z; a++) f[i][a] = n+1;
		for (int a = 0; a < Z; a++) {
			if (!(x&(1<<a))) continue;
			for (int b = 0; b < Z; b++) {
				if (x&(1<<b)) {
					f[i][b] = i;
				} else {
					f[i][b] = min(f[i][b],d[a][b]);
				}
			}
		}
		for (int a = 0; a < Z; a++) {
			if (!(x&(1<<a))) continue;
			for (int b = 0; b < Z; b++) {
				if (!(x&(1<<b))) continue;
				d[a][b] = i;
			}
		}
	}
	int u[Z];
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (t[x]&t[y]) {
			cout << "Shi\n";
			continue;
		}
		for (int a = 0; a < Z; a++) {
			u[a] = f[x][a];
		}
		bool ok = false;
		while (true) {
			int ma = -1;
			for (int a = 0; a < Z; a++) {
				if (u[a] > y) continue;
				if (u[a] < u[ma]) ma = a;
			}
			if (ma == -1) break;
			if (t[u[ma]]&t[y]) {
				cout << "Shi\n";
				ok = true;
				break;
			}
			for (int a = 0; a < Z; a++) {
				if (u[a] != n+2) u[a] = min(u[a],f[u[ma]][a]);
			}
			u[ma] = n+2;
		}
		if (!ok) cout << "Fou\n";
	}
}