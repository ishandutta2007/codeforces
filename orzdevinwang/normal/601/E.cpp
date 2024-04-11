#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 17, Base = 1e7 + 19, mod = 1e9 + 7;
int n, q, k;
bool qr[N];
int f[32][N];
int l[N], r[N], tp, v[N], w[N];
vi s[N];
void add (int x, int L, int R, int l, int r, int p) {
	if(l <= L && R <= r) {
		s[x].push_back(p);
		return ;
	}
	int mid = (L + R) >> 1;
	if(l <= mid) add (x << 1, L, mid, l, r, p);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, p);
}
void dfs (int x, int d, int L, int R) { 
	int mid = (L + R) >> 1;
	for (const int &t : s[x]) 
		R(i, k - w[t], 0) 
			f[d][i + w[t]] = max(f[d][i + w[t]], f[d][i] + v[t]);
	L(i, 0, k) f[d + 1][i] = f[d][i];
	if(L == R) {
		if(qr[L]) {
			int ns = 0;
			R(i, k, 1) ns = (ll) ns * Base % mod, (ns += f[d][i]) %= mod;
			cout << ns << '\n';
		}
		return ;
	}
	dfs (x << 1, d + 1, L, mid);
	L(i, 0, k) f[d + 1][i] = f[d][i];
	dfs (x << 1 | 1, d + 1, mid + 1, R);	
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> k, tp = n;
	L(i, 1, n) 
		cin >> v[i] >> w[i], l[i] = 1;
	cin >> q;
	L(i, 1, q) {
		int op, k;
		cin >> op ;
		if(op == 1) ++ tp, cin >> v[tp] >> w[tp], l[tp] = i;
		else if(op == 2) cin >> k, r[k] = i;
		else qr[i] = true;
	}
	L(i, 1, tp) if(!r[i]) r[i] = q;
	L(i, 1, tp) add (1, 1, q, l[i], r[i], i);
	dfs (1, 0, 1, q);
	return 0;
}