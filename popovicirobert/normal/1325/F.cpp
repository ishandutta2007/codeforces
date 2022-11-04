#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXN = (int) 1e5;

vector<int> g[MAXN + 1];
int lvl[MAXN + 1], par[MAXN + 1];
int sq;

void dfs(int nod) {
	lvl[nod] = lvl[par[nod]] + 1;
	for(auto it : g[nod]) {
		if(lvl[it] == 0) {
			par[it] = nod;
			dfs(it);
		}
		else if(lvl[nod] - lvl[it] + 1 >= sq) {
			cout << 2 << "\n" << lvl[nod] - lvl[it] + 1 << "\n";
			int cur = nod;
			while(cur != it) {
				cout << cur << " ";
				cur = par[cur];
			}
			cout << it << " ";
			exit(0);
		}
	}
}

bool ok[MAXN + 1], vis[MAXN + 1];
vector<int> sol;

void dfs1(int nod) {
	vis[nod] = 1;
	int cnt = 0;
	for(auto it : g[nod]) {
		if(vis[it] == 0) {
			dfs1(it);
		}
		cnt += ok[it];
	}
	if(cnt == 0) {
		ok[nod] = 1;
		sol.push_back(nod);
	}
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	sq = 1;
	while(sq * sq < n) {
		sq++;
	}
	for(i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);
	dfs1(1);

	sol.resize(sq);
	cout << 1 << "\n";
	for(auto it : sol) {
		cout << it << " ";
	}

	return 0;
}