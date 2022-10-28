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

vi d;
vector<vi> g;
void dfs(int u) {
	d[u] = 0;
	for (int v: g[u]) {
		g[v].erase(find(all(g[v]), u));
		dfs(v);
		d[u] = max(d[u], d[v] + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	d.resize(n);
	g.resize(n);
	FOR (i, 0, m - 1) {
		int x, y; cin >> x >> y; --x, --y;
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(0);
	int ans = 0;
	FOR (i, 0, n - 1) {
		vi dd{0, 0};
		for (int v: g[i]) {
			dd.push_back(d[v] + 1);
		}
		sort(all(dd)); reverse(all(dd));
		ans = max(ans, dd[0] + dd[1]);
	}
	cout << ans;
	return 0;
}