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

const int maxn = 2e5 + 10;
int par[maxn],
	frm[maxn],
	too[maxn],
	wei[maxn],
	n, m;
vector<int> edges[maxn],
	all;
int ans;

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
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;
		all.PB(wei[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for (int i = 0; i < m; i++) {
		wei[i] = lower_bound(all(all), wei[i]) - all.begin();
		edges[wei[i]].PB(i);
	}
	for (int i = 0; i < sz(all); i++) {
		for (auto e : edges[i])
			ans += root(frm[e]) != root(too[e]);
		for (auto e : edges[i])
			ans -= merge(frm[e], too[e]);
	}
	cout << ans << endl;
	return 0;
}