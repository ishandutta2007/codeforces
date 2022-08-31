#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 2e5 + 7;
int n, m, s, k, a[N];
int f[N][102];
vi e[N];
void dfs1(int x, int fa) {
	for(const int &v : e[x]) if(fa != v) {
		dfs1(v, x);
		L(j, 1, k) 
			f[x][j] = min(f[x][j], f[v][j] + 1);
	}
} 
void dfs2(int x, int fa) {
	for(const int &v : e[x]) if(fa != v) {
		L(j, 1, k) 
			f[v][j] = min(f[v][j], f[x][j] + 1);
		dfs2(v, x);
	}
}
bool vis[N];
void bfs(int c) {
	queue < int > q;
	L(i, 1, n) if(a[i] == c) q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
	 	for(const int &v : e[u]) if(f[v][c] > f[u][c] + 1) 
	 		f[v][c] = f[u][c] + 1, q.push(v);
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> s;
	me(f, 0x3f);
	L(i, 1, n) {
		cin >> a[i];
		f[i][a[i]] = 0;
	}
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	L(i, 1, k) {
		bfs(i);
	}
	L(i, 1, n) {
		ll sum = 0;
		sort(f[i] + 1, f[i] + k + 1);
		L(j, 1, s) sum += f[i][j];
		cout << sum << ' ';
	}
	return 0;
}