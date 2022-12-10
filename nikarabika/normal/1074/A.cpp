//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define smin(x, y) x = min(x, y)

const int maxn = 1e5 + 10;
int q1[maxn];
pii q2[maxn];
int par[maxn];
vector<int> all;
int n, m;

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
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> q1[i];
	q1[n++] = 1000 * 1000 * 1000;
	sort(q1, q1 + n);
	for (int i = 0; i < m; i++) {
		int fi, se, th;
		cin >> fi >> se >> th;
		if (fi != 1) {
			i--, m--;
			continue;
		}
		q2[i] = MP(se, th);
		all.PB(th);
	}
	sort(q2, q2 + m);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	int ans = m;
	int comp = sz(all) + 1;
	int p = 0;
	for (int i = 0; i < n; i++) {
		while (p < m and q2[p].L < q1[i]) {
			int id = p;
			int idx = lower_bound(all(all), q2[id].R) - all.begin();
			comp -= merge(idx, idx + 1);
			p++;
		}
		smin(ans, i + comp - 1);
	}
	cout << ans << endl;
	return 0;
}