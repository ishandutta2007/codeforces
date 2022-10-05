#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int L = 19;

int n, q;
vector<int> a;
//vector<int> p[L];
//vector<int> c[L][L];
int to[300005][L];
int vis[L];
/*
void calc(int x, int y) {
	int p1 = 0, p2 = 0;
	while (p1 < p[x].size() && p2 < p[y].size()) {
		if (p[x][p1] < p[y][p2]) p1++;
		else if (p[x][p1] > p[y][p2]) p2++;
		else {
			c[x][y].push_back(p[x][p1]);
			p1++, p2++;
		}
	}
}

int can(int l, int r, int x, int y) {
	if (x > y) swap(x, y);
	auto it = lower_bound(c[x][y].begin(), c[x][y].end(), l);
	if (it == c[x][y].end() || *it > r) return -1;
	return *it;
}

void dfs(int l, int r, int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < L; i++)
		if (!vis[i] && can(l, r, v, i))
			dfs(l, r, i);
}
*/
struct edge {
	int to, w;
	edge() {}
	edge(int tt, int ww) {
		to = tt;
		w = ww;
	}
	bool operator < (const edge &a) const {
		return w > a.w;
	}
};
struct some {
	int t;
	some(int tt = 0) {
		t = tt;
	}
	bool operator < (const some &a) const {
		return t > a.t;
	}
};

bool bfs(int l, int r) {
	for (int i = 0; i < L; i++) vis[i] = 0;
	priority_queue<some> Q;
	Q.push(l);
	while (Q.size()) {
		int x = Q.top().t;
		Q.pop();
		bool found = false;
		for (int i = 0; i < L; i++)
			if (a[x] & (1 << i)) {
				if (a[r] & (1 << i)) return true;
				if (!vis[i]) found = true;
				vis[i] = 1;
			}
		if (!found) continue;
		for (int i = 0; i < L; i++)
			if (!vis[i] && to[x][i] <= r)
				Q.push(to[x][i]);
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i;
	/*
	for (int b = 0; b < L; b++) {
		for (int i = 0; i < n; i++)
			if (a[i] & (1 << b)) p[b].push_back(i);
	}
	for (int i = 0; i < L; i++) for (int j = i + 1; j < L; j++) calc(i, j);
	*/
	/*
	for (int i = 0; i < n; i++) {
		for (int b1 = 0; b1 < L; b1++) for (int b2 = b1 + 1; b2 < L; b2++)
			if ((a[i] & (1 << b1)) && (a[i] & (1 << b2))) c[b1][b2].push_back(i);
	}
	*/
	for (int i = 0; i < n; i++) for (int b = 0; b < L; b++) to[i][b] = md;
	int lst[L][L];
	for (int i = 0; i < L; i++) for (int j = 0; j < L; j++) lst[i][j] = md;
	for (int i = n - 1; i >= 0; i--) {
		for (int b1 = 0; b1 < L; b1++) for (int b2 = b1 + 1; b2 < L; b2++)
			if ((a[i] & (1 << b1)) && (a[i] & (1 << b2))) lst[b1][b2] = lst[b2][b1] = i;
		for (int st = 0; st < L; st++)
			if (a[i] & (1 << st)) {
				for (int en = 0; en < L; en++)
					to[i][en] = min(to[i][en], lst[st][en]);
			}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (bfs(x, y)) cout << "Shi\n";
		else cout << "Fou\n";
		/*
		for (int i = 0; i < L; i++)
			vis[i] = 0;
		for (int i = 0; i < L; i++)
			if (a[x] & (1 << i)) dfs(x, y, i);
		bool found = false;
		for (int i = 0; !found && i < L; i++)
			if (vis[i] && (a[y] & (1 << i)) > 0) found = true;
		if (found) cout << "Shi\n";
		else cout << "Fou\n";
		*/
	}
}