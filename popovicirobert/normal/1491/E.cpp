#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int MAXN = (int)2e5;

vector<pair<int, int>> g[MAXN + 1];
bool vis[MAXN + 1];

unordered_map<int, bool> fib;
int sz[MAXN + 1];

void dfs_size(int nod, int par) {
	sz[nod] = 1;
	for (auto it : g[nod]) {
		if (vis[it.second] == 0 && it.first != par) {
			dfs_size(it.first, nod);
			sz[nod] += sz[it.first];
		}
	}
}

void dfs(int nod, int par, int& x, int& y, int& id, int tot_sz) {
	for (auto it : g[nod]) {
		if (vis[it.second] == 0 && it.first != par) {
			dfs(it.first, nod, x, y, id, tot_sz);
			if (fib[sz[it.first]] && fib[tot_sz - sz[it.first]]) {
				x = nod;
				y = it.first;
				id = it.second;
			}
		}
	}
}


bool solve(int nod) {
	int x, y;
	int id = 0;
	dfs_size(nod, 0);
	dfs(nod, 0, x, y, id, sz[nod]);

	if (sz[nod] == 1)
		return true;

	if (id == 0 || fib[sz[nod]] == 0)
		return false;

	vis[id] = true;

	return solve(x) & solve(y);
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
		
	int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back({y, i});
    	g[y].push_back({x, i});
    }

    fib[1] = true;
    int a = 1, b = 1;
    while (a + b <= n) {
    	int c = a + b;
    	a = b;
    	b = c;
    	fib[b] = true;
    }

    cout << (solve(1) ? "YES" : "NO");

    return 0;
}