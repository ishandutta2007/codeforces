// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
// #define uint long long
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int tot = 0, goal;
map<uint, int> mp;
struct DPAM {
	int f[5]; 
	uint ha;
} F[1123], Gs, Gab; // orz George1123 ! 
DPAM start() { DPAM res; res.ha = 1, res.f[0] = res.f[1] = res.f[2] = res.f[3] = res.f[4] = 0; return res; }
void Getha(DPAM &P) {
	L(i, 0, 31) {
		int sum = 0;
		L(j, 0, 4) if(i & (1 << j)) sum ^= P.f[j];
		P.ha |= (1LL << sum);
	} 
} 
DPAM Getto(DPAM aa, int bb) {
	R(i, 4, 0) if((bb >> i) & 1) {
		// if(bb >= (1 << (i + 1))) assert(0);
		if(!aa.f[i]) aa.f[i] = bb;
		bb ^= aa.f[i];
	}
	Getha(aa); 
	return aa;
}
int TO[1123][32];
void bfs() {
	queue<int> q;
	q.push(1), mp[1] = ++tot, F[1] = start();
	while(!q.empty()) {
		int u = q.front(); DPAM fu = F[u];
		q.pop();
		L(i, 0, 31) {
			DPAM to = Getto(fu, i);
			if(to.ha == fu.ha) TO[u][i] = 0;
			else {
				if(mp[to.ha]) TO[u][i] = mp[to.ha];
				else {
					mp[to.ha] = TO[u][i] = ++tot, F[tot] = to, q.push(tot);
					if(to.ha == 0u - 1) goal = tot;
				}
			}
		}
	}
}
int sav[1123];
void zy(int *dp, int *savab, DPAM G) {
	L(i, 1, tot) savab[i] = dp[i], sav[i] = 0;
	R(i, 4, 0) if(G.f[i]) {
		// cout << G.f[i] << endl;
		L(j, 1, tot) if(TO[j][G.f[i]]) (sav[TO[j][G.f[i]]] += savab[j]) %= mod;
		L(j, 1, tot) savab[j] = sav[j], sav[j] = 0;
	}
}
int n, m;
int dp[1123], savs[1123], savab[1123];
int head[N], edge_id;
struct node {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
bool to1[N], vis[N]; int dis[N], mat[N], matv[N], toval[N];
bool dfs(int x, int fa, DPAM &f) {
	// cout << "now : " << x << endl;
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == 1 || v == fa || !vis[v]) continue;
		uint now = f.ha;
		// cout << x << " " << v << " : " << (e[i].val ^ dis[x] ^ dis[v]) << endl;
		f = Getto(f, e[i].val ^ dis[x] ^ dis[v]);
		if(now == f.ha) return 0; 
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == 1 || v == fa || vis[v]) continue;
		dis[v] = (dis[x] ^ e[i].val);
		if(!dfs(v, x, f)) return 0;
	}
	return 1;
}
int main() {
	bfs();
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	for(int i = head[1]; i; i = e[i].next) {
		int v = e[i].to;
		to1[v] = 1, toval[v] = e[i].val;
		for(int j = head[v]; j; j = e[j].next) {
			int vto = e[j].to;
			if(to1[vto]) mat[vto] = v, matv[v] = matv[vto] = e[j].val;
		}
	}
	dp[1] = 1;
	for(int t = head[1]; t; t = e[t].next) {
		int v = e[t].to;
		if(mat[v] == -1) continue;
		// cout << v << endl;
		Gs = Gab = start();
		bool flag = dfs(v, -1, Gs), flags;
		L(i, 1, tot) savs[i] = savab[i] = 0; 
		// L(i, 0, 4) savs[i] = savab[i] = 0;
		if(flag) zy(dp, savs, Gs);
		if(!mat[v]) {
			L(i, 1, tot) (dp[i] += savs[i]) %= mod;
			continue;
		}
		Gab = Gs; 
		uint nowab = Gab.ha;
		// cout << "is : " << nowab << endl;
		Gab = Getto(Gab, matv[v] ^ toval[v] ^ toval[mat[v]]);
		// cout << "is : " << Gab.ha << endl;
		// cout << (matv[v] ^ toval[v] ^ toval[mat[v]]) << endl;
		flags = (Gab.ha != nowab);
		if(flag & flags) zy(dp, savab, Gab);//, cout << "QWQ\n";
		// if(!flag || !flags) assert(0);
		// cout << flag << " " << flags << endl;
		// L(i, 1, tot) dp[i] = 3ll * dp[i] % mod, (dp[i] += savab[i]) %= mod;
		L(i, 1, tot) (dp[i] += 2ll * savs[i] % mod) %= mod, (dp[i] += savab[i]) %= mod;
		mat[mat[v]] = -1;
		// int ans = 0;
		// L(i, 1, tot) if(i != goal) (ans += dp[i]) %= mod;
		// cout << "ans = " << ans << endl;
	}
	int ans = 0;
	L(i, 1, tot) (ans += dp[i]) %= mod;
	// L(i, 1, tot) if(i != goal) (ans += dp[i]) %= mod;
	printf("%d\n", ans);
	if(dp[0]) assert(0);
	return 0;
}

/*
3 3
1 2 1
1 3 1
2 3 0
*/