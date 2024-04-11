#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005, ML = 2000005;

int N, L;
LL t[MN], x[MN], y[MN];
int p[MN], a[ML], b[ML];

inline LL divf(LL c, LL d) { return (c - ((c % d + d) % d)) / d; }
inline LL divc(LL c, LL d) { return (c + ((d - c % d) % d)) / d; }

inline bool check(LL *s, int *v) {
	LL lb = 0, rb = L;
	for (int id = 1; id <= N; ++id) {
		int i, j, dis;
		LL ci, cj;
		if (id == N) {
			i = p[id], j = N + 1, s[N + 1] = 0;
			ci = t[i] / L, cj = -1;
			dis = L - t[i] % L;
		} else {
			i = p[id], j = p[id + 1];
			ci = t[i] / L, cj = t[j] / L;
			dis = t[j] % L - t[i] % L;
		}
		if (ci == cj) if (s[i] > s[j] || s[j] > s[i] + dis) return 0;
		if (ci > cj) {
			lb = std::max(lb, divc(s[i] - s[j], ci - cj));
			rb = std::min(rb, divf(s[i] - s[j] + dis, ci - cj));
		}
		if (ci < cj) {
			rb = std::min(rb, divf(s[j] - s[i], cj - ci));
			lb = std::max(lb, divc(s[j] - s[i] - dis, cj - ci));
		}
	}
	if (lb > rb) return 0;
	for (int id = 1; id <= N; ++id) {
		int posj, posi, dif;
		if (id == N) {
			int i = p[id];
			posi = t[i] % L, posj = L;
			dif = lb - (s[i] - (t[i] / L) * lb);
		} else {
			int i = p[id], j = p[id + 1];
			posi = t[i] % L, posj = t[j] % L;
			LL xi = s[i] - (t[i] / L) * lb;
			LL xj = s[j] - (t[j] / L) * lb;
			dif = xj - xi;
		}
		for (int k = posj; k > posi; --k) v[k] = dif ? --dif, 1 : 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &N, &L), ++N;
	p[1] = 1;
	for (int i = 2; i <= N; ++i) {
		LL X, Y;
		scanf("%lld%lld%lld", &t[i], &X, &Y);
		if ((X ^ Y ^ t[i]) & 1) return puts("NO"), 0;
		x[i] = (X + Y + t[i]) / 2, y[i] = (X - Y + t[i]) / 2;
		p[i] = i;
	}
	std::sort(p + 1, p + N + 1, [](int i, int j) {
		return t[i] % L < t[j] % L;
	});
	if (!check(x, a) || !check(y, b)) return puts("NO"), 0;
	for (int i = 1; i <= L; ++i) putchar("LUDR"[b[i] * 2 + a[i]]);
	puts("");
	return 0;
}