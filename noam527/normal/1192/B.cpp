#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int K = 3, eff[3] = { 1, -2, 1 };

struct block {
	ll dp[K][K];
	block() {
		for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) dp[i][j] = -inf;
	}
	block(ll x) {
		for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) dp[i][j] = -inf;
		for (int i = 0, sum; i < K; i++) {
			sum = 0;
			for (int j = i; j < K; j++) {
				sum += eff[j];
				dp[i][j] = sum * x;
			}
		}
	}
	void push(ll x) {
		for (int i = 0, sum; i < K; i++) {
			sum = 0;
			for (int j = i; j < K; j++) {
				sum += eff[j];
				dp[i][j] += sum * x;
			}
		}
	}
};
block operator * (const block &a, const block &b) {
	block rtn;
	for (int i = 0; i < K; i++) for (int j = i; j < K; j++) {
		rtn.dp[i][j] = max(a.dp[i][j], b.dp[i][j]);
		for (int k = i; k < j; k++)
			rtn.dp[i][j] = max(rtn.dp[i][j], a.dp[i][k] + b.dp[k + 1][j]);
	}
	return rtn;
}

struct segtree {
	int n;
	vector<block> t;
	vector<ll> tag;
	segtree() {}
	segtree(const vector<ll> &a) {
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n);
		tag.resize(2 * n, 0);
		for (int i = 0; i < a.size(); i++)
			t[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--)
			t[i] = t[i + i + 1] * t[i + i + 2];
	}
	void push(int x) {
		if (!tag[x]) return;
		t[x].push(tag[x]);
		if (x < n - 1) {
			tag[x + x + 1] += tag[x];
			tag[x + x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(x + x + 1), push(x + x + 2);
		t[x] = t[x + x + 1] * t[x + x + 2];
	}
	void upd(int l, int r, ll v) {
		upd(l, r, v, 0, 0, n - 1);
	}
	void upd(int l, int r, ll v, int node, int nl, int nr) {
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] += v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		upd(l, r, v, 2 * node + 1, nl, mid);
		upd(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	ll query() {
		push(0);
		return t[0].dp[0][K - 1];
	}
};

struct edge {
	int to;
	ll w;
	edge() {}
	edge(int tt, ll ww) {
		to = tt;
		w = ww;
	}
};

int n, q;
ll w;
vector<edge> e;
vector<vector<int>> g;
vector<int> par;
ll dp[100005][2];

int st[100005], en[100005], tim = 0;
vector<ll> initw;
segtree T;

ll LAST = 0;

void answer(ll X) {
	cout << (LAST = X) << '\n';
}
void encode(int &ind, ll &nw) {
	ind = 2 * ((ind + LAST) % (n - 1));
	nw = (nw + LAST) % w;
}
int dfs(int v, int pre, ll W = 0) {
	par[v] = pre;
	int rtn = 0;
	initw[tim] = W;
	st[v] = tim++;
	for (const auto &i : g[v])
		if (e[i].to != pre) {
			rtn = max(rtn, 1 + dfs(e[i].to, v, W + e[i].w));
			initw[tim++] = W;
		}
	for (int i = 0; i < g[v].size(); i++)
		if (e[g[v][i]].to == pre) {
			swap(g[v].back(), g[v][i]);
			g[v].pop_back();
			break;
		}
	en[v] = tim - 1;
	initw[tim - 1] = W;
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> q >> w;
	g.resize(n);
	par.resize(n);
	initw.resize(2 * n - 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll ww;
		cin >> u >> v >> ww;
		--u, --v;
		g[u].push_back(e.size());
		e.push_back(edge(v, ww));
		g[v].push_back(e.size());
		e.push_back(edge(u, ww));
	}
	dfs(0, 0);
	int eind;
	ll nw;
	T = segtree(initw);

	while (q--) {
		cin >> eind >> nw;
		encode(eind, nw);
		if (OO) cout << "real query " << eind / 2 << " " << nw << '\n';
		ll diff = nw - e[eind].w;
		e[eind].w = nw;
		int nl, nr;
		if (par[e[eind].to] == e[eind + 1].to)
			nl = st[e[eind].to], nr = en[e[eind].to];
		else
			nl = st[e[eind + 1].to], nr = en[e[eind + 1].to];
		if (OO) cout << "updating " << nl << " " << nr << " " << diff << '\n';
		T.upd(nl, nr, diff);
		answer(T.query());
	}
}