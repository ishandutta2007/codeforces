#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int n, m;
vector<int> adj[sz], tadj[sz];
vector<pii> qu;
int cnts[sz], f[sz];
bitset<sz> vis;
vector<int> p;

void dfs1(int src, int prv) {
	f[src] = prv;
	vis[src] = 1;
	for (int x : tadj[src]) {
		if (x == prv || vis[x])continue;
		adj[src].push_back(x);
		adj[x].push_back(src);
		dfs1(x, src);
	}
}

bool dfs2(int src, int goal, int prv) {
	if (src == goal) {
		p.push_back(src + 1);
		return 1;
	}
	for (int x : adj[src]) {
		if (x != prv) {
			if (dfs2(x, goal, src)) {
				p.push_back(src + 1);
				return 1;
			}
		}
	}
	return 0;
}

void tree_solve() {
	for (pii ii : qu) {
		int x = ii.ff, y = ii.ss;
		dfs2(y, x, -1);
		cout << p.size() << '\n';
		for (int z : p)cout << z << ' ';
		cout << '\n';
		p.clear();
	}
}

int main() {
	fast;
	cin >> n >> m;
	foru(i, 0, m) {
		int x, y;
		cin >> x >> y;
		tadj[--x].push_back(--y);
		tadj[y].push_back(x);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cnts[--x]++;
		cnts[--y]++;
		qu.push_back({ x,y });
	}
	int ocnt = 0;
	foru(i, 0, n) {
		if (cnts[i] & 1)ocnt++;
	}
	if (ocnt) {
		cout << "NO\n" << ocnt / 2 << '\n';
		return 0;
	}
	cout << "YES\n";
	dfs1(0, -1);
	tree_solve();
	return 0;
}