#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;

inline int qPow(int b, LL e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Gcd(LL a, LL b) { return b ? Gcd(b, a % b) : a; }
int exGcd(LL a, LL b, LL &x, LL &y) {
	if (!b) return x = 1, y = 0, a;
	LL d = exGcd(b, a % b, y, x);
	return y -= a / b * x, d;
}

const int MN = 105, MS = 905;

int N, A[MN], B[MN];
int pr[MS], pc;
LL a[MS], b[MS], c[MS], d[MS];

inline void X(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i) continue;
		pr[++pc] = i;
		while (x % i == 0) x /= i;
	} if (x > 1) pr[++pc] = x;
}
inline void Z(int x, LL *C) {
	for (int i = 1; i <= pc; ++i) {
		int p = pr[i];
		C[i] = 0;
		while (x % p == 0) x /= p, ++C[i];
	}
}

#define F for (int i = 1; i <= pc; ++i)
inline int Merge() {
	LL Sb = 0, Sd = 0;
	F Sb += b[i], Sd += d[i];
	if (!Sb && !Sd) {
		F if (a[i] != c[i]) return 0;
		return 1;
	}
	if (!Sb || !Sd) {
		if (!Sd) std::swap(a, c), std::swap(b, d), std::swap(Sb, Sd);
		LL k = 0;
		F if (d[i]) {
			k = (a[i] >= c[i] && (a[i] - c[i]) % d[i] == 0) ? (a[i] - c[i]) / d[i] : -1;
			break;
		} else if (a[i] != c[i]) return 0;
		if (k == -1) return 0;
		F if (c[i] + k * d[i] != a[i]) return 0;
		return 1;
	}
	int ok = 0;
	F if (b[i] * Sd != d[i] * Sb) { ok = i; break; }
	if (ok) {
		int p1 = ok, p2 = 0;
		for (int i = 1; i <= pc; ++i)
			if (b[i] * d[p1] != d[i] * b[p1]) { p2 = i; break; }
		LL ka = d[p2] * (c[p1] - a[p1]) - d[p1] * (c[p2] - a[p2]);
		LL kc = b[p2] * (c[p1] - a[p1]) - b[p1] * (c[p2] - a[p2]);
		LL denom = d[p2] * b[p1] - d[p1] * b[p2];
		if (denom < 0) ka = -ka, kc = -kc, denom = -denom;
		if (ka < 0 || kc < 0 || ka % denom != 0 || kc % denom != 0) return 0;
		ka /= denom, kc /= denom;
		F {
			if (a[i] + ka * b[i] != c[i] + kc * d[i]) return 0;
			a[i] = a[i] + ka * b[i], b[i] = 0;
		}
		return 1;
	}
	LL kb = 0, kd = 0;
	F if (b[i]) { LL g = Gcd(b[i], d[i]); kb = b[i] / g, kd = d[i] / g; break; }
	LL k = 0;
	F if (b[i]) {
		if ((a[i] - c[i]) % (b[i] / kb)) return 0;
		k = (a[i] - c[i]) / (b[i] / kb);
		break;
	}
	F if (c[i] + k * (b[i] / kb) != a[i]) return 0;
	if (k < 0) std::swap(a, c), std::swap(b, d), std::swap(kb, kd), k = -k;
	LL x, y; exGcd(kb, kd, x, y);
	x = ((LL)x * -k % kd + kd) % kd;
	F a[i] += x * b[i], b[i] *= kd;
	return 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &A[i], &B[i]);
		X(A[i]), X(B[i]);
	}
	std::sort(pr + 1, pr + pc + 1);
	pc = std::unique(pr + 1, pr + pc + 1) - pr - 1;
	for (int i = 1; i <= N; ++i)
		if (i == 1) Z(A[i], a), Z(B[i], b);
		else if (Z(A[i], c), Z(B[i], d), !Merge()) return puts("-1"), 0;
	int Ans = 1;
	F Ans = (LL)Ans * qPow(pr[i], a[i]) % Mod;
	printf("%d\n", Ans);
	return 0;
}