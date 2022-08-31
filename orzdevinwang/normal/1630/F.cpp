#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;

template < int N, int Ne >  struct flows { 
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

flows < N, N * 2 > S;

#define P(i, j) (((j) - 1) * n + i)

int n, a[N]; 
int mp[N]; 

void lk (int x, int y) {
	S.add(x, n * 2 + y, 1);
}

void Main () {	
	cin >> n ;
	L(i, 1, n) cin >> a[i], mp[a[i]] = i;
	S.n = n * 4, S.s = ++S.n, S.t = ++S.n;
	L(i, 1, n * 2) S.add(S.s, i, 1), S.add(i + n * 2, S.t, 1); 
	L(i, 1, n) {
		lk (P(i, 1), P(i, 2));
		for (int j = a[i] * 2; j <= 50000; j += a[i]) if(mp[j]) 
			lk (P(i, 1), P(mp[j], 1)), lk (P(i, 2), P(mp[j], 2)), lk (P(i, 1), P(mp[j], 2));
	}
	cout << n - (n * 2 - S.max_flow()) << '\n';
	L(i, 1, n) mp[a[i]] = 0;
	S.clear ();
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}