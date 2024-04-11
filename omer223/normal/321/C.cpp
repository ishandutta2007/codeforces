#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

const int sz = 3e5 + 1;
char ans[sz];

struct CentroidDecomposition {
private:
	vector<vector<int>> adj, cadj;
	int n, head;
	bitset<sz> CHECKMYSIZE;
	vector<int> subtree;
	void dfs(int src, int prev) {
		subtree[src] = 1;
		for (auto x : adj[src]) {
			if (x == prev || CHECKMYSIZE[x])continue;
			dfs(x, src);
			subtree[src] += subtree[x];
		}
	}
	int findCentroid(int src, int prev, int treesz) {
		bool bad = 0;
		int s = 0;
		for (auto x : adj[src]) {
			if (x == prev || CHECKMYSIZE[x])continue;
			bad |= (subtree[x] > treesz / 2);
			s += subtree[x];
		}
		bad |= (treesz - s - 1 > treesz / 2);
		if (!bad)return src;
		int potential;
		for (auto x : adj[src]) {
			if (x == prev || CHECKMYSIZE[x])continue;
			potential = findCentroid(x, src, treesz);
			if (potential != -1)return potential;
		}
		return -1;
	}
	int construct(int src) {
		dfs(src, -1);
		int c = findCentroid(src, -1, subtree[src]);
		CHECKMYSIZE[c] = 1;
		for (auto x : adj[c]) {
			if (CHECKMYSIZE[x])continue;
			int p = construct(x);
			cadj[c].pb(p);
			cadj[p].pb(c);
		}
		return c;
	}
public:
	CentroidDecomposition(vector<vector<int>> myadj) {
		n = myadj.size();
		adj = myadj;
		cadj.resize(n);
		subtree.resize(n);
		fill(subtree.begin(), subtree.end(), 0);
		head = construct(0);
		CHECKMYSIZE.reset();
	}
	void scan() {
		scanUtil(head, -1, 0);
	}
	void scanUtil(int src, int prev, int rk) {
		ans[src] = 'A' + rk;
		CHECKMYSIZE[src] = 1;
		for (auto x : cadj[src]) {
			if (x == prev || CHECKMYSIZE[x])continue;
			scanUtil(x, src, rk + 1);
		}
	}
};

int main() {
	fast;
	int n, a, b;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	CentroidDecomposition c(adj);
	c.scan();
	for (int i = 0; i < n; i++)cout << ans[i] << " ";
	cout << endl;
	return 0;
}