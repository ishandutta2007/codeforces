#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(5e5) + 10;

int n, m;
vector<pp> e[maxn];

int si[maxn];

const int mod = int(1e9) + 7;
int p2[maxn];

bitset<maxn> vis;

struct ET {
	int a, b, i;
} et[maxn];
int etn;

int vl[maxn], vln;
void dfs(int x) {
	vis[x] = 1;
	vl[vln++] = x;
	for (auto [y, i]: e[x]) {
		if (x < y) et[etn++] = {x, y, i};
		if (vis[y]) continue;
		dfs(y);
	}
}

ll ansT;
int av[maxn], avn;

int par[maxn];
int root(int x) { return (x == par[x]) ? x : (par[x] = root(par[x])); }

bitset<maxn> tc;

void join(int a, int b) {
	a = root(a); b = root(b);
	par[a] = b;
	if (tc[a]) tc[b] = 1;
}

void work(int r) {
	if (e[r].size() == 0u) {
		if (!si[r]) return;
		ansT += 1;
		av[avn++] = si[r];
		return;
	}

	etn = 0; vln = 0;
	dfs(r);
	bool se = 0;
	rep(i, vln) {
		int v = vl[i];
		if (si[v]) {
			se = 1;
			et[etn++] = {v, v, si[v]};
		}
	}

	ansT += vln - 1 + int(se);

	sort(et, et+etn, [&](const ET& a, const ET& b) {
		return a.i < b.i;
	});

	rep(i, vln) {
		int v = vl[i];
		par[v] = v;
	}

	rep(eti, etn) {
		auto &e = et[eti];
		int a = e.a, b = e.b, i = e.i;
		int ra = root(a), rb = root(b);
		if (a != b) {
			if (tc[ra] != tc[rb]) {
				par[ra] = rb;
				tc[rb] = 1;
				av[avn++] = i;
				continue;
			}
			if (tc[ra] && tc[rb]) continue;
		}

		if (a == b) {
			if (tc[ra]) continue;
			tc[ra] = 1;
			av[avn++] = i;
		} else {
			if (ra != rb) {
				join(ra, rb);
				av[avn++] = i;
			}
		}
	}
}

int main()
{
	cppio();
	cin >> m >> n;
	rrep(i, m) {
		int k; cin >> k;
		if (k == 2) {
			int a, b; cin >> a >> b;
			e[a].eb(b, i);
			e[b].eb(a, i);
		} else {
			int a; cin >> a;
			if (!si[a]) si[a] = i;
		}
	}

	p2[0] = 1;
	int mnm = max(m, n);
	rrep(i, mnm) {
		p2[i] = p2[i-1] * 2;
		if (p2[i] >= mod) p2[i] -= mod;
	}

	rrep(i, n) if (!vis[i]) work(i);

	cout << p2[ansT] << ' ' << avn << '\n';

	sort(av, av+avn);
	rep(ai, avn) {
		cout << av[ai] << ' ';
	}
	cout << '\n';

	return 0;
}