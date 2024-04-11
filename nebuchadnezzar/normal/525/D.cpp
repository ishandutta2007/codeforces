#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2007;
const int INF = 1e9 + 7;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct rect {
	int x1, y1, x2, y2;
	rect() {
	 	x1 = y1 = INF;
	 	x2 = y2 = -INF;
	}
	rect(int x, int y) {
	 	x1 = x2 = x;
	 	y1 = y2 = y;
	}
	rect(int _x1, int _y1, int _x2, int _y2) {
	 	x1 = _x1;
	 	y1 = _y1;
	 	x2 = _x2;
	 	y2 = _y2;
	}
	bool in(int x, int y) {
	 	return x1 <= x && x <= x2 && y1 <= y && y <= y2;
	}
	bool in(rect r) {
	 	return x1 <= r.x1 && r.x2 <= x2 && y1 <= r.y1 && r.y2 <= y2;
	}
};

rect combine(rect r1, rect r2) {
 	return rect(min(r1.x1, r2.x1), min(r1.y1, r2.y1), max(r1.x2, r2.x2), max(r1.y2, r2.y2));
}

int n, m;
int field[MAXN][MAXN];
pii dsu[MAXN][MAXN];
int sz[MAXN][MAXN];
rect here[MAXN][MAXN];
char s[MAXN];

pii get_root(int x, int y) {
 	return dsu[x][y] == make_pair(x, y) ? make_pair(x, y) : dsu[x][y] = get_root(dsu[x][y].ff, dsu[x][y].ss);
}

int unite(int x1, int y1, int x2, int y2) {
 	pii p1 = get_root(x1, y1);
 	pii p2 = get_root(x2, y2);
 	if (p1 != p2) {
 	 	if (sz[p1.ff][p1.ss] < sz[p2.ff][p2.ss]) {
 	 	 	swap(p1, p2);
 	 	}
 	 	dsu[p2.ff][p2.ss] = p1;
 	 	if (sz[p1.ff][p1.ss] == sz[p2.ff][p2.ss]) {
 	 	 	++sz[p1.ff][p1.ss];
 	 	}
		here[p1.ff][p1.ss] = combine(here[p1.ff][p1.ss], here[p2.ff][p2.ss]);
 	}
 	return 0;
}

bool norm(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
	 	return false;
	}
 	pii tmp = get_root(x, y);
 	rect r = here[tmp.ff][tmp.ss];
 	if (r.x1 == r.x2 && r.y1 == r.y2 && !field[x][y]) {
 	 	return false;
 	}
 	return true;
}

int unite_rects(int x1, int y1, int x2, int y2) {
	pii tmp = get_root(x1, y1);
	rect r1 = here[tmp.ff][tmp.ss];
	pii tmp2 = get_root(x2, y2);
 	rect r2 = here[tmp2.ff][tmp2.ss];
 	if (tmp == tmp2) {
 	 	return 0;
 	}
 	unite(x1, y1, x2, y2);
 	tmp = get_root(x1, y1);
 	rect r = here[tmp.ff][tmp.ss];

 	for (int i = r.x1; i <= r.x2; ++i) {
 		for (int j = r.y1; j <= r.y2; ++j) {
 	 	 	if (r1.in(i, j)) {
 	 	 	 	j = r1.y2;
 	 	 	 	continue;
 	 	 	}
 	 	 	if (r2.in(i, j)) {
 	 	 	 	j = r2.y2;
 	 	 	 	continue;
 	 	 	}
 	 	 	tmp = get_root(i, j);
 	 	 	if (r.in(here[tmp.ff][tmp.ss])) {
 	 	 	 	unite(x1, y1, i, j);
 	 	 	} else {
 	 	 	 	unite_rects(x1, y1, i, j);
 	 	 	}
 	 	}
 	}
 	
 	for (int i = r.x1; i <= r.x2; ++i) {
 	 	if (norm(i, r.y1 - 1)) {
 	 	 	unite_rects(x1, y1, i, r.y1 - 1);
 	 	}
 	 	if (norm(i, r.y2 + 1)) {
 	 	 	unite_rects(x1, y1, i, r.y2 + 1);
 	 	}
 	}

 	for (int j = r.y1; j <= r.y2; ++j) {
 	 	if (norm(r.x1 - 1, j)) {
 	 	 	unite_rects(x1, y1, r.x1 - 1, j);
 	 	}
 	 	if (norm(r.x2 + 1, j)) {
 	 	 	unite_rects(x1, y1, r.x2 + 1, j);
 	 	}
 	}

 	return 0;
}

int ans[MAXN][MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);


	for (int i = 0; i < n; ++i) {
	 	scanf("%s", s);
	 	for (int j = 0; j < m; ++j) {
	 	 	if (s[j] == '.') {
	 	 	 	field[i][j] = 1;
	 	 	}
	 	 	dsu[i][j] = {i, j};
	 	 	sz[i][j] = 1;
	 	 	here[i][j] = rect(i, j);
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
	 	 	if (field[i][j]) {
	 	 	 	for (int k = 0; k < 4; ++k) {
	 	 	 	 	int nx = i + dx[k];
	 	 	 	 	int ny = j + dy[k];
	 	 	 	 	if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny]) {
	 	 	 	 	 	//cerr << "unite " << i << " " << j << " " << nx << " " << ny << endl;
	 	 	 	 	 	unite_rects(i, j, nx, ny);
	 	 	 	 	}
	 	 	 	}
	 	 	}
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
	 	 	if (dsu[i][j] == make_pair(i, j)) {
	 	 		rect r = here[i][j];
	 	 		if (r.x1 == r.x2 && r.y1 == r.y2 && !field[i][j]) {
	 	 		 	continue;
	 	 		}
	 	 	 	for (int x = r.x1; x <= r.x2; ++x) {
	 	 	 	 	for (int y = r.y1; y <= r.y2; ++y) {
	 	 	 	 	 	ans[x][y] = 1;
	 	 	 	 	}
	 	 	 	}
	 	 	}
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
	 	 	cout << "*."[ans[i][j]];
	 	}
	 	cout << "\n";
	}

	return 0;
}