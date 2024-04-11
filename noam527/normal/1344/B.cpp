#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int n, m;
int a[1005][1005];
int vis[1005][1005] = {};

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && a[x][y] == 1;
}

void dfs(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		if (ok(x + dx[k], y + dy[k]))
			dfs(x + dx[k], y + dy[k]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		char c;
		cin >> c;
		if (c == '.')
			a[i][j] = 0;
		else
			a[i][j] = 1;
	}
	for (int i = 0; i < n; i++) {
		int f = md, l = -md;
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				f = min(f, j);
				l = max(l, j);
			}
		}
		if (f == md) continue;
		for (int j = f; j <= l; j++)
			if (!a[i][j])
				finish(-1);
	}
	for (int j = 0; j < m; j++) {
		int f = md, l = -md;
		for (int i = 0; i < n; i++) {
			if (a[i][j]) {
				f = min(f, i);
				l = max(l, i);
			}
		}
		if (f == md) continue;
		for (int i = f; i <= l; i++)
			if (!a[i][j])
				finish(-1);
	}


	int fr[2] = { 0,0 };
	for (int i = 0; i < n; i++) {
		bool found = false;
		for (int j = 0; j < m; j++)
			if (a[i][j]) {
				found = true;
				break;
			}
		if (!found) fr[0] = 1;
	}
	for (int j = 0; j < m; j++) {
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (a[i][j]) {
				found = true;
				break;
			}
		}
		if (!found) fr[1] = 1;
	}
	if (fr[0] != fr[1]) finish(-1);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !vis[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt << endl;
}