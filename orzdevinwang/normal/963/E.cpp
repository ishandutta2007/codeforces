#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 107, n = 101, xn = 51, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int pn, f[N][N * 2], tc[N][N];
void Guess() {
	L(i, 1, n) {
		int maxn = i;
		L(j, i + 1, n) if(f[j][i] > f[maxn][i]) maxn = j;
		if(!f[maxn][i]) assert(false);
		L(j, 1, pn) swap(f[maxn][j], f[i][j]);
		int iv = qpow(f[i][i]);
		L(j, 1, pn) f[i][j] = (ll) f[i][j] * iv % mod;
		L(j, 1, n) {
			if(i == j) continue;
			int tmp = f[j][i];
			L(k, i, pn) (f[j][k] += mod - (ll) tmp * f[i][k] % mod) %= mod;
		}
	}
}

int R, a[4], S;
int G[N][N][N], ns[N][N]; 
bool vis[N][N]; 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> R;
	L(i, 0, 3) cin >> a[i], S += a[i];
	S = qpow(S);
	L(i, 0, 3) a[i] = (ll) a[i] * S % mod; 
	L(i, 1, n) L(j, 1, n) vis[i][j] = (i - xn) * (i - xn) + (j - xn) * (j - xn) <= R * R;
	pn = n * 2 + 1;
	L(i, 1, n) {
		me(f, 0);
		L(j, 1, n) {
			if(vis[i][j]) {
				if(vis[i][j - 1]) f[j][j - 1] = mod - a[1];
				if(vis[i][j + 1]) f[j][j + 1] = mod - a[3];
				f[j][n * 2 + 1] = 1;
				L(t, 1, n) (f[j][t] += mod - (ll) G[i - 1][j][t] * a[0] % mod) %= mod;
				(f[j][n * 2 + 1] += (ll) a[0] * G[i - 1][j][n + 1] % mod) %= mod;
				(f[j][n * 2 + 1] += f[j][n + 1]) %= mod; 
				(f[j][j] += 1) %= mod; 
				f[j][j + n] = a[2];
			} else {
				f[j][j] = 1;
			}	
		}
		Guess(); 
		L(j, 1, n) L(k, 1, n + 1) G[i][j][k] = f[j][k + n];
	}
	R(i, n, 1) {
		L(j, 1, n) if(vis[i][j]) {
			ns[i][j] = G[i][j][n + 1];
			L(k, 1, n) (ns[i][j] += (ll) ns[i + 1][k] * G[i][j][k] % mod) %= mod;
		}
	}
//	L(i, 1, n) {
//		L(j, 1, n) {
//			if(vis[i][j]) {
//				cout << i - xn << ' ' << j - xn << " : " << ns[i][j] << endl;
//			} else assert(!ns[i][j]);
//		}
//	}
	cout << ns[xn][xn] << '\n';
	return 0;
}