#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace Mod {
	long long mul(long long a,long long b,long long mod) {
		long long tmp = a * b - (long long)((long double)a * b / mod + 0.5) * mod;
		return tmp < 0 ? tmp + mod : tmp;
	}
	int P;
	void Build_Mod(int v) {P = v;}
	inline int cH(long long x) {return (x % P + P) % P;}
	int Pow_M(long long x, long long y) {long long ret = 1; x = cH(x);while (y) {if (y & 1) ret = mul(ret , x , P);x = mul(x , x , P), y >>= 1;}return cH(ret);}
	int inv(long long x) {return Pow_M(x, P - 2);}
	struct modint {
		int x;
		modint(int x = 0) : x(x) {}
		modint operator = (const modint a) {x = a.x; return *this;}
		modint operator = (const int a) {x = cH(a); return *this;}
	};
	inline modint operator + (modint a, modint b) {return modint(a.x + b.x >= P ? a.x + b.x - P : a.x + b.x);}
	inline modint operator + (modint a, long long b) {return modint(cH((long long)a.x + b));}
	inline modint operator - (modint a, modint b) {return modint(a.x < b.x ? a.x - b.x + P : a.x - b.x);}
	inline modint operator - (modint a, long long b) {return modint(cH((long long)a.x - b));}
	inline modint operator * (modint a, modint b) {return modint(mul(a.x , b.x , P));}
	inline modint operator * (modint a, long long b) {return modint(cH(mul(a.x , b , P)));}
	inline modint operator / (modint a, modint b) {return modint(mul(a.x , inv(b.x) , P));}
	inline modint operator / (modint a, long long b) {return modint(mul(a.x , inv(b) , P));}
	inline int operator == (modint a, modint b) {return a.x == b.x;}
	inline modint operator += (modint &a, modint b) {a = a + b; return a;}
	inline modint operator += (modint &a, long long b) {a = a + b; return a;}
	inline modint operator -= (modint &a, modint b) {a = a - b; return a;}
	inline modint operator -= (modint &a, long long b) {a = a - b; return a;}
	inline modint operator *= (modint &a, modint b) {a = a * b; return a;}
	inline modint operator *= (modint &a, long long b) {a = a * b; return a;}
	inline modint operator /= (modint &a, modint b) {a = a / b; return a;}
	inline modint operator /= (modint &a, long long b) {a = a / b; return a;}
	inline istream & operator >> (istream &in, modint &a) {in >> a.x; return in;}
	inline ostream & operator << (ostream &out, modint b) {out << b.x; return out;}
	inline modint operator ^ (modint x, long long y) {return Pow_M(x.x, y);}
	inline modint Ch(int x) {return modint(cH(x));}
	inline void read(modint &x) {long long t; scanf("%lld", &t), x = t % P;}
	inline void print(modint x) {printf("%d", x.x);}
	inline void print(modint x, char c) {printf("%d%c", x.x, c);}
	modint One = 1, Two = 2;
};

using namespace Mod;

const int N = 5010;

int n, k, M[N];
vector <int> G[N];
modint f[N][N][2], Ans, t[N][2];

void dfs(int u, int fa) {
	f[u][0][0] = 1, f[u][0][1] = 0;
	for (int v : G[u]) if (v != fa) {
		dfs(v, u);
		for (int i = 0; i <= max(M[v] + 1, M[u]); i++) t[i][0] = t[i][1] = 0;
		for (int i = 0; i <= M[u]; i++)
			for (int j = 0; j <= M[v]; j++) {
				t[i][0] += f[u][i][0] * f[v][j][0];
				t[i][1] += f[u][i][0] * f[v][j][1];
				t[i][1] += f[u][i][1] * f[v][j][0];
				t[i][1] += f[u][i][1] * f[v][j][1];
				if (i + j + 1 > k) {
					t[max(i, j + 1)][1] += f[u][i][0] * f[v][j][0];
					t[max(i, j + 1)][1] += f[u][i][0] * f[v][j][1];
					t[max(i, j + 1)][1] += f[u][i][1] * f[v][j][0];
					t[max(i, j + 1)][1] += f[u][i][1] * f[v][j][1];
				}
				else {
					t[max(i, j + 1)][0] += f[u][i][0] * f[v][j][0];
					t[max(i, j + 1)][1] += f[u][i][0] * f[v][j][1];
					t[max(i, j + 1)][1] += f[u][i][1] * f[v][j][0];
					t[max(i, j + 1)][1] += f[u][i][1] * f[v][j][1];
				}
			}
		M[u] = max(M[u], M[v] + 1);
		for (int i = 0; i <= M[u]; i++)
			f[u][i][0] = t[i][0], f[u][i][1] = t[i][1]; 
	}
}

int main() {
	Build_Mod(998244353);
	read(n), read(k);
	for (int i = 1; i < n; i++) {
		int u, v; read(u), read(v);
		G[u].pb(v), G[v].pb(u); 
	}
	dfs(1, 0);
	for (int i = 0; i <= M[1]; i++)
		Ans += f[1][i][1];
	print((Two ^ (n - 1)) - Ans, '\n');
	return 0;
}