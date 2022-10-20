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
	modint One = 1;
};

using namespace Mod;

char A[1010], B[1010];
int n, m, lst[2][1010];
modint f[1010][1010][2], Ans = 0;

int main() {
	Build_Mod(998244353);
	scanf("%s%s", A + 1, B + 1);
	n = strlen(A + 1), m = strlen(B + 1);
	lst[0][1] = lst[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		lst[0][i] = lst[0][i - 1];
		if (A[i] == A[i - 1]) lst[0][i] = i; 
	}
	for (int i = 2; i <= m; i++) {
		lst[1][i] = lst[1][i - 1];
		if (B[i] == B[i - 1]) lst[1][i] = i; 
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (A[i] != B[j]) f[i][j][0] += j - lst[1][j] + 1, f[i][j][1] += i - lst[0][i] + 1;
			if (A[i] != A[i + 1]) f[i + 1][j][0] += f[i][j][0];
			if (A[i + 1] != B[j]) f[i + 1][j][0] += f[i][j][1];
			if (B[j] != B[j + 1]) f[i][j + 1][1] += f[i][j][1];
			if (A[i] != B[j + 1]) f[i][j + 1][1] += f[i][j][0]; 
			Ans += f[i][j][0] + f[i][j][1];
		}
	print(Ans, '\n');
	return 0;
}