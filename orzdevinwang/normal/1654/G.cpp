#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 19, mod = 998244353;
int n, l[N], lst[N];
vi e[N], S;
int h[N], fx[N];
bool vis[N], gt[N], xvis[N];
queue < int > q;
vi mS;

int lab[N]; 
int dfs(int x, int fa) {
	int cur = 0, msk = 0, tv;
	for(const int &v : e[x]) if(v != fa) tv = dfs(v, x), msk |= cur & tv, cur |= tv;
	lab[x] = msk ? 32 - __builtin_clz(msk) : 0, lab[x] += __builtin_ctz(~(cur >> lab[x]));
	return (cur >> lab[x] | 1) << lab[x];
}

int rt, dep[N], bk[N], pre[N], cdp[N], xpre[N], xlen[N], mxd; 
vi ele;
void DFS(int x, int fa) {
	ele.emplace_back(x);
	mxd = max(mxd, dep[x] + 1);
	for(const int &v : e[x]) 
		if(v != fa && lab[v] < lab[rt]) {
			dep[v] = dep[x] + 1;
			if(!fa) bk[v] = v;
			else bk[v] = bk[x];
			if(h[v] > h[x]) cdp[v] = pre[v] = -1e9;
			else {
				int len = cdp[x];
				if(h[v] == h[x]) len -= 1;
				else len += 1;
				cdp[v] = len, pre[v] = min(pre[x], len);
			}
			
			if(h[v] < h[x]) xlen[v] = xpre[v] = -1e9;
			else {
				int op = 0;
				if(h[v] == h[x]) op = -1;
				else op = 1;
				xlen[v] = xlen[x] + op, xpre[v] = min(xpre[x] + op, 0);
			}
			
			DFS(v, x);
		}
}
int ns[N];
int bela[N], belb[N], wa[N], wb[N];
void ins(int u, int bk, int h) {
	if(h < wa[u]) {
		if(bk != bela[u]) wb[u] = wa[u], belb[u] = bela[u];
		wa[u] = h, bela[u] = bk;
	} else if(bk != bela[u] && h < wb[u]) wb[u] = h, belb[u] = bk;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	L(i, 1, n) {
		cin >> l[i];
		if(l[i]) q.push(i), vis[i] = xvis[i] = true;
	}
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const int &v : e[u]) 
			if(!vis[v]) 
				q.push(v), h[v] = h[u] + 1, vis[v] = true;
	}
	L(u, 1, n) 
		for(const int &v : e[u]) if(h[u] == h[v])
			gt[u] = true;
	dfs(1, 0);
	
	L(i, 1, n) 
		ns[i] = h[i];
	for(rt = 1; rt <= n; ++rt) {
		ele.clear();
		mxd = 0;
		dep[rt] = 0, cdp[rt] = 0, pre[rt] = xpre[rt] = cdp[rt] = xlen[rt] = 0, DFS(rt, 0);
		bk[rt] = rt, ele.push_back(rt);
		L(i, 0, mxd) bela[i] = belb[i] = 0, wa[i] = 1e9, wb[i] = 1e9;
		
		for(const int &v : ele) 
			if(gt[v] && pre[v] > -n) 
				ins(-pre[v], bk[v], h[v]);
		L(i, 1, mxd) 
			ins(i, bela[i - 1], wa[i - 1]),  
			ins(i, belb[i - 1], wb[i - 1]);
		for(const int &u : ele) if(xpre[u] >= 0) {
			int t = xlen[u];
			if(bela[t] == bk[u]) ns[u] = min(ns[u], wb[t]);
			else ns[u] = min(ns[u], wa[t]);
		} 
//		for(const int &u : ele) if(xpre[u] >= 0)
//			for(const int &v : ele) if(gt[v] && bk[u] != bk[v] && xlen[u] + pre[v] >= 0) 
//				ns[u] = min(ns[u], h[v]);
	}
	L(i, 1, n) 
		cout << h[i] * 2 - ns[i] << ' ';
	return 0;
}