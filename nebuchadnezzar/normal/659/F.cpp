#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define rbend(_x) (_x).rbegin(), (_x).rend()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1005;

int dsu[MAXN * MAXN];
int sz[MAXN * MAXN];
int n, m;
ll k;

int _get_root(int v) {
	return dsu[v] == v ? v : dsu[v] = _get_root(dsu[v]);
}

pii get_root(int x, int y) {
	int tmp = _get_root(x * MAXN + y);
 	return {tmp / MAXN, tmp % MAXN};
}

int unite(int x1, int y1, int x2, int y2) {
 	int num1 = x1 * MAXN + y1;
 	int num2 = x2 * MAXN + y2;
 	int r1 = _get_root(num1);
 	int r2 = _get_root(num2);

 	if (r1 == r2) {
 	 	return 0;
 	}

 	dsu[r1] = r2;
 	sz[r2] += sz[r1];
 	return 0;
}

int field[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool used[MAXN][MAXN];

bool onfield(int x, int y) {
 	return 0 <= x && x < n && 0 <= y && y < m && field[x][y];
}

int dfs(int x, int y, int& rest) {
	if (!rest) {
		return 0;
	}
 	used[x][y] = true;
 	--rest;
 	for (int i = 0; i < 4; ++i) {
 	 	int nx = x + dx[i];
 	 	int ny = y + dy[i];
 	 	if (onfield(nx, ny) && !used[nx][ny]) {
 	 	 	dfs(nx, ny, rest);
 	 	}
 	}
 	return 0;
}

int main() {
	fill(sz, sz + MAXN * MAXN, 1);
	for (int i = 0; i < MAXN * MAXN; ++i) {
	 	dsu[i] = i;
	}
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d%I64d", &n, &m, &k);

	vector<tuple<int, int, int>> inp;
	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
	 	 	int num;
	 	 	scanf("%d", &num);
	 	 	inp.puba(make_tuple(num, i, j));
	 	}
	}

	sort(rbend(inp));

	for (int i = 0; i < n * m; ++i) {
		int h, x, y;
		tie(h, x, y) = inp[i];
		//cerr << h << " " << x << " " << y << endl;
		field[x][y] = 1;
	 	
	 	for (int j = 0; j < 4; ++j) {
	 	 	int nx = x + dx[j];
	 	 	int ny = y + dy[j];
	 	 	if (onfield(nx, ny)) {
	 	 	 	unite(x, y, nx, ny);
	 	 	}
	 	}
	 	
	 	pii p = get_root(x, y);
	 	//cerr << p.ff << " " << p.ss << endl;
	 	if (k % h == 0 && k / h <= sz[p.ff * MAXN + p.ss]) {
	 		int tmp = k / h;
	 	 	dfs(x, y, tmp);
	 	 	cout << "YES\n";
	 	 	for (int i2 = 0; i2 < n; ++i2) {
             	for (int j = 0; j < m; ++j) {
             	 	if (used[i2][j]) {
             	 	 	cout << h << " ";
             	 	} else {
             	 	 	cout << "0 ";
             	 	}
             	}
             	cout << "\n";
            }
            return 0;
	 	}
	}

	cout << "NO\n";

	return 0;
}