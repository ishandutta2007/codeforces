#include <bits/stdc++.h>

typedef long long ll;
const int N = 6e5 + 50;
const int mod = 998244353;
const int g = 3;
const double pi = acos(-1.0);

char s[N], t[N];
int n, m, k, len, rev[N], e[N][6][6];
struct Complex
{
	double x, y;
	Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
} A[N], B[N], omega[N], omegaInv[N];

inline Complex operator+ (const Complex &a, const Complex &b) { return Complex(a.x + b.x, a.y + b.y); }
inline Complex operator- (const Complex &a, const Complex &b) { return Complex(a.x - b.x, a.y - b.y); }
inline Complex operator* (const Complex &a, const Complex &b) { return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline Complex operator/ (const Complex &a, const double t) { return Complex(a.x / t, a.y / t); }

inline void NTTInit(int n)
{
	k = 0, len = 1;
	while (len <= n) ++k, len <<= 1;
	for (int i = 1; i < len; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	omega[0] = omegaInv[0] = 1;
	Complex t(cos(2 * pi / len), sin(2 * pi / len));
	for (int i = 1; i < len; ++i) omega[i] = omegaInv[len - i] = omega[i - 1] * t;
}

inline void NTT(Complex *A, const Complex *w)
{
	for (int i = 0; i < len; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int h = 1; h < len; h <<= 1)
		for (int t = len / (h * 2), j = 0; j < len; j += h * 2)
		{
			const Complex *wn = w;
			for (int i = j; i < j + h; ++i)
			{
				const Complex _1 = A[i], _2 = A[i + h] * *wn;
				A[i] = _1 + _2, A[i + h] = _1 - _2;
				wn += t;
			}
		}
	if (w == omegaInv)
	{
		for (int i = 0; i < len; ++i) A[i] = A[i] / len;
	}
}

bool vis[10];
void dfs(int id, int x)
{
	if (vis[x]) return; vis[x] = true;
	for (int j = 0; j < 6; ++j) if (e[id][x][j]) dfs(id, j);
}
int main()
{
	scanf("%s%s", s, t); n = strlen(s), m = strlen(t);
	for (int i = 0; i < n; ++i) s[i] -= 'a';
	for (int i = 0; i < m; ++i) t[i] -= 'a';
	std::reverse(t, t + m);
	NTTInit(n + m + 5);
	for (int a = 0; a < 6; ++a)
		for (int b = 0; b < 6; ++b)
		{
			for (int i = 0; i < n; ++i) A[i] = Complex(s[i] == a, 0);
			for (int i = 0; i < m; ++i) B[i] = Complex(t[i] == b, 0);
			NTT(A, omega); NTT(B, omega);
			for (int i = 0; i < len; ++i) A[i] = A[i] * B[i];
			NTT(A, omegaInv);
			for (int k = 0; k + m - 1 < n; ++k)
				if (fabs(A[k + m - 1].x) >= 1e-6) e[k][a][b] = e[k][b][a] = true;
			memset(A, 0, sizeof A), memset(B, 0, sizeof B);
		}
	for (int i = 0; i < n - m + 1; ++i)
	{
		memset(vis, 0, sizeof vis);
		int ans = 6;
		for (int j = 0; j < 6; ++j)
		{
			if (!vis[j]) --ans, dfs(i, j);
		}
		printf("%d ", ans);
	}
}
// By Qingyu