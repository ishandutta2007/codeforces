#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> pt;

const int sz = 3e5;
int p[sz], ans[sz], n, k, rt = -1, id[sz], tot[sz];
vector<int> adj[sz], radj[sz], treesons[sz];
vector<vector<int>> lines;
bitset<sz> vis;
queue<int> q;

bool formatLines() {
	foru(i, 0, n) {
		if (adj[i].size() > 1 || radj[i].size() > 1)return 0;
	}
	foru(i, 0, n) {
		if (vis[i])continue;
		int src = i;
		while (radj[src].size() == 1) {
			src = radj[src][0];
			if (src == i)return 0;
		}
		vector<int> crl;
		while (!vis[src]) {
			vis[src] = 1;
			crl.pb(src);
			id[src] = lines.size();
			if (adj[src].size() != 0)src = adj[src][0];
		}
		lines.pb(crl);
	}
	return 1;
}

bool goodLines() {
	vis.reset();
	int lsz = lines.size();
	foru(i, 0, lsz) {
		foru(j, 0, lines[i].size()) {
			vis[lines[i][j]] = 1;
			if (p[lines[i][j]]==-1 || id[p[lines[i][j]]] == id[lines[i][j]]) {
				if (p[lines[i][j]] != -1&&!vis[p[lines[i][j]]])return 0;
			}
			else tot[i]++;
		}
	}
	vis.reset();
	if (tot[id[rt]] != 0)return 0;
	else q.push(id[rt]);
	foru(i, 1, lsz) {
		if (i == id[rt])continue;
		if (!tot[i])q.push(i);
	}
	return 1;
}

int main() {
	fast;
	cin >> n >> k;
	foru(i, 0, n) {
		cin >> p[i]; p[i]--;
		if (p[i] == -1) {
			rt = i;
		}
		else treesons[p[i]].pb(i);
	}
	foru(i, 0, k) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		radj[b].pb(a);
	}
	if (!formatLines() || !goodLines()) {
		cout << 0;
		return 0;
	}
	int ind = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		foru(i, 0, lines[x].size()) {
			ans[ind++] = lines[x][i];
			for (int y : treesons[lines[x][i]]) {
				tot[id[y]]--;
				if (tot[id[y]] == 0)q.push(id[y]);
			}
		}
	}
	if (ind == n) {
		foru(i, 0, n)cout << ans[i] + 1 << ' ';
		cout << '\n';
	}
	else cout << 0;
	return 0;
}