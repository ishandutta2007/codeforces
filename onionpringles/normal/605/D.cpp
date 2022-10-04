#pragma warning(disable:4996)

#include <stdio.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<int, int> pii;

const int N = 101010;
const int BIG = 1010101010;

class Point {
public:
	int a, b, c, d;
	Point(int _a, int _b, int _c, int _d) :a(_a), b(_b), c(_c), d(_d) {};
	Point() {};
};

int vis[N];
int par[N];
Point pts[N];
int sorted[N];

int n;
queue<pii> q;
set<pii> st[N];

int stk[N];
int dist[N];
int sp = -1;

void insert(int i, int j, int y) {
	i++;
	while (i <= n) {
		st[i].insert(mp(y, j));
		i = i + (i&(-i));
	}
	return;
}

void add2q(int x, int y, int par) {
	int l = 0;
	int u = n ;
	while (l != u) {
		int m = (l + u) / 2;
		if (pts[sorted[m]].a > x) u = m;
		else l = m + 1;
	}
	int i = l;
	while (i > 0) {
		auto ite = st[i].upper_bound(mp(y, N));
		for (auto it = st[i].begin(); it != ite; it++) {
			if (vis[it->second]) continue;
			vis[it->second] = 1;
			q.push(mp(it->second,par));
		}
		st[i].erase(st[i].begin(), ite);
		i = i - (i&(-i));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		pts[i] = Point(a, b, c, d);
		sorted[i] = i;
		vis[i] = 0;
		par[i] = -1;
		dist[i] = -1;
	}

	sort(sorted, sorted + n, [&](const int& x, const int& y) {return pts[x].a < pts[y].a; });
	for (int i = 0; i < n; i++) {
		int j = sorted[i];
		insert(i, j, pts[j].b);
	}


	add2q(0, 0, -1);
	while (!q.empty()) {
		auto fr = q.front(); q.pop();
	//	printf("%d %d\n", fr.first, fr.second);
		par[fr.first] = fr.second;
		if (fr.second == -1) dist[fr.first] = 1;
		else dist[fr.first] = dist[fr.second] + 1;
		int nx = pts[fr.first].c;
		int ny = pts[fr.first].d;
		add2q(nx, ny, fr.first);
	}

	if (dist[n - 1] < 0) {
		printf("%d", -1);
		return 0;
	}

	int cur = n - 1;
	for (; cur != -1; cur = par[cur]) {
		stk[++sp] = cur;
	}
	printf("%d\n", dist[n - 1]);
	for (int i = sp; i >= 0; i--) {
		printf("%d ", stk[i]+1);
	}

	return 0;
}


/*#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

#define mp(a,b) make_pair(a,b)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}*/