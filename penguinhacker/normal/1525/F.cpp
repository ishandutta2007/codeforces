#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for (int L=0; L<31; ++L) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const int mxN=50;
const ll INF=1e18;
int n, m, k, cur, last[mxN+1][mxN+1];
bool e[mxN][mxN], e2[mxN][mxN];
vector<int> ord;
ll dp[mxN+1][mxN+1];

int solve() {
	Dinic g(2*n+2);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			if (e[i][j])
				g.addEdge(i+1, j+n+1, 1);
		g.addEdge(0, i+1, 1);
		g.addEdge(i+n+1, 2*n+1, 1);
	}
	return n-g.calc(0, 2*n+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		e[u][v]=1;
	}
	cur=solve();
	while(cur<n) {
		bool b=0;
		for (int i=0; i<n; ++i) {
			memcpy(e2, e, sizeof(e));
			int ok=0;
			for (int j=0; j<n; ++j) {
				if (e[i][j]) {
					ok=1;
					e[i][j]=0;
				}
			}
			if (ok) {
				int x=solve();
				assert(cur<=x&&x<=cur+1);
				if (x>cur) {
					cur=x, b=1;
					ord.push_back(i+1);
					break;
				}
				memcpy(e, e2, sizeof(e));
			}
		}
		for (int i=0; i<n; ++i) {
			memcpy(e2, e, sizeof(e));
			int ok=0;
			for (int j=0; j<n; ++j) {
				if (e[j][i]) {
					ok=1;
					e[j][i]=0;
				}
			}
			if (ok) {
				int x=solve();
				assert(cur<=x&&x<=cur+1);
				if (x>cur) {
					cur=x, b=1;
					ord.push_back(-(i+1));
					break;
				}
				memcpy(e, e2, sizeof(e));
			}
		}
		assert(b);
	}
	int need=n-ord.size();
	if (need>k) {
		cout << k << "\n";
		for (int i=0; i<k; ++i)
			cout << "0 ";
		return 0;
	}
	memset(dp, 0xbf, sizeof(dp));
	dp[0][0]=0;
	for (int i=1; i<=k; ++i) {
		ll x, y;
		cin >> x >> y;
		for (int j=0; j<=ord.size(); ++j) {
			if (need+j<=i)
				continue;
			for (int k2=0; k2<=j; ++k2) {
				ll ndp=dp[i-1][k2]+max(0ll, x-(j-k2)*y);
				if (ndp>dp[i][j]) {
					dp[i][j]=ndp;
					last[i][j]=k2;
				}
			}
		}
	}
	ar<ll, 2> best={-1, -1};
	for (int i=1; i<=ord.size(); ++i)
		best=max(best, {dp[k][i], i});
	int cur=best[1];
	vector<int> v;
	for (int i=k; i; --i) {
		v.push_back(cur);
		cur=last[i][cur];
	}
	v.push_back(0);
	reverse(v.begin(), v.end());
	cout << k+v.back() << "\n";
	for (int i=1; i<=k; ++i) {
		for (int j=v[i-1]; j<v[i]; ++j)
			cout << ord[j] << " ";
		cout << 0 << " ";
	}
	return 0;
}