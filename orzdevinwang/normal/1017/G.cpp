#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n, q, B, sB, dep[N], fa[N], dw[N];
bool ok[N], isp[N], intr[N], val[N];
int ehd[N], ev[N], ecnt[N], cle[N], enx[N], eid;
vi e[N];
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid, ecnt[eid] = 0;
	for(int x = fa[v]; x != u; x = fa[x]) { ecnt[eid] += (!val[x]); }
}

void dfs(int x) {
	isp[x] = ok[x];
	for(const int &v : e[x]) { dep[v] = dep[x] + 1, dfs(v), isp[x] |= isp[v]; }
}

void build(int x, int Fa) {
	int cnt = 0;
	for(const int &v : e[x]) { cnt += isp[v]; }
	if(cnt >= 2 || ok[x]) {
		if(Fa) { eadd(Fa, x); }
		Fa = x, intr[x] = true;
	}
	for(const int &v : e[x]) { build(v, Fa), cnt += isp[v]; }
}

void move1(int x) {
	if(!val[x]) return val[x] = true, void();
	++dw[x]; 
	for(int i = ehd[x]; i; i = enx[i]) { if(dw[x] > ecnt[i]) { move1(ev[i]); } }
}

void move2(int x) {
	val[x] = dw[x] = false, cle[x] = true;
	for(int i = ehd[x]; i; i = enx[i]) { ecnt[i] = dep[ev[i]] - dep[x] - 1, move2(ev[i]); }
}

void mv(int x, int ok, int s) {
	if(intr[x]) { ok |= cle[x], s = dw[x]; }
	else {
		if(ok) val[x] = false;
		if(!val[x] && s) { --s, val[x] = true; } 
	}
	for(const int &v : e[x]) { mv(v, ok, s); }
}

int opt[N], ox[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> q;
	L(i, 2, n) { cin >> fa[i], e[fa[i]].push_back(i); }
	B = sqrt(q) * 2, sB = (q - 1) / B + 1;
	L(i, 1, q) cin >> opt[i] >> ox[i];
	L(t, 1, sB) {
		int l = (t - 1) * B + 1, r = min(t * B, q);
		eid = 0;
		L(i, l, r) { ok[ox[i]] = true; }
		dfs(1), build(1, 0);
		L(i, l, r) {
			if(opt[i] == 1) { move1(ox[i]); }
			else if(opt[i] == 2) { move2(ox[i]); }
			else { cout << (val[ox[i]] ? "black" : "white") << "\n"; }
		}
		mv(1, 0, 0);
		L(i, 1, n) intr[i] = cle[i] = ok[i] = false, ehd[i] = dw[i] = 0; 
	}
	return 0;
}