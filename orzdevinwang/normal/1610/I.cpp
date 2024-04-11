#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7;
int n, fa[N], dp[N], ret;
vi e[N];
void dfs (int x) {
	for (const int &v : e[x]) if (v != fa[x]) fa[v] = x, dfs (v), dp[x] ^= dp[v] + 1;
}
bool vis[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1), ret = (dp[1] + 1) ^ 1;
	L(i, 1, n) {
		for (int u = i; u && !vis[u]; u = fa[u]) 
			vis[u] = true, ret ^= dp[u] ^ (dp[u] + 1) ^ 1;
		cout << (ret ? 1 : 2);
	}
	return 0;
}