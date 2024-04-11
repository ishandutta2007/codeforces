#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

namespace Mod {int P; void Build_Mod(int v) {P = v;} inline int cH(long long x) {return (x % P + P) % P;} int Pow_M(long long x, long long y) {long long ret = 1; x = cH(x);while (y) {if (y & 1) ret = ret * x % P;x = x * x % P, y >>= 1;}return cH(ret);} int inv(long long x) {return Pow_M(x, P - 2);} struct modint { int x; modint(int x = 0) : x(x) {} modint operator = (const modint a) {x = a.x; return *this;} modint operator = (const int a) {x = cH(a); return *this;} }; inline modint operator + (modint a, modint b) {return modint(a.x + b.x >= P ? a.x + b.x - P : a.x + b.x);} inline modint operator + (modint a, long long b) {return modint(cH((long long)a.x + b));} inline modint operator - (modint a, modint b) {return modint(a.x < b.x ? a.x - b.x + P : a.x - b.x);} inline modint operator - (modint a, long long b) {return modint(cH((long long)a.x - b));} inline modint operator * (modint a, modint b) {return modint(1ll * a.x * b.x % P);} inline modint operator * (modint a, long long b) {return modint(cH(1ll * a.x * (b % P) % P));} inline modint operator / (modint a, modint b) {return modint(1ll * a.x * inv(b.x) % P);} inline modint operator / (modint a, long long b) {return modint(1ll * a.x * inv(b) % P);} inline int operator == (modint a, modint b) {return a.x == b.x;} inline modint operator += (modint &a, modint b) {a = a + b; return a;} inline modint operator += (modint &a, long long b) {a = a + b; return a;} inline modint operator -= (modint &a, modint b) {a = a - b; return a;} inline modint operator -= (modint &a, long long b) {a = a - b; return a;} inline modint operator *= (modint &a, modint b) {a = a * b; return a;} inline modint operator *= (modint &a, long long b) {a = a * b; return a;} inline modint operator /= (modint &a, modint b) {a = a / b; return a;} inline modint operator /= (modint &a, long long b) {a = a / b; return a;} inline istream & operator >> (istream &in, modint &a) {in >> a.x; return in;} inline ostream & operator << (ostream &out, modint b) {out << b.x; return out;} inline modint operator ^ (modint x, long long y) {return Pow_M(x.x, y);} }; using namespace Mod;

modint C(int x, int y) {
	modint a = 1, b = 1; y = x - y < y ? x - y : y;
	for (int i = 1; i <= y; i++) a *= x - i + 1, b *= i;
	return a / b;
}

const int N = 1510;

int n, m, t;
modint a, b, x, p[N], q[N], f[N][N], s[N][N], g[N][N];

int main() {
	ios::sync_with_stdio(false), Build_Mod(1000000007);
	cin >> n >> m >> a >> b >> t, x = a / b;
	for (int i = 0; i <= min(m, t); i++)
		p[i] = C(t, i) * (x ^ i) * ((modint(1) - x) ^ (t - i));
	for (int i = 1; i <= m; i++) q[i] = q[i - 1] + p[i - 1];
	f[0][m] = s[0][m] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		f[i][j] = p[m - j] * ((s[i - 1][m] - s[i - 1][m - j]) * q[j] - g[i - 1][j]);
		s[i][j] = s[i][j - 1] + f[i][j], g[i][j] = g[i][j - 1] + p[j - 1] * s[i][j - 1];
	}
	cout << s[n][m] << endl;
	return 0;
}