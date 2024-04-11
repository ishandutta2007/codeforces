/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int const N = 10000;

bool was[10][10];
int a[N], b[N];
int z[10];
int ans;
int m;

void go(int v, int n) {
	if (v == n) {
		for (int i = 1; i <= 6; i++) {
			for (int j = i; j <= 6; j++) {
				was[i][j] = false;
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++) {
			int from = z[a[i]];
			int to = z[b[i]];
			if (from > to) swap(from, to);
			if (!was[from][to]) {
				was[from][to] = true;
				count++;
			}
		}
		ans = max(ans, count);
		return;
	}
	for (int x = 1; x <= 6; x++) {
		z[v] = x;
		go(v + 1, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}
	ans = 0;
	go(0, n);
	cout << ans << endl;
}