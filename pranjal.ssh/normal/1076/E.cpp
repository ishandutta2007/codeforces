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

const int N = 3e5 + 10;
vi g[N];
vector<ii> q[N];
ll val[2*N];
ll ans[N];
ll r = 0;
void dfs(int u, int p, int h) {
	r -= val[h];
	for (auto it: q[u]) {
		r += it.S;
		val[h + it.F + 1] += it.S;
	}
	ans[u] = r;

	for (int v: g[u]) if (v != p) {
		dfs(v, u, h + 1);
	}

	for (auto it: q[u]) {
		r -= it.S;
		val[h + it.F + 1] -= it.S;
	}
	r += val[h];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	FOR (i, 1, n - 1) {
		int x, y;
		cin >> x >>  y;
		g[x].emplace_back(y), g[y].emplace_back(x);
	}
	int m; cin >> m;
	while (m--) {
		int v, d, x; cin >> v >> d >> x;
		d = min(d, n);
		q[v].emplace_back(d, x);
	}
	dfs(1, 0, 0);
	FOR (i, 1, n) cout << ans[i] << " ";
	
	return 0;
}