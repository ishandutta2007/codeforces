#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <cctype>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

struct SCC {
public:
	int n, sccAmt = 0;
	vector<vector<int>> adj, radj, sccAdj, sccList;
	vector<int> scc, times;
	vector<bool> vis;
	SCC(int n, vector<vector<int>> adj) {
		this->n = n;
		this->adj = adj;
		scc.assign(n, -1);
		radj.resize(n);
		vis.assign(n, false);
		for(int i = 0; i < n; i++) {
			for (int x : adj[i])
				radj[x].pb(i);
		}
	}
	void findSCCs() {
		foru(i, 0, n) {
			if (!vis[i])
				dfs1(i);
		}
		fill(vis.begin(), vis.end(), false);
		sccList.resize(n);
		ford(i, n - 1, 0) {
			if (!vis[times[i]])
				dfs2(times[i], sccAmt++);
		}
	}
	void getGraph() {
		sccAdj.resize(sccAmt);
		for (int i = 0; i < n; i++) {
			for (int x : adj[i]) {
				if (scc[x] != scc[i])
					sccAdj[scc[i]].pb(scc[x]);
			}
		}
	}
private:
	void dfs1(int src) {
		vis[src] = 1;
		for (int x : adj[src]) {
			if (!vis[x])
				dfs1(x);
		}
		times.pb(src);
	}
	void dfs2(int src, const int& curscc) {
		vis[src] = 1;
		scc[src] = curscc;
		sccList[curscc].pb(src);
		for (int x : radj[src]) {
			if (!vis[x])
				dfs2(x, curscc);
		}
	}
};

const int sz = 2e5 + 5;
string strs[sz];
SCC* alg;
int n, m, words=0;
map<string, int> ids;
pii scores[sz];
pii dp[sz];

int insert(string& str) {
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); });
	if (ids.find(str) == ids.end())
		ids[str] = words++;
	else
		return ids[str];
	int id = ids[str];
	for (char c : str)
		scores[id].ff += (c == 'r');
	scores[id].ss = str.length();
	return id;
}

int main() {
	fast;
	cin >> m;
	foru(i, 0, m) {
		cin >> strs[i];
		insert(strs[i]);
	}
	cin >> n;
	vector<vector<int>> adj(2*n + m);
	foru(i, 0, n) {
		string tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		int id1 = insert(tmp1), id2 = insert(tmp2);
		adj[id1].pb(id2);
	}
	alg = new SCC(words, adj);
	alg->findSCCs();
	alg->getGraph();
	ford(i, alg->sccAmt - 1, 0) {
		dp[i] = { 1e9,1e9 };
		for (int x : alg->sccList[i])
			dp[i] = min(dp[i], scores[x]);
		for (int x : alg->sccAdj[i])
			dp[i] = min(dp[i], dp[x]);
	}
	pii tot = { 0,0 };
	foru(i, 0, m) {
		ll id = insert(strs[i]);
		pii ii = dp[alg->scc[id]];
		tot.ff += ii.ff;
		tot.ss += ii.ss;
	}
	cout << tot.ff << ' ' << tot.ss << '\n';
	return 0;
}

/*
1
abcdefrrr
3
abcdefrrr abcdefrrrr
abcdefrrrr ra
ra abcdefrrr
*/