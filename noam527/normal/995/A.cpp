#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k;
vector<vector<int>> ans;
int a[4][51];

int trynow() {
	int cnt = 0;
	for (int i = 0; i < n; i++) if (a[1][i] == a[0][i] && a[1][i] != 0) {
		cnt++;
		ans.push_back({ a[1][i], 1, i + 1 });
		a[1][i] = 0;
	}
	for (int i = 0; i < n; i++) if (a[2][i] == a[3][i] && a[2][i] != 0) {
		cnt++;
		ans.push_back({ a[2][i], 4, i + 1 });
		a[2][i] = 0;
	}
	return cnt;
}

void moveall() {
	int r, c, nr, nc;
	for (int i = 0; i < n; i++) {
		if (a[1][i] == 0) {
			r = 1, c = i;
			break;
		}
		if (a[2][i] == 0) {
			r = 2, c = i;
			break;
		}
	}
	if (n > 1) {
		for (int i = 0; i < 2 * n - 1; i++) {
			if (r == 1) {
				if (c == 0) nr = 2, nc = 0;
				else nr = 1, nc = c - 1;
			}
			else {
				if (c == n - 1) nr = 1, nc = n - 1;
				else nr = 2, nc = c + 1;
			}
			if (a[nr][nc] > 0) {
				ans.push_back({ a[nr][nc], r + 1, c + 1 });
				swap(a[r][c], a[nr][nc]);
			}
			r = nr;
			c = nc;
		}
	}
	else {
		if (a[2][0] > 0) {
			ans.push_back({ a[2][0], 2, 1 });
		}
		else if (a[1][0] > 0) {
			ans.push_back({ a[1][0], 3, 1 });
		}
		swap(a[1][0], a[2][0]);
	}
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < 4; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	trynow();
	int b = 1;
	for (int i = 0; i < n; i++) {
		if (a[1][i] == 0 || a[2][i] == 0) b = 0;
	}
	if (b == 1) finish(-1);

	for (int i = 0; i < 2 * n; i++) {
		moveall();
		trynow();
	}
	cout << ans.size() << endl;
	for (const auto &i : ans) cout << i[0] << " " <<  i[1] << " " << i[2] << endl;
}