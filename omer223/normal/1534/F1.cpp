#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

int n, m;

/*
Author: Omer223
Purpose: Finding SCCs in a graph using Kosaraju's algorithm.
Date: 28/03/2021
Confirmed: Yes, https://codeforces.com/contest/467/problem/D
*/
struct SCC { //components sorted in reverse topological order
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
		for (int i = 0; i < n; i++) {
			for (int x : adj[i])
				radj[x].push_back(i);
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
					sccAdj[scc[i]].push_back(scc[x]);
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
		times.push_back(src);
	}
	void dfs2(int src, const int& curscc) {
		vis[src] = 1;
		scc[src] = curscc;
		sccList[curscc].push_back(src);
		for (int x : radj[src]) {
			if (!vis[x])
				dfs2(x, curscc);
		}
	}
};

struct DisjointSet {
	int fcnt;
	vi f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
		}
	}
	int father(int src) {
		if (src == f[src])return src;
		return f[src] = father(f[src]);
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		fcnt--;
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};

int tn(int i, int j) {
    return m * i + j;
}

pii tc(int x) {
    return pii{ x / m,x % m };
}

bool in(int i, int j) {
	return i >= 0 && i < n&& j >= 0 && j < m;
}


int dir[][2]{ {1,0},{0,1},{-1,0},{0,-1} };
vector<vector<bool>> a;

int main() {
    fast;
    cin >> n >> m;
    a.resize(n);
    foru(i, 0, n) {
        a[i].resize(m);
        string s;
        cin >> s;
        foru(j, 0, m)a[i][j] = (s[j] == '#');
    }
    int x;
    foru(i, 0, m)cin >> x;
	int nm = n * m;
	DisjointSet dsu(nm);
	foru(i, 0, n) {
		foru(j, 0, m) {
			foru(r, 0, 4) {
				int mi = i + dir[r][0], mj = j + dir[r][1];
				if (in(mi, mj) && a[i][j] && a[mi][mj])
					dsu.unite(tn(i, j), tn(mi, mj));
			}
		}
	}
	vector<vector<int>> adj(nm);
	vector<int> prv(m, -1);
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (!a[i][j])continue;
			int mc = dsu.father(tn(i, j));
			if (j && prv[j - 1] != -1)adj[prv[j - 1]].push_back(mc);
			if (prv[j] != -1)adj[prv[j]].push_back(mc);
			if (j != m - 1 && prv[j + 1] != -1)adj[prv[j + 1]].push_back(mc);
		}
		foru(j, 0, m) {
			if (a[i][j])prv[j] = dsu.father(tn(i, j));
		}
	}
	SCC scc(nm, adj);
	scc.findSCCs();
	vector<int> u = scc.scc;
	vector<bool> goodscc(nm, false), visadj(nm,false);
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (a[i][j])goodscc[u[dsu.father(tn(i, j))]] = 1;
		}
	}
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (a[i][j]) {
				int cmp = dsu.father(tn(i, j));
				if (visadj[cmp])continue;
				visadj[cmp] = 1;
				for (int y : adj[cmp]) {
					if(u[y]!=u[cmp])goodscc[u[y]] = 0;
				}
			}
		}
	}
	int ret = 0;
	foru(i, 0, nm)ret += goodscc[i];
	cout << ret;
    return 0;
}