#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define ull unsigned long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 14;
int n, m, k, c[N], h[N], cnt[N], xc[N];
unordered_map < ll, bool > mp;
inline ll has(int *f) {
	ll ret = 0;
	L(i, 1, n) ret += f[i] - 1, ret *= i;
	return ret;
}
int tnt[N], lst[N], fst[N], f[N], to[N];
void fix(int *f) {
	me(to, 0);
	int ic = 0;
	L(i, 1, n) if(!to[f[i]]) to[f[i]] = ++ic;
	L(i, 1, n) f[i] = to[f[i]];
}
void dfs(int x, int mx) {
	if(x == n + 1) {
		me(cnt, 0);
		L(i, 1, n) cnt[c[i]] += 1;
		L(i, 1, mx) if(cnt[i] & 1) return ;
		int rid = has(c), ns = false;
		if(mp.count(rid)) ns = true;
		L(i, 1, n) lst[c[i]] = i;
		L(col, 1, mx) if(cnt[col] > 2) {
			int v = lst[col];
			L(i, 1, v - 1) 
				if(c[i] == col) {
					L(j, 1, n) xc[j] = c[j];
					xc[i] = xc[v] = n / 2, fix(xc);
					if(mp.count(has(xc))) ns = true; 
				}
		}
		if(ns) tnt[mx] += 1;
		if(ns && !mp.count(rid)) mp[rid] = true; 
		return ;
	}
	R(i, min(mx + 1, n / 2), 1) {
		c[x] = i;
		dfs(x + 1, max(i, mx));
	}
}
int cur, mat[N], G[N], S, ip[N];
void DFS(int u, int v) {
	S ^= 1 << u, S ^= 1 << v;
	mat[u] = v, mat[v] = u;
	if(S) {
		int sx = G[u] & S, sy = G[v] & S, all = sx | sy;
		L(i, 1, n) if(all >> i & 1) L(j, i + 1, n) 
			if(((sx >> i & 1) && (sy >> j & 1)) || ((sx >> j & 1) && (sy >> i & 1))) 
				DFS(i, j);
	} else {
		int nt = 0;
		L(i, 1, n) ip[i] = 0;
		L(i, 1, n) if(!ip[i]) ip[i] = ip[mat[i]] = ++nt;
//		L(i, 1, n) cout << ip[i] << ' ';
//		cout << '\n';
		mp[has(ip)] = true;
	}
	S ^= 1 << u, S ^= 1 << v;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u] |= 1 << v;
		G[v] |= 1 << u;
	}
	S = (1 << (n + 1)) - 2;
	L(i, 1, n) L(j, i + 1, n) if(G[i] >> j & 1 && c[i] == c[j]) DFS(i, j);
	dfs(1, 0);
	ll ns = 0;
	R(i, n / 2, 1) ns += tnt[i], ns *= k - i + 1;
	cout << ns << '\n';
	return 0;
}