#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 256;
template < int N, int Ne >  struct flows { 
	using F = int; // flow type
	F inf = 1e9;
	int n, s, t; // Remember to assign n, s and t !
	int ehd[N], cur[N], ev[Ne << 1], enx[Ne << 1], eid = 1;
	void clear() {
		eid = 1, memset(ehd, 0, sizeof(ehd));
	}
	F ew[Ne << 1], dis[N];
	void Eadd(int u, int v, F w) {
		++eid, enx[eid] = ehd[u], ew[eid] = w, ev[eid] = v, ehd[u] = eid;
	}
	void add(int u, int v, F w) {
		Eadd(u, v, w), Eadd(v, u, 0);
	}
	bool bfs() {
		queue < int > q;
		L(i, 1, n) dis[i] = inf, cur[i] = ehd[i]; 
		q.push(s), dis[s] = 0;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i = ehd[u]; i; i = enx[i]) if(ew[i] && dis[ev[i]] == inf) {
				dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
			}
		}
		return dis[t] < inf;
	}
	F dfs(int x, F now) {
		if(!now || x == t) return now;
		F res = 0, f;
		for(int i = cur[x]; i; i = enx[i]) {
			cur[x] = i;
			if(ew[i] && dis[ev[i]] == dis[x] + 1) {
				f = dfs(ev[i], min(now, ew[i])), ew[i] -= f, now -= f, ew[i ^ 1] += f, res += f;
				if(!now) break;
			}
		}
		return res;
	}
	F max_flow() {
		F res = 0;
		while(bfs()) res += dfs(s, inf);
		return res;
	}
} ; 

flows < N * N * 2, N * N * 4 > G;

int n, wa[N][N], id[N][N], b[N][N];
int p[N][N], mp[N][N];
inline int P(int x, int y) {
	if(!x) return G.s;
	if(x == n) return G.t;
	return (x - 1) * n + y;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) L(j, 1, n) cin >> wa[i][j], p[wa[i][j]][i] = j;
	L(i, 1, n) L(j, 1, n) mp[i][p[i][j]] = j; 
	L(i, 1, n) L(j, 1, n) cin >> b[wa[i][j]][i];
	L(i, 1, n) L(j, 1, n) b[i][j] ^= 1;
	G.n = n * n, G.s = ++G.n, G.t = ++G.n;
	L(i, 1, n) {
		L(j, 1, n) {
//			cout << p[i][j] << ",";
			G.add(P(i, j), P(i - 1, j), G.inf); 
			G.add(P(i, mp[i][j]), P(i - 1, mp[i - 1][j]), G.inf);
			if(i) G.add(P(i - 1, mp[i][j]), P(i - 1, mp[i - 1][j]), G.inf); 
			if(b[i][j]) G.add(P(i - 1, j), P(i, j), 1);
//			cout << b[i][j] << " ";
		}
//		cout << "\n";
	}
	cout << n - G.max_flow() << "\n"; 
//	G.bfs();
//	L(i, 1, n) {
//		L(j, 1, n) cout << (G.dis[P(i, j)] == G.inf);
//		cout << '\n';
//	}
	return 0;
}