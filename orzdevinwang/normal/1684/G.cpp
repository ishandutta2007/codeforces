#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
#define int long long 
using namespace std;
const int N = 1e6 + 7;
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

flows < N, N * 2 > G;
int n, m;
ll a[N];
int s[2007][2007]; 
bool visa[N], visb[N];
signed main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m ;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	vector < ll > va, vb;
	L(i, 1, n) 
		if((ll) a[i] * 3 > m) va.emplace_back(a[i]);
		else vb.emplace_back(a[i]);
	G.n = n, G.s = ++G.n, G.t = ++G.n;
	if(sz(va) > sz(vb)) {
		cout << -1 << '\n';
		return 0;
	}
	L(i, 0, sz(va) - 1) 
		L(j, 0, sz(vb) - 1) 
			if(va[i] % vb[j] == 0 && (ll) va[i] * 2 + vb[j] <= m) 
				G.add(i + 1, j + sz(va) + 1, 1), s[i][j] = G.eid;
	L(i, 0, sz(va) - 1) 
		G.add(G.s, i + 1, 1);
	L(i, 0, sz(vb) - 1) 
		G.add(sz(va) + i + 1, G.t, 1);
	int t = G.max_flow();
//	cout << "t = " << t << endl;
	if(t != sz(va)) 
		return cout << -1 << '\n', 0;
	cout << sz(vb) << '\n';
	L(i, 0, sz(va) - 1) 
		L(j, 0, sz(vb) - 1) 
			if(va[i] % vb[j] == 0 && (ll) va[i] * 2 + vb[j] <= m && G.ew[s[i][j]]) 
				cout << va[i] + vb[j] << ' ' <<	va[i] * 2 + vb[j] << '\n', visa[i] = true, visb[j] = true;
	L(i, 0, sz(vb) - 1) if(!visb[i]) 
		cout << vb[i] * 2 << ' ' << vb[i] * 3 << '\n', assert(vb[i] * 3 <= m);
	return 0;
}

/*
1
1 4
1
*/