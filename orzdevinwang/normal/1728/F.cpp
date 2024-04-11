#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
#define bs bitset < N > 
const int N = 1e3 + 7, M = N * N;
int n, a[M], lst[M], idt, val[M];
bs G[N], cur;
unordered_map < int, int > mp;
vi el[M], er[M];
int road[M], tp, mc[M];
bool matl[M], matr[M];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i], mc[i] = 0;
		L(j, 1, n) {
			int W = a[i] * j;
			if(!mp.count(W)) mp[W] = ++idt, val[idt] = W;
			int v = mp[W];
			el[i].emplace_back(v), er[v].emplace_back(i);
		}
	}
	ll ns = 0;
	L(tc, 1, n) {
		L(i, 1, n) cur.set(i);
		queue < int > q;
		L(i, 1, n) if(!matl[i]) q.push(i), cur.reset(i), lst[i] = 0;
		L(i, 1, n) while(matr[el[i][mc[i]]]) ++mc[i]; 
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			bs o = cur & G[u];
			cur ^= o;
			for(int t = o._Find_first(); t <= n; t = o._Find_next(t)) 
				q.push(t), lst[t] = u;
		}
		int xu = -1, cw = 1e9 + 7, xv;
		L(i, 1, n) if(!cur[i] && cw > val[el[i][mc[i]]]) xu = i, cw = val[el[i][mc[i]]];
		xv = el[xu][mc[xu]], ns += cw, tp = 0;
		for(int u = xu; u; u = lst[u]) road[++tp] = u;
		R(i, tp - 1, 1) L(x, 1, n) if(G[x][road[i]]) G[x].set(road[i + 1]), G[x].reset(road[i]);
		for(const int &u : er[xv]) G[u].set(xu);
		matl[road[tp]] = true, matr[xv] = true;
	}
	cout << ns << '\n';
	return 0;
}