#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 403;
int n, m, k, f[N][N], mod;
int qpow (int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
struct ufs {
	int f[N * N];
	void init (int n) {
		L(i, 1, n) f[i] = i;
	}
	int find (int x) {
		return f[x] == x ? x : f[x] = find (f[x]);
	}
	void merge (int x, int y) {
		f[find(x)] = find(y);
	}
} u;
int idt, id[N * N], ns;
int det (int n) {
	int res = 1;
	L(i, 1, n) {
		int w = -1;
		L(j, i, n) if(f[j][i]) w = j;
		if(!~w) return 0; 
		if(w != i) res = (mod - res) % mod, swap(f[i], f[w]);
		res = (ll) res * f[i][i] % mod;
		L(j, i + 1, n) {
			int z = mod - (ll) f[j][i] * qpow (f[i][i]) % mod;
			L(k, i, n) (f[j][k] += (ll) z * f[i][k] % mod) %= mod;
		}
	}
	return res;
}
#define P(i, j) (((i) - 1) * (m + 1) + (j))
char s[N][N];
void eadd (int u, int v) { 
	if(u != v) (f[u][v] += mod - 1) %= mod, (f[v][u] += mod - 1) %= mod, (f[u][u] += 1) %= mod, (f[v][v] += 1) %= mod; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> mod;
	L(i, 1, n) cin >> (s[i] + 1);
	u.init ((n + 1) * (m + 1));
	L(i, 1, n) L(j, 1, m) {
		if(s[i][j] == '*') ++k;
		else if(s[i][j] == '/') {
			if (u.find(P(i + 1, j)) == u.find(P(i, j + 1))) 
				return cout << "0\n", 0;
			u.merge(P(i + 1, j), P(i, j + 1));	
		} 
		else {
			if (u.find(P(i, j)) == u.find(P(i + 1, j + 1))) 
				return cout << "0\n", 0;
			u.merge(P(i, j), P(i + 1, j + 1));	
		}
	} 
	
	L(i, 1, n + 1) L(j, 1, m + 1) if(((i + j) & 1) && u.find(P(i, j)) == P(i, j)) id[P(i, j)] = ++idt;
	L(i, 1, n + 1) L(j, 1, m + 1) if((i + j) & 1) id[P(i, j)] = id[u.find(P(i, j))];
	if(idt <= k + 1) {
		L(i, 1, n) L(j, 1, m) if(s[i][j] == '*') {
			if((i + j) & 1) eadd(id[P(i, j)], id[P(i + 1, j + 1)]);
			else eadd(id[P(i + 1, j)], id[P(i, j + 1)]);
		} 
		(ns += det(idt - 1)) %= mod;
		L(i, 1, idt) L(j, 1, idt) f[i][j] = 0;	
	}
	idt = 0;
	
	L(i, 1, n + 1) L(j, 1, m + 1) if(!((i + j) & 1) && u.find(P(i, j)) == P(i, j)) id[P(i, j)] = ++idt;
	L(i, 1, n + 1) L(j, 1, m + 1) if(!((i + j) & 1)) id[P(i, j)] = id[u.find(P(i, j))];
	if(idt <= k + 1) {
		L(i, 1, n) L(j, 1, m) if(s[i][j] == '*') {
			if((i + j) & 1) eadd(id[P(i + 1, j)], id[P(i, j + 1)]);
			else eadd(id[P(i, j)], id[P(i + 1, j + 1)]);
		} 
		(ns += det(idt - 1)) %= mod;
		L(i, 1, idt) L(j, 1, idt) f[i][j] = 0;	
	}
	idt = 0;
	
	cout << ns << "\n";
	return 0;
}