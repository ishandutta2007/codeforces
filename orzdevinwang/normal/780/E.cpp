#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
int n, m, k, f[N], tot, now;
int ehd[N], enx[N], ev[N], eid;
void add(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
bool vis[N];
void dfs(int x) {
	vis[x] = 1;
	f[++tot] = x;
	for(int i = ehd[x]; i; i = enx[i]) 
		if(!vis[ev[i]]) dfs(ev[i]), f[++tot] = x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, m) {
		int u ,v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	dfs(1);
	int len1 = tot % k;
	L(i, 1, k - len1) {
		cout << tot / k << " ";
		L(j, 1, tot / k) cout << f[++ now] << " ";
		cout << "\n";
	}
	L(i, 1, len1) {
		cout << tot / k + 1 << " ";
		L(j, 1, tot / k + 1) cout << f[++ now] << " ";
		cout << "\n";
	}
	return 0;
}