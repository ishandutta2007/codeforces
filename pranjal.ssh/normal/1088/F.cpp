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

int n; const int N = 5e5 + 10;
int a[N], p[20][N], h[N];
vi g[N];
void dfs(int u) {
	for (int v: g[u]) if (v != p[0][u]) {
		p[0][v] = u;
		h[v] = h[u] + 1;
		dfs(v);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i, 1, n) {
		cin >> a[i];
	}	
	FOR (i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	int r = min_element(a+1, a+n+1) - a;
	p[0][r] = r;
	dfs(r);
	ll ans = 0;
	FOR (i, 1, 19) FOR (j, 1, n) p[i][j] = p[i-1][p[i-1][j]];
	FOR (i, 1, n) if (i != r) {
		ans += a[i];
		ll cur = 1e18;
		FOR (d, 0, 19) {
			int par = p[d][i];
			cur = min(cur, (d + 1LL) * a[par]);
			if (par == r) break;
		}
		ans += cur;
	}
	cout << ans;
	
	return 0;
}