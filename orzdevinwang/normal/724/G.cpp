#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int mod = 1e9 + 7;
int n, m, flag, ans, cnt;
int head[N], edge_id;
struct node {
	int to, next; ll val;
} e[M << 1];
void add_edge(int u, int v, ll val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
int siz, Cnt[N];
ll dis[N], G[66];
void George1123AKIOI(ll x) {
	R(i, 60, 0) if((x >> i) & 1) {
		if(!G[i]) G[i] = x, cnt ++;
		x ^= G[i];
	}
}
void dfs(int x) {
	siz ++;
	L(i, 0, 60) if((dis[x] >> i) & 1) Cnt[i] ++;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(dis[v] == -1) dis[v] = (dis[x] ^ e[i].val), dfs(v);
		else George1123AKIOI(dis[x] ^ e[i].val ^ dis[v]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v; ll val; scanf("%d%d%lld", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	fill(dis + 1, dis + n + 1, -1);
	L(i, 1, n) {
		if(dis[i] != -1) continue;
		L(t, 0, 60) G[t] = Cnt[t] = 0;
		dis[i] = cnt = siz = 0, dfs(i);
		L(j, 0, 60) {
			bool ok = 0;
			L(t, 0, 60) if(G[t] & (1LL << j)) ok = 1;
			// cout << j << " : " << ok << endl;
			if(ok == 1) (ans += (1LL << j) % mod * ((1LL << (cnt - 1)) % mod) % mod * (1ll * siz * (siz - 1) / 2 % mod) % mod) %= mod;
			else (ans += (1LL << j) % mod * ((1LL << cnt) % mod) * Cnt[j] % mod * (siz - Cnt[j]) % mod) %= mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}