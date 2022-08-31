#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4e5 + 7;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
int n, m, sq, ehd[N], dep[N], ev[N], enx[N], fa[N], eid, Ans[N], tot;
void eadd(int u, int v) {
	ev[++eid] = v, enx[eid] = ehd[u], ehd[u] = eid;
}
bool vis[N], ns[N];
void dfs(int x) {
	vis[x] = true;
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) {
		if(!vis[ev[i]]) fa[ev[i]] = x, dep[ev[i]] = dep[x] + 1, dfs(ev[i]);
		else if(dep[x] - dep[ev[i]] + 1 >= sq) {
			int now = x;
			cout << "2\n" << dep[x] - dep[ev[i]] + 1 << "\n";
			for(; now != ev[i]; now = fa[now]) cout << now << " ";
			cout << now << "\n";
			exit(0);
		}
	}
	if(!ns[x]) {
		ns[x] = true, Ans[++tot] = x;
		if(tot == sq) {
			cout << "1\n";
			L(i, 1, tot) cout << Ans[i] << " ";
			cout << "\n";
			exit(0);
		}
		L(i, 1, sq - 2) x = fa[x], ns[x] = true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, sq = ceil(sqrt(n));
	L(i, 1, m) {
		int u, v;
		cin >> u >> v, eadd(u, v), eadd(v, u);
	}
	dfs(1), assert(0);
	return 0;
}