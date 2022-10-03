// luogu

#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 100005, MM = 100005;

inline int R(int x) { return x < 0 ? -x : x; }
struct dat {
	int a, b;
	dat() { a = 1, b = 0; }
	dat(int t) { if (t) a = 0, b = 1; else a = 1, b = 0; }
	dat(int a, int b) : a(a), b(b) {}
	inline friend dat operator + (const dat &p, const dat &q) {
		return dat((p.a + q.a) % Mod, (p.b + q.b) % Mod);
	}
	inline friend dat operator * (const dat &p, const dat &q) {
		return dat(((LL)p.a * q.a + (LL)p.b * q.b) % Mod, ((LL)p.a * q.b + (LL)p.b * q.a) % Mod);
	}
	inline dat & operator *= (const dat &q) { return *this = *this * q; }
} Ans;
int N, M, k[MN], p[MN], q[MN];
int loop[MM], deg[MM], vis[MM];
std::vector<int> V[MM];
inline int gNxt(int u, int f) {
	for (auto i : V[u]) if (k[i] == 2 && i != f) return i;
	return 0;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &k[i]);
		if (k[i] == 1) {
			scanf("%d", &p[i]);
			int a = R(p[i]);
			++loop[a];
			V[a].push_back(i);
		} else {
			scanf("%d%d", &p[i], &q[i]);
			int a = R(p[i]), b = R(q[i]);
			if (a == b) {
				vis[a] = 1;
				Ans *= p[i] == q[i] ? dat(1, 1) : dat(0, 2);
			} else {
				++deg[a], ++deg[b];
				V[a].push_back(i);
				V[b].push_back(i);
			}
		}
	}
	for (int i = 1; i <= M; ++i) if (!vis[i]) {
		if (deg[i] == 2) continue;
		if (!deg[i]) {
			vis[i] = 1;
			if (!loop[i]) Ans *= dat(2, 0);
			else if (loop[i] == 1) Ans *= dat(1, 1);
			else Ans *= p[V[i][0]] == p[V[i][1]] ? dat(2, 0) : dat(0, 2);
		} else {
			static int stk[MM]; int tp = 0;
			stk[++tp] = i;
			int x = gNxt(i, 0), y = x, z = i;
			x = R(p[x]) ^ R(q[x]) ^ z;
			while (x) {
				stk[++tp] = x;
				z = x, y = x = gNxt(x, y);
				x = x ? R(p[x]) ^ R(q[x]) ^ z : 0;
			} stk[tp + 1] = 0;
//			for (int j = 1; j <= tp; ++j) printf("%d, ", stk[j]); puts("");
			dat now0, now1;
			if (loop[i]) {
				int o = p[k[V[i][0]] == 1 ? V[i][0] : V[i][1]] < 0;
				if (o) now0 = dat(0, 1);
				else now1 = dat(0, 1);
			}
			y = 0;
			for (int j = 1; j < tp; ++j) {
				y = gNxt(stk[j], y);
				int opa, opb;
				if (R(p[y]) == stk[j + 1]) opa = q[y] < 0, opb = p[y] < 0;
				else opa = p[y] < 0, opb = q[y] < 0;
				dat tmp0 = now0 * dat(opa || opb) + now1 * dat(!opa || opb);
				dat tmp1 = now0 * dat(opa || !opb) + now1 * dat(!opa || !opb);
				now0 = tmp0, now1 = tmp1;
			}
			if (loop[stk[tp]]) {
				int u = stk[tp];
				int o = p[k[V[u][0]] == 1 ? V[u][0] : V[u][1]] < 0;
				if (o) now0 *= dat(0, 1);
				else now1 *= dat(0, 1);
			}
			Ans *= now0 + now1;
			for (int j = 1; j <= tp; ++j) vis[stk[j]] = 1;
		}
	}
	for (int i = 1; i <= M; ++i) if (!vis[i]) {
		static int stk[MM]; int tp = 0;
		stk[++tp] = i;
		int x = gNxt(i, 0), y = x, z = i;
		x = R(p[x]) ^ R(q[x]) ^ z;
		while (x != i) {
			stk[++tp] = x;
			z = x, y = x = gNxt(x, y);
			x = x ? R(p[x]) ^ R(q[x]) ^ z : 0;
		} stk[tp + 1] = stk[1];
//		for (int j = 1; j <= tp; ++j) printf("%d, ", stk[j]); puts("");
		dat now00, now01(0, 0), now10(0, 0), now11;
		y = 0;
		for (int j = 1; j <= tp; ++j) {
			y = gNxt(stk[j], y);
			int opa, opb;
			if (R(p[y]) == stk[j + 1]) opa = q[y] < 0, opb = p[y] < 0;
			else opa = p[y] < 0, opb = q[y] < 0;
			dat tmp00, tmp01, tmp10, tmp11;
			tmp00 = now00 * dat(opa || opb) + now01 * dat(!opa || opb);
			tmp01 = now00 * dat(opa || !opb) + now01 * dat(!opa || !opb);
			tmp10 = now10 * dat(opa || opb) + now11 * dat(!opa || opb);
			tmp11 = now10 * dat(opa || !opb) + now11 * dat(!opa || !opb);
			now00 = tmp00, now01 = tmp01;
			now10 = tmp10, now11 = tmp11;
		}
		Ans *= now00 + now11;
		for (int j = 1; j <= tp; ++j) vis[stk[j]] = 1;
	}
	printf("%d\n", Ans.b);
	return 0;
}

// luogu