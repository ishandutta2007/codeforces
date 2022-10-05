#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, q, a[1000][1000];
set<int> u[1000], l[1000];

void upd(int x, int y) {
	if (a[x][y]) {
		if (y > 0 && a[x][y - 1]) l[x].insert(y - 1);
		if (y < m - 1 && a[x][y + 1]) l[x].insert(y + 1);

		if (x > 0 && a[x - 1][y]) u[y].insert(x - 1);
		if (x < n - 1 && a[x + 1][y]) u[y].insert(x + 1);
	}
	else {
		bool b1 = y > 0 && a[x][y - 1], b2 = y < m - 1 && a[x][y + 1];
		if (b1 != b2) l[x].insert(y);
		if (b1 && y > 1 && a[x][y - 2]) l[x].erase(y - 1);
		if (b2 && y < m - 2 && a[x][y + 2]) l[x].erase(y + 1);
		if (!b1 && !b2) l[x].insert(y);

		b1 = x > 0 && a[x - 1][y], b2 = x < n - 1 && a[x + 1][y];
		if (b1 != b2) u[y].insert(x);
		if (b1 && x > 1 && a[x - 2][y]) u[y].erase(x - 1);
		if (b2 && x < n - 2 && a[x + 2][y]) u[y].insert(x + 1);
		if (!b1 && !b2) u[y].insert(x);
	}
	a[x][y] ^= 1;
}

int up(int x, int y) {
	if (x == 0 || !a[x - 1][y]) return x;
	auto it = u[y].lower_bound(x); it--;
	return *it;
}
int down(int x, int y) {
	if (x < n - 1 && a[x + 1][y]) return *u[y].upper_bound(x);
	return x;
}
int left(int x, int y) {
	if (y == 0 || !a[x][y - 1]) return y;
	auto it = l[x].lower_bound(y); it--;
	return *it;
}
int right(int x, int y) {
	if (y < m - 1 && a[x][y + 1]) return *l[x].upper_bound(y);
	return y;
}

int chkup(int x, int y) {
	if (!a[x][y]) return 0;

	int p1 = y, p2 = y, mx = up(x, y), t1, t2, rtn = x - mx + 1;
	while ((p1 > 0 && a[x][p1 - 1]) || (p2 < m - 1 && a[x][p2 + 1])) {
		t1 = t2 = 2e9;
		if (p1 > 0 && a[x][p1 - 1]) t1 = up(x, p1 - 1);
		if (p2 < m - 1 && a[x][p2 + 1]) t2 = up(x, p2 + 1);
		if (t1 < t2) {
			mx = max(mx, t1);
			p1--;
		}
		else {
			mx = max(mx, t2);
			p2++;
		}
		rtn = max(rtn, (x - mx + 1) * (p2 - p1 + 1));
	}
//	cout << "up rtn " << rtn << endl;
	return rtn;
}

int chkdown(int x, int y) {
	if (!a[x][y]) return 0;

	int p1 = y, p2 = y, mn = down(x, y), t1, t2, rtn = mn - x + 1;
	while ((p1 > 0 && a[x][p1 - 1]) || (p2 < m - 1 && a[x][p2 + 1])) {
		t1 = t2 = -2e9;
		if (p1 > 0 && a[x][p1 - 1]) t1 = down(x, p1 - 1);
		if (p2 < m - 1 && a[x][p2 + 1]) t2 = down(x, p2 + 1);

		if (t1 > t2) {
			mn = min(mn, t1);
			p1--;
		}
		else {
			mn = min(mn, t2);
			p2++;
		}
		rtn = max(rtn, (mn - x + 1) * (p2 - p1 + 1));
	}
//	cout << "down rtn " << rtn << endl;
	return rtn;
}

int chkleft(int x, int y) {
	if (!a[x][y]) return 0;

	int p1 = x, p2 = x, mx = left(x, y), t1, t2, rtn = y - mx + 1;
	while ((p1 > 0 && a[p1 - 1][y]) || (p2 < n - 1 && a[p2 + 1][y])) {
		t1 = t2 = 2e9;
		if (p1 > 0 && a[p1 - 1][y]) t1 = left(p1 - 1, y);
		if (p2 < n - 1 && a[p2 + 1][y]) t2 = left(p2 + 1, y);
//		cout << "t1 " << t1 << " t2 " << t2 << endl;
//		cout << "p2 " << p2 << " p1 " << p1 << endl;
		if (t1 < t2) {
			mx = max(mx, t1);
			p1--;
		}
		else {
			mx = max(mx, t2);
			p2++;
		}
		rtn = max(rtn, (y - mx + 1) * (p2 - p1 + 1));
	}
//	cout << "left rtn " << rtn << endl;
	return rtn;
}

int chkright(int x, int y) {
	if (!a[x][y]) return 0;

	int p1 = x, p2 = x, mn = right(x, y), t1, t2, rtn = mn - y + 1;
	while ((p1 > 0 && a[p1 - 1][y]) || (p2 < n - 1 && a[p2 + 1][y])) {
		t1 = t2 = -2e9;
		if (p1 > 0 && a[p1 - 1][y]) t1 = right(p1 - 1, y);
		if (p2 < n - 1 && a[p2 + 1][y]) t2 = right(p2 + 1, y);

		if (t1 > t2) {
			mn = min(mn, t1);
			p1--;
		}
		else {
			mn = min(mn, t2);
			p2++;
		}
		rtn = max(rtn, (mn - y + 1) * (p2 - p1 + 1));
	}
//	cout << "right rtn " << rtn << endl;
	return rtn;
}

int main() {
	fast;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		if (a[i][0]) l[i].insert(0);
		if (a[i][m - 1]) l[i].insert(m - 1);
		for (int j = 1; j < m - 1; j++)
			if (a[i][j] && (!a[i][j - 1] || !a[i][j + 1])) l[i].insert(j);
	}
	for (int j = 0; j < m; j++) {
		if (a[0][j]) u[j].insert(0);
		if (a[n - 1][j]) u[j].insert(n - 1);
		for (int i = 1; i < n - 1; i++)
			if (a[i][j] && (!a[i - 1][j] || !a[i + 1][j])) u[j].insert(i);
	}

	int p1, p2, p3;
	while (q--) {
		cin >> p1 >> p2 >> p3;
		if (p1 == 1) {
			upd(p2 - 1, p3 - 1);
//			for (int i = 0; i < n; i++) {
//				for (auto &j : l[i]) cout << j << " "; cout << endl;
//			}
//			for (int i = 0; i < m; i++) {
//				for (auto &j : u[i]) cout << j << " "; cout << endl;
//			}
		}
		else {
			cout << max(max(max(chkdown(p2 - 1, p3 - 1), chkleft(p2 - 1, p3 - 1)), chkright(p2 - 1, p3 - 1)), chkup(p2 - 1, p3 - 1)) << endl;
		}
	}
}