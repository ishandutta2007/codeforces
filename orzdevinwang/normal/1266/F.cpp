#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
using namespace std;
const int N = 5e5 + 7;
void Max(int &x, int y) { if(x < y) x = y;  }
int n, deg[N], Fa[N], f1[N], f2[N], sum[N], mx1[N], mx2[N], up[N], mxs[N], las, u, v;
vector<int> G[N], e[N];
void dfs1(int x) {
	Max(f1[0], deg[x] + 1), mxs[x] = -1e9;
	for(int v : e[x]) if(v ^ Fa[x]) {
		Fa[v] = x, dfs1(v);
		if(mx1[v] + 1 > mx1[x]) mx2[x] = mx1[x], mx1[x] = mx1[v] + 1; else Max(mx2[x], mx1[v] + 1);
	}
}
void dfs2(int x) {
	if(x ^ 1) G[up[x]].push_back(x);
	for(int v : e[x]) if(v ^ Fa[x]) G[mx1[v] + 1].push_back(x);
	for(int v : e[x]) if(v ^ Fa[x]) up[v] = max(up[x], mx1[v] + 1 == mx1[x] ? mx2[x] : mx1[x]) + 1, dfs2(v);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, f1[n] = f2[n] = 1;
	L(i, 1, n - 1)  cin >> u >> v, deg[u] ++, deg[v] ++, e[u].push_back(v), e[v].push_back(u);
	dfs1(1), dfs2(1);
	R(i, n, 1) {
		las = 0;
		for(int t : G[i]) {
			sum[t] ++, Max(mxs[Fa[t]], sum[t]), Max(f2[i], sum[t] + mxs[t] - 2), Max(f2[i], sum[t] + sum[Fa[t]] - 2), Max(f2[i], sum[t]), Max(f1[i - 1], sum[t]);
			if(las != t) Max(f1[i], sum[t]); las = t;
		}
	}
	R(i, n, 1) Max(f1[i - 1], f1[i]), Max(f2[i - 1], f2[i]);
	L(i, 1, n) cout << (i % 2 ? f1[i / 2] : f2[i / 2]) << " ";
	cout << endl;
	return 0;
}