#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
int n, dp[N], cnt[N], fa[N], fae[N]; 

vi fp[N][2];

vi G[N];
int deg[N];
void lk(int u, int v) { // u is earlier than v
	G[u].emplace_back(v), deg[v] += 1;
}

int ehd[N], ev[N], enx[N], eid;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
} 
bool okk;
void dfs(int x) {
	int v = 0;
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) 
		fa[ev[i]] = x, fae[ev[i]] = i >> 1, dfs(ev[i]), v += !dp[ev[i]];
	int z = (cnt[x] + 1) / 2 - v;
	if(z < 0 || z > 1) return okk = false, void(); 
	dp[x] = !z;
}

int col[N];
void print(int x, int op) {
	vi cm[2];
	L(i, 1, cnt[x]) cm[(cnt[x] - i) & 1].emplace_back(i);
	vi rnt;
	col[cm[op].back()] = fae[x], cm[op].pop_back();
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) 
		col[cm[dp[ev[i]]].back()] = i >> 1, cm[dp[ev[i]]].pop_back();
	L(i, 1, cnt[x] - 1) lk(col[i], col[i + 1]);
	vi COL(cnt[x] + 1);
	L(i, 1, cnt[x]) COL[i] = col[i];
	L(i, 1, cnt[x]) if(COL[i] != fae[x]) {
		int t = COL[i], tr = ev[t * 2 + 1] ^ ev[t * 2] ^ x;
		print(tr, (cnt[x] - i) & 1);
	}
}

void topo() {
	queue < int > q;
	L(i, 1, n - 1) 
		if(!deg[i]) 
			q.push(i);
	while(!q.empty()) {
		int u = q.front();
		cout << ev[u * 2] << ' ' << ev[u * 2 + 1] << '\n';
		q.pop();
		for(const int &v : G[u]) {
			deg[v] -= 1;
			if(!deg[v]) q.push(v);
		}
	}
	L(i, 1, n) G[i].clear(), deg[i] = 0;
}

void Main () {
	cin >> n;
	L(i, 1, n) dp[i] = 0, ehd[i] = 0, cnt[i] = 0;
	eid = 1, okk = true;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		cnt[u] += 1, cnt[v] += 1;
		eadd(u, v);
		eadd(v, u);
	}
	int rt = 0;
	L(i, 1, n) if(!enx[ehd[i]]) rt = i;
	int xto = ev[ehd[rt]];
	fa[xto] = rt, fae[xto] = ehd[rt] >> 1, dfs(xto);
	if(okk && dp[xto] == 0) {
		cout << "YES\n";
		print(xto, 0);
		topo();
	} else {
		cout << "NO\n";
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}