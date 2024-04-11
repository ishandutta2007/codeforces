#include <cstdio>
#include <cmath>
#include <algorithm>

typedef double db;
typedef long double ld;
const ld eps = 1e-9;

struct P {
	ld x, y;
	P() {}
	P(ld _x, ld _y) : x(_x), y(_y) {}
	friend P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y); }
	friend P operator - (P a) { return P(-a.x, -a.y); }
	friend P operator - (P a, P b) { return a + -b; }
	friend P operator * (P a, ld b) { return P(a.x * b, a.y * b); }
	friend P operator / (P a, ld b) { return P(a.x / b, a.y / b); }
	friend ld operator * (P a, P b) { return a.x * b.x + a.y * b.y; }
	friend ld operator / (P a, P b) { return a.x * b.y - b.x * a.y; }
	ld a() { return atan2(y, x); }
	ld l() { return sqrt(x * x + y * y); }
	P perp() { return P(-y, x) / l(); }
};
struct L {
	P p, v; ld a;
	L() {}
	L(P _p, P _v) : p(_p), v(_v) { a = v.a(); }
	friend P operator * (L a, L b) { return a.p + a.v * (b.v / (a.p - b.p) / (a.v / b.v)); }
	friend bool operator < (L a, L b) {
		if (fabs(a.a - b.a) >= eps) return a.a < b.a;
		return a.v / (b.p - a.p) > 0;
	}
};

const int MN = 305;

int N, X[MN], Y[MN], p[MN * 2], nxt[MN];
L edg[MN * 2];
P Ans[2];

int vis[MN * 2];
L q1[MN * 2]; P q2[MN * 2]; int l, r;
inline bool Solve(int lb, int rb) {
	for (int i = 1; i <= N; ++i) vis[i] = 1, vis[N + i] = 0;
	for (int i = lb; i <= rb; ++i) vis[N + (i - 1) % N + 1] = 1;
	l = 1, r = 0;
	for (int I = 1; I <= 2 * N; ++I) if (vis[p[I]]) {
		L now = edg[p[I]];
		while (l < r && now.v / (q2[r] - now.p) < eps) --r;
		while (l < r && now.v / (q2[l + 1] - now.p) < eps) ++l;
		if (l <= r && fabs(q1[r].a - now.a) < eps) q1[r] = now;
		else q1[++r] = now;
		if (l < r) q2[r] = q1[r - 1] * now;
	}
	L now = q1[l];
	while (l < r && now.v / (q2[r] - now.p) < eps) --r;
	if (r - l <= 1) return 0;
	return 1;
}
P ret[MN];
inline bool check(ld rad) {
	for (int i = 1; i <= N; ++i)
		edg[N + i] = L(edg[i].p + edg[i].v.perp() * rad, -edg[i].v);
	std::sort(p + 1, p + 2 * N + 1, [](int i, int j) {
		return edg[i] < edg[j];
	});
	for (int i = 1, j = 1; i <= N; ++i) {
		while (j < i + N - 1 && Solve(i, j + 1)) ++j;
		Solve(i, nxt[i] = j), ret[i] = q2[r];
	}
	for (int i = 1; i <= N; ++i) {
		int dis = nxt[i] - i + 1, j = nxt[i] % N + 1;
		dis += nxt[j] - j + 1;
		if (dis >= N) {
			Ans[0] = ret[i], Ans[1] = ret[j];
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &X[i], &Y[i]);
	for (int i = 1; i <= N; ++i) edg[i] = L(P(X[i], Y[i]), P(X[i % N + 1], Y[i % N + 1]) - P(X[i], Y[i]));
	for (int i = 1; i <= 2 * N; ++i) p[i] = i;
	ld lb = 0, rb = 2e4, mid, ans = 0;
	while (rb - lb >= eps) {
		mid = (lb + rb) / 2;
		if (check(mid)) ans = mid, rb = mid;
		else lb = mid;
	}
	check(ans);
	printf("%.10lf\n", (db)(ans + eps));
	printf("%.10lf %.10lf\n", (db)Ans[0].x, (db)Ans[0].y);
	printf("%.10lf %.10lf\n", (db)Ans[1].x, (db)Ans[1].y);
	return 0;
}