#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 307, mod = 1e9 + 7, B = 16;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, q, a[N], r[N], cB;
bool cp[N][N];
int f[40][B][N]; //  0~31  

struct matrix {
	int s[N][N];
	matrix (const matrix & o) {
		L(i, 1, n) L(j, 1, n) s[i][j] = o.s[i][j];
	}
	matrix (int x = 0) { L(i, 1, n) L(j, 1, n) s[i][j] = i == j ? x : 0; } 
	int * operator [] (int x) {
		return s[x];
	}
	void Move () { 
		L(i, 2, n) L(j, 1, n) (s[i - 1][j] += mod - s[i][j]) %= mod;	
		L(i, 1, n) L(j, 1, n - 1) (s[i][j + 1] += s[i][j]) %= mod;	
	}
} ;

matrix mA[B * 5 + 3], mB[B * 4 + 3], Bs, Gs; // A_i : i ; B_j : j*B ;  

matrix operator * (matrix a, matrix b) {
	matrix ns;
	L(i, 1, n) L(j, 1, i) L(k, j, i) (ns[i][j] += (ll) a[i][k] * b[k][j] % mod) %= mod;
	return ns;
} 

int ord[N], vl[N], vr[N], bel[N];
vi ad[N];
void Build () {
	memset(f, 0, sizeof(f));
	L(i, 1, cB) ad[i].clear();
	L(i, 1, n) ord[i] = i;
	R(i, n, 1) {
		if(a[i] > 0) r[i] = 0;
		else {
			r[i] = 1001;
			L(j, i + 1, n) if(cp[i][j]) r[i] = min(r[i], r[j] + 1);
		}
	} 
	L(i, 1, n) r[i] = max(r[i], 0);
	sort (ord + 1, ord + n + 1, [&] (int x, int y) {
		return r[x] < r[y];
	});
	int lst = 1;
	cB = 1, ad[cB].push_back(ord[1]);
	L(i, 2, n) {
		if(i - lst > B * 4 || r[ord[i]] - r[ord[lst]] > B * 4) ++cB, lst = i;
		ad[cB].push_back(ord[i]);
	}
	L(i, 1, cB) {
		vl[i] = r[ad[i][0]], vr[i] = r[ad[i][sz(ad[i]) - 1]];
		for (const int & x : ad[i]) {
			bel[x] = i;
			L(t, 0, B - 1) {
				int z = vr[i] - r[x] + t;
				L(k, 1, x) (f[i][t][k] += (ll) mA[z][x][k] * (a[x] + mod) % mod) %= mod;
			}
		}
	}
}

void modify (int x, int k) {
	if(a[x] <= 0 && a[x] + k > 0) a[x] += k, Build();
	else {
		a[x] += k;
		int i = bel[x];
		L(t, 0, B - 1) {
			int z = vr[i] - r[x] + t;
			L(p, 1, x) (f[i][t][p] += (ll) mA[z][x][p] * k % mod) %= mod;
		}
	}  
} 

int wl[N], cwl[N];
int query (int len, int pl, int pr) {
	int ret = 0;
	L(i, 1, cB) {
		if(len >= vr[i]) {
			int R = (len - vr[i]) % B, P = (len - vr[i]) / B;
			L(k, 1, n) wl[k] = f[i][R][k], (wl[k] += wl[k - 1]) %= mod;
			L(k, 1, n) (ret += (ll) wl[k] * (mB[P][k][pr] - mB[P][k][pl - 1] + mod) % mod) %= mod;
		} else if(len >= vl[i]) {
			for (const int &x : ad[i]) if(len >= r[x]) {
				L(j, pl, pr) (ret += (ll) mA[len - r[x]][x][j] * (a[x] + mod) % mod) %= mod;
			}
		}
	} 
	L(i, 1, n) if(len < r[i] && pl <= i && i <= pr) (ret += a[i] + mod) %= mod; 
	return ret;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		int g, t; 
		cin >> g;
		while (g--) cin >> t, cp[i][t] = true ;
	}
	L(i, 1, n) Bs[i][i] = i;
	L(i, 1, n) L(j, 1, i - 1) if(cp[j][i]) (Bs[i][j] += i) %= mod;
	mA[0] = mB[0] = matrix (1);
	L(i, 1, B * 5) mA[i] = mA[i - 1] * Bs;
	L(i, 1, B * 4) mB[i] = mB[i - 1] * mA[B];
	L(i, 1, B * 4) mB[i].Move();
	Build();
	cin >> q;
	L(zp, 1, q) {
		int op, k, l, r;
		cin >> op >> k >> l;
		if (op == 2) modify (k, l);
		else cin >> r, cout << query (k, l, r) << '\n';
	}
	return 0;
}