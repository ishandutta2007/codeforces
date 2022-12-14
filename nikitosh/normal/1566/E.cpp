#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 2e5 + 5;

vi g[N], path;
int cnt[N], st[N];

void dfs(int v, int p) {
	for (int u : g[v])
		if (u != p) {
			dfs(u, v); 
			if (st[u] == 0)
				cnt[v]++;
		}
	if (cnt[v] == 0)
		st[v] = 0;
	else {
		if (v != 0)
			path.pb(cnt[v]);
		st[v] = 1;
	}
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tn;
	cin >> tn;
	forn (tt, tn) {
		int n;
		cin >> n;
		forn (i, n)
			g[i].clear(), cnt[i] = st[i] = 0;
		forn (i, n - 1) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].pb(u), g[u].pb(v);
		}
		path.clear();
		dfs(0, -1);
		int res = (st[0] == 0 ? 1 : cnt[0]);
		for (int k : path)
			res += k - 1;
		cout << res << "\n";
	}
	
	return 0;
}