#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 5e5 + 7;

template < int N, int Ne > struct flows { 
	using F = ll; // flow type
	F inf = 1e18;
	int n, s, t; // Remember to assign n, s and t !
	int ehd[N], cur[N], ev[Ne << 1], enx[Ne << 1], eid = 1;
	void clear() {
		eid = 1, memset(ehd, 0, sizeof(F) * (n + 1));
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

template < int N, int Ne > struct upflows { //  
	using F = ll; // flow type
	F inf = 1e18;
	flows < N, Ne > a;
	int n, s, t;
	F deg[N];
	void clear () {
		L(i, 1, n) deg[i] = 0;
		a.clear();
	}
	void add (int u, int v, F l, F r) {
		r -= l;
		deg[u] += l;
		deg[v] -= l;
		if(r) a.add(u, v, r);
	}
	bool max_flow() {
		a.n = n, a.s = ++a.n, a.t = ++a.n;
		F sum = 0;
		L(i, 1, n) 
			if(deg[i] > 0) a.add(i, a.t, deg[i]), sum += deg[i];
			else a.add(a.s, i, -deg[i]);
		a.add(t, s, inf);
		return sum == a.max_flow();
	}
};

upflows < N, N * 2 > S;

map < int, vector < pair < int, int > > > mp;

vi f[N], ok[N], go[N], ns[N], idx[N];

string b[N];

int n, m; 

inline int P(int x, int y) {
	return (x - 1) * n + y;
}

int dt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char dir[4] = {'D', 'U', 'R', 'L'};

int ed[N][4];

void Main () {	
	mp.clear();
	cin >> n >> m; 
	L(i, 0, n + 1) 
		f[i].clear(), f[i].resize(m + 2), 
		ok[i].clear(), ok[i].resize(m + 2), 
		go[i].clear(), go[i].resize(m + 2), 
		ns[i].clear(), ns[i].resize(m + 2), 
		idx[i].clear(), idx[i].resize(m + 2);
	L(i, 1, n) L(j, 1, m) cin >> f[i][j], mp[f[i][j]].push_back({i, j}); 
	L(i, 1, n) b[i].resize(m);
	for (auto u : mp) {
		int w = u.first;
		auto c = u.second;
		S.clear();
		S.n = 0;
		for (auto p : c) 
			idx[p.first][p.second] = ++S.n;
		S.s = ++S.n, S.t = ++S.n;
		int cntx = 0, cnty = 0;
		for (auto p : c) {
			int i = p.first, j = p.second, tok = 0;
			L(o, 0, 3) {
				int ri = i + dt[o][0], rj = j + dt[o][1];
				if(ri < 1 || ri > n || rj < 1 || rj > m) continue;
				if(f[ri][rj] > w) continue;
				if(ok[ri][rj]) {
					go[i][j] = o;
					tok = 1;
				} else if(!((i + j) & 1)) {
					S.add(idx[i][j], idx[ri][rj], 0, 1); 
					ed[idx[i][j]][o] = S.a.eid;
				}
			}
			if(tok) {
				if((i + j) & 1) S.add(S.s, idx[i][j], 0, 1);
				else S.add(idx[i][j], S.t, 0, 1);
			}
			if((i + j) & 1) cnty += 1, S.add(idx[i][j], S.t, 1, 1);
			else cntx += 1, S.add(S.s, idx[i][j], 1, 1);
		}
		if(!S.max_flow()) {
			cout << "NO\n";
			return ;
		}
		for (auto p : c) {
			int i = p.first, j = p.second;
			if(!((i + j) & 1)) {
				L(o, 0, 3) if(S.a.ew[ed[idx[i][j]][o]]) {
					int ri = i + dt[o][0], rj = j + dt[o][1];
					ns[i][j] = w - 1;
					ns[ri][rj] = 1;
					b[i][j - 1] = dir[o];
					b[ri][rj - 1] = dir[o ^ 1];
				}
			}
		}
		for (auto p : c) {
			int i = p.first, j = p.second;
			if(!ns[i][j]) {
				int o = go[i][j];
				b[i][j - 1] = dir[o], ns[i][j] = f[i][j] - f[i + dt[o][0]][j + dt[o][1]];
			}
		}
		
		L(i, 1, S.n) L(j, 0, 3) ed[i][j] = 0;
		for (auto p : c) 
			ok[p.first][p.second] = true;
	}
	cout << "YES\n";
	L(i, 1, n) L(j, 1, m) cout << ns[i][j] << " \n"[j == m];
	L(i, 1, n) L(j, 0, m - 1) cout << b[i][j] << " \n"[j == m - 1];
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}