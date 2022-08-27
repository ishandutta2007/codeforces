#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 1e3 + 7, mod = 998244353;
int n, m;
struct pqt { 
	int op [N], siz [N], tot, rt;
	
	/* 
		op = 0 : P
		op = 1 : Q
	*/
	
	vi son[N];
	
	void init (int x = -1) {
		if(x != -1) n = x;
		tot = n, rt = ++tot;
		L(i, 1, n) son[rt].push_back(i);
	}
	
	bool vis [N];
	int count[N], ops[N];
	int GV (int x) { return count[x] ? (count[x] == siz[x] ? 2 : 1) : 0; }
	
	void dfs1 (int x) {
		if (x <= n) return count[x] = vis[x], siz[x] = 1, ops[x] = vis[x] ? 2 : 1, void ();
		count [x] = siz[x] = ops[x] = 0;
		for (int v : son[x]) dfs1 (v), count[x] += count[v], siz[x] += siz[v], ops[x] |= ops[v];
	}
	
	bool isok;
	int dfs2 (int x, int lim) { // lim = 0 : no limits; lim = 1 : 1left; lim = 2 : 1right
		if (ops[x] != 3) return x;
//		cout << x << " " << lim << "\n";
		vi a[3]; 
		for (int v : son[x]) a[GV(v)].push_back(v); 
		if (sz(a[1]) > 2 || (lim && sz(a[1]) == 2)) isok = false; 
		if(!lim) {
			L(i, 0, sz(son[x]) - 1) if(count[son[x][i]] == count[x]) 
				return son[x][i] = dfs2 (son[x][i], 0), x;
		}
		if (!op[x]) {	
			int ct = -1, rx = -1;
			if (sz(a[2]) == 1) ct = a[2][0];
			else if (sz(a[2]) > 1) ct = ++tot, op[ct] = 0, son[ct] = a[2]; 
			vi t;
			if (sz(a[1])) {
				rx = dfs2 (a[1][0], 2);
				for(int v : son[rx]) t.push_back(v);
			} 
			if (~ct) t.push_back(ct); 
			if (sz(a[1]) > 1) {
				rx = dfs2 (a[1][1], 1);
				for(int v : son[rx]) t.push_back(v);
			} 
			if(!sz(a[0])) {
				if(lim == 1) reverse(t.begin(), t.end());
				op[x] = 1, son[x] = t;
				return x;
			} 
			int px = t[0];
			if (sz(t) > 1) px = ++ tot, son[px] = t, op[px] = 1;
			if(lim) {
				son[x].clear(), op[x] = 1;
				int zer = a[0][0];
				if(sz(a[0]) > 1) zer = ++tot, op[zer] = 0, son[zer] = a[0];
				son[x].push_back(zer);
				for(int v : t) son[x].push_back(v);  
				if(lim == 1) reverse(son[x].begin(), son[x].end()); //, cout << "FYY66666 " << x << '\n'; 
			} else son[x] = a[0], son[x].push_back(px);
		} else {
			int cnt = 0;
			vi t;
			if(GV(son[x][0]) == 2 || GV(son[x][sz(son[x]) - 1]) == 0) reverse(son[x].begin(), son[x].end());
//			if(lim && !GV(son[x][0])) isok = false;
//			cout << "lim = " << lim << " : ";
//			for(int v : son[x]) 
//				cout << GV(v) << ",, ";
//			cout << "\n";
			for(int v : son[x]) {
				int w = GV (v);
				if(w == 1) {
					if (cnt == 2) isok = false; 
					++ cnt; 
					int z = dfs2 (v, 3 - cnt); 
					for(int p : son[z]) t.push_back(p);
				} else if(w == 2) {
					t.push_back(v);
					if (cnt == 0) cnt = 1;
					if (cnt == 2) isok = false; 
				} else {
					t.push_back(v);
					if(cnt == 1) cnt = 2;
				}
			} 
			if (lim && cnt == 2) isok = false; 
			if (lim == 1) reverse(t.begin(), t.end()); //, cout << "66666fyy " << x << "\n";
			son[x] = t;
		}
		return x;
	}
	
	bool insert (vi r) {
		L(i, 1, n) vis[i] = false;
		for(const int &x : r) vis[x] = true;
		dfs1 (rt), isok = true, rt = dfs2(rt, 0);
		return isok;
	}
	
	vi ns;
	void output (int x) {
		if (x <= n) return ns.push_back(x), void (); 
		cout << x << " : " << op[x] << "\n";
		for(int v : son[x]) cout << x << " " << v << "\n";
		for(int v : son[x]) output (v); 
	}
	int get (int x) {
		if(x <= n) return 1;
		int res = 1;
		if(op[x] == 0) L(i, 1, sz(son[x])) res = (ll) res * i % mod;
		else res = (ll) res * 2 % mod;
		for(int v : son[x]) res = (ll) res * get (v) % mod;
		return res;
	}
} t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	t.init (n);
	while (m--) {
		vi s;
		int q, w;
		cin >> q;
		while (q--) cin >> w, s.push_back(w);
		if(!t.insert (s)) return cout << "0\n", 0;
//		cout << "hehe-------------------------------------\n";
	} 
//	t.output (t.rt); 
//	for (const int &v : t.ns) cout << v << ", ";
//	cout << "\n";
	cout << t.get (t.rt) << "\n";
	return 0;
}
/*
7 5
3 1 2 3 
5 2 4 5 6 7 
3 4 6 7 
4 2 3 5 7 
4 2 4 5 7 

1 3 2 5 7 4 6
*/