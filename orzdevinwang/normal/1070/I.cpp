#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
template < int N, int Ne >  struct flow { 
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
const int N = 1 << 13;
flow < N, N > a;
int n, m, k, c[N];
vi e[N], ma_ak[N];
void Main () {
	cin >> n >> m >> k;
	a.n = n + m, a.s = ++a.n, a.t = ++a.n;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		a.add (i + n, a.t, 1);
		a.add (u, i + n, 1), ma_ak[u].push_back(a.eid), e[u].push_back(i);
		a.add (v, i + n, 1), ma_ak[v].push_back(a.eid), e[v].push_back(i);
	}
	int sum = 0;
	L(u, 1, n) {
		if(k < sz(e[u])) {
			sum += (sz(e[u]) - k) * 2;
			a.add(a.s, u, (sz(e[u]) - k) * 2); 
		}
	}
	L(i, 1, m) c[i] = 0;
	if(sum == a.max_flow()) {
		int now = 0;
		L(u, 1, n) {
			vi lb;
			L(j, 0, sz(e[u]) - 1) 
				if(a.ew[ma_ak[u][j]]) 
					lb.push_back(e[u][j]);
			for (int i = 0; i < sz(lb); i += 2) 
				c[lb[i]] = c[lb[i + 1]] = ++now;
		}
		L(i, 1, m) if(!c[i]) c[i] = ++now;
	}
	L(i, 1, m) cout << c[i] << ' ';
	cout << '\n';
	L(i, 1, n) e[i].clear (), ma_ak[i].clear ();
	a.clear ();
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}