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

const int maxn = 1e6 + 10;
int par[maxn],
	sibl[maxn],
	n;
bool out[maxn],
	 dp[maxn];
string op[maxn];
vector<int> adj[maxn];

bool calc(string o, int u) {
	if (o == "IN")
		return out[u];
	if (o == "NOT")
		return !out[adj[u][0]];
	if (o == "XOR")
		return out[adj[u][0]] ^ out[adj[u][1]];
	if (o == "AND")
		return out[adj[u][0]] & out[adj[u][1]];
	if (o == "OR")
		return out[adj[u][0]] | out[adj[u][1]];
}

void dfs(int u = 0) {
	for (auto v : adj[u])
		dfs(v);
	out[u] = calc(op[u], u);
}

void sfd(int u = 0) {
	if (u == 0)
		dp[u] = true;
	else {
		string o = op[par[u]];
		if (o == "IN" or o == "NOT" or o == "XOR")
			dp[u] = true;
		else if (o == "OR")
			dp[u] = (out[par[u]] == 0) or (out[par[u]] == 1 and out[sibl[u]] == 0);
		else if (o == "AND")
			dp[u] = (out[par[u]] == 1) or (out[par[u]] == 0 and out[sibl[u]] == 1);
	}
	if (dp[u])
		for (auto v : adj[u])
			sfd(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	par[0] = -1;
	for (int i = 0; i < n; i++) {
		int fi, se;
		string ty;
		cin >> ty >> fi;
		op[i] = ty;
		if (ty != "IN") {
			fi--;
			adj[i].PB(fi);
			par[fi] = i;
			if (ty != "NOT") {
				cin >> se, se--;
				adj[i].PB(se);
				par[se] = i;
				sibl[fi] = se;
				sibl[se] = fi;
			}
		}
		else
			out[i] = fi;
	}
	dfs();
	sfd();
	for (int i = 0; i < n; i++)
		if (sz(adj[i]) == 0)
			cout << (out[0] xor dp[i]);
	cout << '\n';
	return 0;
}