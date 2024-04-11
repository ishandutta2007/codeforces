#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct BipDSU {
	vi p, r, cc;
	int good;
	vector<tuple<int, int*, int>> rb;
	BipDSU(int n = 0): p(n), r(n), cc(n), good(1) {iota(all(p), 0);}
	int get(int x, int id) {
		if (p[x] == x) return p[x];
		int ans = get(p[x], id);
		rb.emplace_back(id, &cc[x], cc[x]);
		cc[x] ^= cc[p[x]];
		rb.emplace_back(id, &p[x], p[x]);
		p[x] = ans;
		return ans;
	}
	int getC(int x) {
		int ans = cc[x];
		while (p[x] != x) x = p[x], ans ^= cc[x];
		return ans;
	}
	void connect(int x, int y, int id) {
		int u = get(x, id), v = get(y, id);
		int xc = getC(x), yc = getC(y);
		if (u == v) {
			if (xc != yc) return;
			rb.emplace_back(id, &good, good);
			good = 0;
			return;
		}
		if (r[u] > r[v]) swap(u, v);
		if (r[u] == r[v]) {
			rb.emplace_back(id, &r[v], r[v]);
			++r[v];
		}
		rb.emplace_back(id, &p[u], p[u]);
		p[u] = v;
		if (xc == yc) {
			rb.emplace_back(id, &cc[u], cc[u]);
			cc[u] ^= 1;
		}
	}
	void rollback(int id) {
		while (!rb.empty()) {
			int x, z; int *y; tie(x, y, z) = rb.back();
			if (x != id) break;
			rb.pop_back();
			*y = z;
		}
	}
};

const int N = 1e5 + 10;
vector<ii> T[4*N+10];
int gg[N];
void upd(int no, int l, int r, int u, int v, int x, int y) {
	if (r < u or l > v) return;
	if (l >= u and r <= v) {
		T[no].emplace_back(x, y);
		return;
	}
	int mid= (l+r)>>1;
	upd(no<<1, l, mid, u, v, x, y);
	upd(no<<1|1,mid+1,r,u,v,x,y);
}

BipDSU ds;
void dfs(int no, int l, int r) {
	for (auto it: T[no]) {
		ds.connect(it.F, it.S, no);
	}
	if (l == r) {
		gg[l] = ds.good;
		ds.rollback(no);
		return;
	}
	int mid = (l+r)>>1;
	dfs(2*no, l, mid);
	dfs(2*no+1, mid+1, r);
	ds.rollback(no);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	map<ii, int> last;
	FOR (i, 1, q) {
		int x, y; cin >> x >> y;
		if (last.count({x, y})) {
			upd(1, 1, q, last[{x, y}], i - 1, x, y);
			last.erase({x, y});
		} else {
			last[{x, y}] = i;
		}
	}
	for (auto it: last) {
		upd(1, 1, q, it.S, q, it.F.F, it.F.S);
	}
	ds = BipDSU(n + 1);
	dfs(1, 1, q);
	FOR (i, 1, q) cout << (gg[i] ? "YES\n" : "NO\n");
	return 0;
}