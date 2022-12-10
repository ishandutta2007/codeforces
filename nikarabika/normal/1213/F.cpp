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

const int maxn = 2e5 + 10;
char ans[maxn];
bool mark[maxn];
int a[maxn],
	b[maxn],
	n, k;
vector<int> adj[maxn],
	jda[maxn],
	vec[maxn];
stack<int> stc;

void dfs(int u) {
	mark[u] = true;
	for (auto v : adj[u])
		if (!mark[v])
			dfs(v);
	stc.push(u);
}

void sfd(int u, int comp) {
	mark[u] = true;
	vec[comp].PB(u);
	for (auto v : jda[u])
		if (!mark[v])
			sfd(v, comp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	for (int i = 0; i < n; i++)
		cin >> b[i], b[i]--;
	for (int i = 0; i + 1 < n; i++) {
		int u = a[i],
		v = a[i + 1];
		adj[u].PB(v);
		jda[v].PB(u);
	}
	for (int i = 0; i + 1 < n; i++) {
		int u = b[i],
		v = b[i + 1];
		adj[u].PB(v);
		jda[v].PB(u);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i);
	memset(mark, false, sizeof mark);
	int comps = 0;
	while (sz(stc)) {
		int u = stc.top();
		stc.pop();
		if (mark[u])
			continue;
		sfd(u, comps);
		comps++;
	}
	if (comps < k)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < comps; i++) {
			char col = 'a' + min(i, k - 1);
			for (auto u : vec[i])
				ans[u] = col;
		}
		cout << ans << endl;
	}
	return 0;
}