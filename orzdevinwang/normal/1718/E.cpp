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
const int N = 2e5 + 7, mod = 1019260817;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

int n, m, *f[N], *g[N], *w[N];
ull A[N], B[N];
inline void ha()  {
	me(A, 0), me(B, 0);
	L(i, 1, n) A[i] = 1;
	L(o, 1, 30) {
		L(i, 1, n) L(j, 1, m) B[j] ^= w[i][j] * A[i];
		L(j, 1, m) L(i, 1, n) A[i] ^= w[i][j] * B[j];
	}
}

mt19937_64 orz(time(0) ^ clock() ^ *new int);
const int Base = 114; // orz() % 998244351 + 1;

ull qa[N], qb[N];
ull pa[N], pb[N];

int mtx[N], mty[N];

void dfsx(int a, int b) ; 
void dfsy(int a, int b) ; 

bool vxa[N], vya[N];
bool vxb[N], vyb[N];
void dfsx(int a, int b) {
	vxa[a] = vxb[b] = true, mtx[a] = b;
	map < int, int > mp;
	L(i, 1, m) if(f[a][i] && !vya[i]) mp[f[a][i]] = i;
	L(i, 1, m) if(g[b][i] && !vyb[i]) assert(mp.count(g[b][i])), dfsy(mp[g[b][i]], i);
} 

void dfsy(int a, int b) {
	vya[a] = vyb[b] = true, mty[a] = b;
	map < int, int > mp;
	L(i, 1, n) if(f[i][a] && !vxa[i]) mp[f[i][a]] = i;
	L(i, 1, n) if(g[i][b] && !vxb[i]) assert(mp.count(g[i][b])), dfsx(mp[g[i][b]], i);
}

pair < ull, int > xa[N]; 
pair < ull, int > xb[N]; 

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) f[i] = new int [m + 1], g[i] = new int[m + 1], w[i] = new int [m + 1];
	L(i, 1, n) L(j, 1, m) cin >> f[i][j], w[i][j] = qpow(f[i][j] + 2, Base);
	ha();
	L(i, 1, n) pa[i] = A[i], xa[i] = make_pair(pa[i], i);
	L(i, 1, m) pb[i] = B[i];
	
	L(i, 1, n) L(j, 1, m) cin >> g[i][j], w[i][j] = qpow(g[i][j] + 2, Base);
	swap(f, g), ha(), swap(f, g);
	L(i, 1, n) qa[i] = A[i], xb[i] = make_pair(qa[i], i);
	L(i, 1, m) qb[i] = B[i];
	
	sort(xa + 1, xa + n + 1);
	sort(xb + 1, xb + n + 1);
	
//	L(i, 1, n) cout << xa[i].first << ' ';
//	cout << '\n';
//	L(i, 1, n) cout << xb[i].first << ' ';
//	cout << '\n';
	L(i, 1, n) if(xa[i].first != xb[i].first) return cout << "-1\n", 0;
	
	int pa = 1, pb = 1;
	while(pa <= n && pb <= n) {
		dfsx(xa[pa].second, xb[pb].second);
		while(pa <= n && vxa[xa[pa].second]) ++pa;
		while(pb <= n && vxb[xb[pb].second]) ++pb;
	}
	
	pa = 1, pb = 1;
	while(pa <= m && pb <= m) {
		while(pa <= m && vya[pa]) ++pa;
		while(pb <= m && vyb[pb]) ++pb;
		if(pa <= m && pb <= m) mty[pa] = pb, vya[pa] = vyb[pb] = true;
	}
	
//	L(i, 1, n) cout << mty[i] << ",";
//	cout << '\n';
	
	
	vector < pair < int, int > > X, Y; 
	L(i, 1, n) if(mtx[i] != i) {
		int u = i;
		while(mtx[u] != i) X.push_back({u, mtx[u]}), swap(u, mtx[u]);
		mtx[u] = u;
	}
	
	L(i, 1, m) if(mty[i] != i) {
		int u = i;
		while(mty[u] != i) Y.push_back({u, mty[u]}), swap(u, mty[u]);
		mty[u] = u;
	}
	
	cout << sz(X) + sz(Y) << '\n';
	reverse(X.begin(), X.end()), reverse(Y.begin(), Y.end());
	for(auto u : X) cout << 1 << ' ' << u.first << ' ' << u.second << '\n';
	for(auto u : Y) cout << 2 << ' ' << u.first << ' ' << u.second << '\n';
	return 0;
}