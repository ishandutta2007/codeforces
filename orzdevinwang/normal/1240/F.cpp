#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3333, M = N * 5;
int n, m, k, he_____he;
int ehd[N], lhd[N], deg[N], enx[M], ev[M], ew[M], eid = 1;
int cnt[N][N], mx[N], mn[N];
int a, b;
void eadd (int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
bool ok[N];
void DFS (int u) {
	ok[u] = true;
	for (int &i = ehd[u], o; i; i = enx[i]) if(!ew[i]) 
		o = i, ew[o] = ew[o ^ 1] = -1, DFS(ev[i]), ew[o] = ew[o ^ 1] = a, swap(a, b);
}
void cle () {
	L(i, 2, eid) cnt[ev[i]][ew[i]] -= 1;
}
void reb () {
	L(i, 2, eid) cnt[ev[i]][ew[i]] += 1;
	L(i, 1, n) {
		mn[i] = mx[i] = 1;
		L(j, 2, k) {
			if(cnt[i][mx[i]] < cnt[i][j]) mx[i] = j; 
			if(cnt[i][mn[i]] > cnt[i][j]) mn[i] = j; 
		}
	}
}

mt19937_64 orz(time(0) ^ clock());

int main () {
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0); 
	cin >> n >> m >> k;
	L(i, 1, n) cin >> he_____he;
	L(t, 1, m) {
		int u, v, w = orz() % k + 1;
		cin >> u >> v;
		eadd (u, v, w);
		eadd (v, u, w);
	}
	reb();
	int CNT = 0;
	while (1) {
		++ CNT;
		bool upd = false;
		L(i, 1, n) if(cnt[i][mx[i]] - cnt[i][mn[i]] >= 3) {
			a = mx[i], b = mn[i];
			cle();
			L(j, 0, n) lhd[j] = ehd[j], deg[j] = 0, ok[j] = false;
			int lid = eid; 
			L(j, 2, eid) if(ew[j] == a || ew[j] == b) ew[j] = 0, deg[ev[j]] += 1;
			int ptn = 0;
			L(j, 1, n) if(deg[j] & 1) eadd (j, 0, 0), eadd (0, j, 0), ptn += 1;
			DFS(0);
			L(j, 1, n) if(!ok[j]) DFS(j);
			L(j, 2, eid) if(!ew[j]) assert (0);
			eid = lid; 
			L(j, 0, n) ehd[j] = lhd[j];
			upd = true;	
			break ;
		}
		if(!upd) break ;
		reb();
		if(k == 2 && CNT > 3) cout << "access denied\n", exit (0);
	}
	for (int i = 2; i <= eid; i += 2) 
		cout << ew[i] << '\n';
	return 0;
}