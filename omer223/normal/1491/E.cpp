#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
bitset<sz> vis;
int n;
vector<pii> adj[sz];
int fib[sz];
map<int, int> fibmp;
int sub[sz];
pii f[sz];

void precfib() {
	fib[0] = fib[1] = 1;
	fibmp[1] = 1;
	for (int i = 2; fib[i - 1] <= 2e5; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fibmp[fib[i]] = i;
	}
}

void input() {
	cin >> n;
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb({ --y,i });
		adj[y].pb({ x,i });
	}
	precfib();
}

int dfs(int src, int prv, const int& fibser) {
	sub[src] = 1;
	if (prv == -1) 
		f[src] = { -1,-1 };
	int win = -1;
	for (pii ii : adj[src]) {
		if (ii.ff == prv || vis[ii.ss])continue;
		int pos = dfs(ii.ff, src, fibser);
		if (pos != -1)
			win = pos;
		sub[src] += sub[ii.ff];
		f[ii.ff] = { src,ii.ss };
	}
	if (win != -1)
		return win;
	else if (sub[src] == fib[fibser - 1] || sub[src] == fib[fibser - 2])
		return src;
	else
		return -1;
}

bool rec(int fibser, int rt) {
	if (fibser <= 1)return 1;
	//get non isolated root
	int src = dfs(rt, -1, fibser);
	if (src == -1)return 0;
	vis[f[src].ss] = 1;
	int id = fibmp[sub[src]], id2 = fibmp[fib[fibser] - sub[src]];
	int save = f[src].ff;
	return rec(id2, save) && rec(id, src);
}

int main() {
	fast;
	input();
	if (fibmp.find(n) == fibmp.end()) {
		cout << "NO\n";
		return 0;
	}
	cout << (rec(fibmp[n], 0) ? "YES\n" : "NO\n") << '\n';
	return 0;
}