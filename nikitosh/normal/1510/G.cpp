#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int)((x).size())
#define forn(i,n) for(int i = 0; i < (n); i++)
#define fornr(i,n) for(int i = (n) - 1; i >= 0; --i)
#define forab(i,a,b) for(int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int N = 105;
const int INF = 1e9 + 7;

vi g[N];
int s[N], dp[N][N][2], dpRow[N][N][N][2];
pii par[N][N][N][2];

int dfs(int v) {
	s[v] = 1;
	for(int to : g[v]) {
		s[v] += dfs(to);
	}

	// dpRow[v][ind][k][0/1]
	forn(k, s[v] + 1) {
		dpRow[v][0][k][0] = dpRow[v][0][k][1] = INF;
	}
	dpRow[v][0][0][0] = dpRow[v][0][0][1] = 0;
	dpRow[v][0][1][0] = dpRow[v][0][1][1] = 1;

	int curSize = 1;
	forn(i, sz(g[v])) {
		int to = g[v][i];
		
		forn(k, s[v] + 1) {
			dpRow[v][i + 1][k][0] = dpRow[v][i][k][0];
			par[v][i + 1][k][0] = mp(k, 0);
			dpRow[v][i + 1][k][1] = dpRow[v][i][k][1];
			par[v][i + 1][k][1] = mp(k, 1);
		}
//		dpRow[v][i + 1][0][0] = dpRow[v][i + 1][0][1] = 0;
		dpRow[v][i + 1][1][0] = dpRow[v][i + 1][1][1] = 1;
		for(int k1 = 1; k1 <= curSize; k1++) {
			for(int k2 = 1; k2 <= s[to]; k2++) {
				if (dpRow[v][i + 1][k1 + k2][0] > dpRow[v][i][k1][0] + dp[to][k2][0] + 1) {
					dpRow[v][i + 1][k1 + k2][0] = dpRow[v][i][k1][0] + dp[to][k2][0] + 1;
					par[v][i + 1][k1 + k2][0] = mp(k1, 0);
				}
				if (dpRow[v][i + 1][k1 + k2][1] > dpRow[v][i][k1][1] + dp[to][k2][0] + 1) {
					dpRow[v][i + 1][k1 + k2][1] = dpRow[v][i][k1][1] + dp[to][k2][0] + 1;
					par[v][i + 1][k1 + k2][1] = mp(k1, 1);
				}
				if (dpRow[v][i + 1][k1 + k2][1] > dpRow[v][i][k1][0] + dp[to][k2][1]) {
					dpRow[v][i + 1][k1 + k2][1] = dpRow[v][i][k1][0] + dp[to][k2][1];
					par[v][i + 1][k1 + k2][1] = mp(k1, 0);
				}
				
			}
		}
		curSize += s[to];
	}
	forn(k, s[v] + 1) {
		dp[v][k][0] = dpRow[v][sz(g[v])][k][0];
		dp[v][k][1] = dpRow[v][sz(g[v])][k][1];
	}
/*	cerr << v + 1 << ":\n";
	forn(j, sz(g[v]) + 1) {
		cerr << "---" << j << "---\n";
		forn(i, s[v] + 1) {
			cerr << i << " " << dpRow[v][j][i][0] << " " << dpRow[v][j][i][1] << '\n';
		}
	}
	cerr << '\n';*/
	return s[v];
}

vi path;

void buildAns(int v, int k, int s) {
	if (k == 0) {
		return;
	}
	path.pb(v);
	int ind = sz(g[v]);
	int toGo = -1, toGoK = -1;
	while(ind) {
		if (k <= 1) {
			break;
		}
		int to = g[v][ind - 1];
		auto [k1, ss] = par[v][ind][k][s];
		if (k - k1) {
			if (s == 1 && ss == 0) {
				toGo = to;
				toGoK = k - k1;
			} else {
				buildAns(to, k - k1, 0);
				path.pb(v);
			}
		}
		k = k1;
		s = ss;
		ind--;
	}
	if (toGo != -1) {
		buildAns(toGo, toGoK, 1);
	}
}

int pp[N];
set<int> visited;

void checkPath(int i) {
	if (i == sz(path)) {
		return;
	}
	int v = path[i];
	visited.insert(v);
	if (i) {
		int u = path[i - 1];
		assert(pp[u] == v || pp[v] == u);
	}
	checkPath(i + 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		int k;
		cin >> n >> k;
		forn(i, n) {
			g[i].clear();
		}
		forn(i, n - 1) {
			int v;
			cin >> v;
			v--;
			pp[i + 1] = v;
			g[v].pb(i + 1);
		}
		dfs(0);
		path.clear();
		
		buildAns(0, k, 1);
		cout << sz(path) - 1 << '\n';
		for(int x : path) cout << x + 1 << " ";
		cout << '\n';
		
		
		
/*		int res = dp[0][k][1];
		assert(res <= dp[0][k][0]);
		assert(sz(path) == res);
		visited.clear();
		checkPath(0);
	//	cerr << sz(visited) << " " << k << '\n';
		assert(sz(visited) == k);*/
	}
	return 0;
}