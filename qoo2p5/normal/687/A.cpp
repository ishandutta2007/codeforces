#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9;
const ll LINF = 1e18;

const int N = 1e5 + 123;

int n, m;
vector<int> g[N];
int color[N];
bool bad = false;

int nxt(int c) {
	return c == 1 ? 2 : 1;
}

void dfs(int v) {
	for (int u : g[v]) {
		if (color[u] == 0) {
			color[u] = nxt(color[v]);
			dfs(u);
		} else {
			if (color[u] != nxt(color[v])) {
				bad = true;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) {
			color[i] = 1;
			dfs(i);
		}
	}
	
	if (bad) {
		printf("-1\n");
	} else {
		vector<int> a, b;
		for (int i = 0; i < n; i++) {
			if (color[i] == 1) a.push_back(i + 1);
			else b.push_back(i + 1);
		}
		
		printf("%d\n", sz(a));
		for (int i : a) {
			printf("%d ", i);
		}
		printf("\n");
		
		printf("%d\n", sz(b));
		for (int i : b) {
			printf("%d ", i);
		}
		printf("\n");
	}
}