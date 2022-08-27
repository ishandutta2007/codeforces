#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
template < int N, int Ne >  struct flows { 
	using F = ll; // flow type
	F inf = 1e18;
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

const int N = 2002, Ne = 5005;
flows < N, Ne > a;
int n, m, x[N], y[N], w[N];
map < ll, int > mp;
ll ns;
ll ha(int x, int y) { return (ll) x * 2000000001 + y; } 
#define P(x, y) ((x) * n + (y))
void adde(int x1, int y1, int x2, int y2) {
	int o1, o2;
	if((o1 = mp[ha(x1, y1)]) && (o2 = mp[ha(x2, y2)]))
		a.add(P(1, o1), P(0, o2), a.inf);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> x[i] >> y[i] >> w[i], mp[ha(x[i], y[i])] = i, a.add(P(0, i), P(1, i), w[i]), ns += w[i];
	a.n = n * 2 + 2, a.s = n * 2 + 1, a.t = n * 2 + 2;
	L(i, 1, n) {
		int op = (!((x[i] - y[i]) & 1)) + (y[i] & 1) * 2;
//		cout << op << "\n";
		if(op == 0) adde(x[i], y[i], x[i] + 1, y[i]), adde(x[i], y[i], x[i] - 1, y[i]);
		if(op == 1) adde(x[i], y[i], x[i], y[i] + 1), adde(x[i], y[i], x[i], y[i] - 1);
		if(op == 2) adde(x[i], y[i], x[i] + 1, y[i]), adde(x[i], y[i], x[i] - 1, y[i]);
		
		if(op == 0) a.add(a.s, P(0, i), a.inf);
		if(op == 3) a.add(P(1, i), a.t, a.inf);
	}
	cout << ns - a.max_flow() << "\n";
	return 0;
}