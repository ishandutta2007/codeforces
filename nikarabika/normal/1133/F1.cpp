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
	n, m;

void add(int x, int y) {
	cout << x + 1 << ' ' << y + 1 << '\n';
}

int root(int u) {
	return par[u] < 0 ? u : par[u] = root(par[u]);
}

bool merge(int u, int v) {
	if ((u = root(u)) == (v = root(v)))
		return false;
	if (par[u] > par[v])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		frm[i] = fi;
		too[i] = se;
		deg[fi]++;
		deg[se]++;
	}
	int root = max_element(deg, deg + n) - deg;
	for (int i = 0; i < m; i++) if (frm[i] == root or too[i] == root) {
		merge(frm[i], too[i]);
		add(frm[i], too[i]);
	}
	for (int i = 0; i < m; i++)
		if (merge(frm[i], too[i]))
			add(frm[i], too[i]);
	return 0;
}