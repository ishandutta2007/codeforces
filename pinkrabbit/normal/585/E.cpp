#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 500005, ML = 10000005, MP = 664580;

bool ip[ML];
int p[MP], pc;
int mu[ML];
void Sieve(int N) {
	mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i, mu[i] = -1;
		for (int j = 1; j <= pc && p[j] * i <= N; ++j) {
			ip[p[j] * i] = 1;
			if (i % p[j]) mu[p[j] * i] = -mu[i];
			else break;
		}
	}
}

int L, N, _2[MN], Mx;
int b[ML];

int main() {
	scanf("%d", &N), _2[0] = 1;
	for (int i = 1, x; i <= N; ++i) {
		scanf("%d", &x), ++b[x];
		Mx = Mx > x ? Mx : x;
		_2[i] -= (_2[i] = _2[i - 1] << 1) >= Mod ? Mod : 0;
	}
	Sieve(L = Mx);
	for (int j = 1; j <= pc; ++j) {
		int pr = p[j], l = L / pr;
		for (int i = l; i >= 1; --i)
			b[i] -= (b[i] += b[i * pr]) >= Mod ? Mod : 0;
	}
	LL F = 0, G = 0, X = 0;
	for (int i = 1; i <= L; ++i) {
		if (!mu[i] || !b[i]) continue;
		X = mu[i] > 0 ? _2[b[i]] : Mod - _2[b[i]];
		F += X - mu[i], G += b[i] * X;
	}
	printf("%lld\n", ((G - F % Mod * N) % Mod + Mod) % Mod);
	return 0;
}