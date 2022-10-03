// luogu

#include <cstdio>

typedef long long LL;
const LL Infll = 0x7fffffffffffffff;
const int MN = 100005;

inline void chkmx(LL &x, LL y) { x = x > y ? x : y; }
inline void chkmn(LL &x, LL y) { x = x < y ? x : y; }

int N;
LL x[MN], y[MN], z[MN];
LL Ansx, Ansy, Ansz;

inline bool check(LL r) {
	static LL Mx0, Mxx, Mxy, Mxz; Mx0 = Mxx = Mxy = Mxz = Infll;
	static LL Mn0, Mnx, Mny, Mnz; Mn0 = Mnx = Mny = Mnz = -Infll;
	for (int i = 1; i <= N; ++i) {
		chkmn(Mx0, +r + x[i] + y[i] + z[i]);
		chkmn(Mxx, +r - x[i] + y[i] + z[i]);
		chkmn(Mxy, +r + x[i] - y[i] + z[i]);
		chkmn(Mxz, +r + x[i] + y[i] - z[i]);
		chkmx(Mn0, -r + x[i] + y[i] + z[i]);
		chkmx(Mnx, -r - x[i] + y[i] + z[i]);
		chkmx(Mny, -r + x[i] - y[i] + z[i]);
		chkmx(Mnz, -r + x[i] + y[i] - z[i]);
	}
	for (LL o = 0; o < 2; ++o) {
		LL l0 = Mn0 + ((Mn0 & 1) ^ o), r0 = Mx0 - ((Mx0 & 1) ^ o);
		LL lx = Mnx + ((Mnx & 1) ^ o), rx = Mxx - ((Mxx & 1) ^ o);
		LL ly = Mny + ((Mny & 1) ^ o), ry = Mxy - ((Mxy & 1) ^ o);
		LL lz = Mnz + ((Mnz & 1) ^ o), rz = Mxz - ((Mxz & 1) ^ o);
		if (l0 > r0 || lx > rx || ly > ry || lz > rz) continue;
		LL a = lx, b = ly, c = lz;
		if (a + b + c > r0) continue;
		if (a + b + c < l0) a = rx < l0 - b - c ? rx : l0 - b - c;
		if (a + b + c < l0) b = ry < l0 - a - c ? ry : l0 - a - c;
		if (a + b + c < l0) c = rz < l0 - a - b ? rz : l0 - a - b;
		if (a + b + c < l0) continue;
		Ansx = (b + c) / 2, Ansy = (a + c) / 2, Ansz = (a + b) / 2;
		return 1;
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		LL l = 0, r = 3000000000000000000, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld %lld %lld\n", Ansx, Ansy, Ansz);
	}
	return 0;
}