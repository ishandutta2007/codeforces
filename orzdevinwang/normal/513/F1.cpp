#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
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
//		cout << u << " " << v << "\n";
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
//		cout << res << "\n";
		return res;
	}
} ; 

const int N = 24, S = N * N;
int n, m, A, B;
int det[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char s[N][N];
struct node {
	int x, y, w;
	int d[N][N];
	void bfs() {
		queue < pair < int, int > > q;
		memset(d, 0x3f, sizeof(d));
		q.push(make_pair(x, y)), d[x][y] = 0;
		while(!q.empty()) {
			int sx = q.front().first, sy = q.front().second;
			q.pop();
			L(i, 0, 3) {
				int px = sx + det[i][0], py = sy + det[i][1];
				if(s[px][py] == '.' && d[px][py] > n * m) 
					d[px][py] = d[sx][sy] + 1, q.push(make_pair(px, py)); 
			}
		}
//		cout << x << " " << y << " : \n";
//		L(i, 1, n) L(j, 1, m) cout << setw(10) << d[i][j] << " \n"[j == m];
	}
} pa[S], pb[S];
flow < S * 3, S * S * 5 > a;
#define P(o, i, j) ((o) * n * m + ((i) - 1) * m + (j) + A + B)
bool check(ll X) {
	a.clear(), a.n = P(1, n, m) + 2, a.s = P(1, n, m) + 1, a.t = P(1, n, m) + 2;
	L(i, 1, n) L(j, 1, m) a.add(P(0, i, j), P(1, i, j), 1);
	L(x, 1, A) {
		a.add(a.s, x, 1);
		L(i, 1, n) L(j, 1, m) 
			if(pa[x].d[i][j] <= n * m && (ll) pa[x].d[i][j] * pa[x].w <= X) 
				 a.add(x, P(0, i, j), 1);	
	}
	L(x, 1, B) {
		a.add(x + A, a.t, 1);
		L(i, 1, n) L(j, 1, m) 
			if(pb[x].d[i][j] <= n * m && (ll) pb[x].d[i][j] * pb[x].w <= X) 
				 a.add(P(1, i, j), x + A, 1);
	}
	return a.max_flow() == A;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m >> A >> B;
	L(i, 1, n) cin >> (s[i] + 1);
	if(abs(A - B) != 1) return cout << "-1\n", 0;
	if(A < B) {
		++A;
		L(i, 1, A) cin >> pa[i].x >> pa[i].y >> pa[i].w;
		L(i, 1, B) cin >> pb[i].x >> pb[i].y >> pb[i].w;
	}
	else {
		++B;
		cin >> pb[B].x >> pb[B].y >> pb[B].w;
		L(i, 1, A) cin >> pa[i].x >> pa[i].y >> pa[i].w;
		L(i, 1, B - 1) cin >> pb[i].x >> pb[i].y >> pb[i].w;
	}
	L(i, 1, A) pa[i].bfs();
	L(i, 1, B) pb[i].bfs();
//	check(100);
	ll l = 0, r = 1e13, ns = -1;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(check(mid)) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ns << "\n";
	return 0;
}