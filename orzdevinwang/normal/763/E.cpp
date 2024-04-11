#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 1 << 18;
int n, k, m, q, f[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int lg[N], ns, cnts[N], fsk[20][N];
vi e[N];
bool vis[N];
void build (int x, int L, int R) {
	L(i, L, R) f[i] = i;
	L(i, L, R) for (const int &v : e[i]) if(i < v && v <= R && find(v) != find (i)) {
		int x = find (v), y = find (i);
		if(x < L + k || x > R - k) f[y] = x;
		else f[x] = y;
	}
	L(i, L, R) fsk[lg[x]][i] = f[i];
	L(i, L + k, R - k) if (f[i] == i) cnts[x] += 1;
	if(L == R) return ;
	int mid = (L + R) >> 1;
	lg[x << 1] = lg[x << 1 | 1] = lg[x] + 1;
	build (x << 1, L, mid);
	build (x << 1 | 1, mid + 1, R);
}
vi S;
void query (int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) {
		L(i, L, min(L + k - 1, R)) f[i] = fsk[lg[x]][i], vis[i] = true, S.push_back(i);
		L(i, max(R - k + 1, L), R) if(!vis[i]) f[i] = fsk[lg[x]][i], vis[i] = true, S.push_back(i); 
		ns += cnts[x];
		return ;
	}
	int mid = (L + R) >> 1;
	if (l <= mid) query (x << 1, L, mid, l, r);
	if (r > mid) query (x << 1 | 1, mid + 1, R, l, r);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap (u, v);
		e[u].push_back(v);
	}
	build (1, 1, n);
	cin >> q;
	L(t, 1, q) {
		int l, r;
		ns = 0, S.clear (), cin >> l >> r, query (1, 1, n, l, r);
		for (const int &x : S) for (const int &v : e[x]) if(vis[v] && find(x) != find (v)) f[find (x)] = find (v);
		for (const int &x : S) ns += f[x] == x, vis[x] = false;
		cout << ns << '\n';
	}
	return 0;
}