//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 100;
int frm[maxn],
	too[maxn],
	par[maxn],
	deg[maxn],
	mark[maxn],
	flag[maxn],
	n, m, k, last_merge_flag;
vector<pii> vec;

void add(int x, int y) {
	vec.PB(MP(x + 1, y + 1));
}

int root(int u) {
	return par[u] < 0 ? u : par[u] = root(par[u]);
}

bool merge(int u, int v) {
	last_merge_flag = false;
	if ((u = root(u)) == (v = root(v)))
		return false;
	if (par[u] > par[v])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
	last_merge_flag = flag[u] and flag[v];
	flag[u] |= flag[v];
	return true;
}

void print() {
	if (sz(vec) != n - 1)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (auto e : vec)
			cout << e.L << ' ' << e.R << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		frm[i] = fi;
		too[i] = se;
		deg[fi]++;
		deg[se]++;
		if (fi == 0 or se == 0)
			flag[fi^se] = 1;
	}
	for (int i = 0; i < m; i++) if (frm[i] != 0 and too[i] != 0) {
		if (deg[0] <= k and flag[root(frm[i])] and flag[root(too[i])])
			continue;
		if (merge(frm[i], too[i])) {
			deg[0] -= last_merge_flag;
			add(frm[i], too[i]);
		}
	}
	if (deg[0] == k) {
		for (int i = 0; i < m; i++) if (min(frm[i], too[i]) == 0) {
			int v = frm[i] ^ too[i];
			if (!mark[root(v)]) {
				mark[root(v)] = true;
				add(0, v);
			}
		}
	}
	else {
		cout << "NO\n";
		return 0;
	}
	print();
	return 0;
}