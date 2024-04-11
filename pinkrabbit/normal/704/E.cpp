#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

typedef long long LL;
struct Frac {
	LL c, d;
	Frac() {}
	Frac(LL x) : c(x), d(1) {}
	Frac(LL _c, LL _d) { c = _c, d = _d; if (d < 0) c = -c, d = -d; }
	friend bool operator < (Frac A, Frac B) { return A.c * B.d < B.c * A.d; }
	friend bool operator == (Frac A, Frac B) { return A.c * B.d == B.c * A.d; }
	friend Frac operator * (int A, Frac B) { return Frac(B.c * A, B.d); }
	friend Frac operator + (Frac A, Frac B) {
		if (A.d == B.d) Frac(A.c + B.c, A.d);
		return Frac(A.c * B.d + B.c * A.d, A.d * B.d);
	}
};

const int MN = 100005, MQ = 100005, MS = 3200005;

int N, Q, qu[MQ], qv[MQ], qt[MQ], qc[MQ];
std::vector<int> G[MN];
int faz[MN], dep[MN], siz[MN], son[MN], top[MN];
void DFS0(int u, int fz) {
	dep[u] = dep[faz[u] = fz] + 1, siz[u] = 1;
	for (auto v : G[u]) if (v != fz) {
		DFS0(v, u), siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS1(int u, int t) {
	top[u] = t;
	if (son[u]) DFS1(son[u], t);
	for (auto v : G[u]) if (v != faz[u] && v != son[u]) DFS1(v, v);
}

Frac ql[MS], qr[MS]; int qk[MS], qb[MS], cnt;
std::vector<int> V[MN];

inline int Dist(int x, int y) {
	int ans = dep[x] + dep[y];
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = faz[top[x]];
	}
	return ans - 2 * std::min(dep[x], dep[y]);
}
inline void Add(int x, int y, int t, int c) {
	int dis = Dist(x, y), dx = 0, dy = dis;
	t *= c;
	while (top[x] != top[y]) {
		++cnt;
		if (dep[top[x]] > dep[top[y]]) {
			ql[cnt] = Frac(t + dx, c);
			dx += dep[x] - dep[top[x]] + 1;
			qr[cnt] = Frac(t + dx, c);
			qk[cnt] = -c;
			qb[cnt] = dx + t;
			V[top[x]].push_back(-cnt);
			V[top[x]].push_back(cnt);
			x = faz[top[x]];
		} else {
			qr[cnt] = Frac(t + dy, c);
			dy -= dep[y] - dep[top[y]] + 1;
			ql[cnt] = Frac(t + dy, c);
			qk[cnt] = c;
			qb[cnt] = -(dy + t);
			V[top[y]].push_back(-cnt);
			V[top[y]].push_back(cnt);
			y = faz[top[y]];
		}
	}
	++cnt;
	ql[cnt] = Frac(t + dx, c);
	qr[cnt] = Frac(t + dy, c);
	if (dep[x] < dep[y]) {
		qk[cnt] = c;
		qb[cnt] = dep[x] - dep[top[x]] + 1 - dx - t;
	} else {
		qk[cnt] = -c;
		qb[cnt] = dep[x] - dep[top[x]] + 1 + dx + t;
	}
	V[top[x]].push_back(-cnt);
	V[top[x]].push_back(cnt);
}

double Ans;
Frac T;
struct cmp { bool operator () (int i, int j) {
	Frac iz = qk[i] * T + qb[i], jz = qk[j] * T + qb[j];
	if (iz == jz) return i < j;
	return iz < jz;
} };
std::set<int, cmp> st;
inline void Solve(int u) {
	std::sort(V[u].begin(), V[u].end(), [](int i, int j) {
		Frac iz = i < 0 ? ql[-i] : qr[i], jz = j < 0 ? ql[-j] : qr[j];
		if (iz == jz) return i < j;
		return iz < jz;
	});
	st.clear();
	int o = 0; Frac isct;
	auto chk = [&](int i, int j) {
		Frac lb = std::max(ql[i], ql[j]);
		Frac rb = std::min(qr[i], qr[j]);
		if (qk[i] == qk[j]) {
			if (qb[i] != qb[j]) return ;
			if (!o) o = 1, isct = lb;
			else isct = std::min(isct, lb);
		} else {
			Frac z(qb[i] - qb[j], qk[j] - qk[i]);
			if (z < lb || rb < z) return ;
			if (!o) o = 1, isct = z;
			else isct = std::min(isct, z);
		}
	};
	for (int id : V[u]) {
		T = id < 0 ? ql[-id] : qr[id];
		if (o && !(T < isct)) break;
		if (id < 0) {
			id = -id;
			auto it = st.insert(id).first;
			auto lst = it, nxt = it;
			if (lst == st.begin()) lst = st.end();
			else --lst;
			++nxt;
			if (lst != st.end()) chk(id, *lst);
			if (nxt != st.end()) chk(id, *nxt);
		} else {
			auto it = st.erase(st.lower_bound(id));
			if (it == st.end() || it == st.begin()) continue;
			auto jt = it; --jt;
			chk(*it, *jt);
		}
	}
	if (o) Ans = std::min(Ans, isct.c / (double)isct.d);
}

int main() {
	scanf("%d%d", &N, &Q), Ans = 1e99;
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	DFS0(1, 0), DFS1(1, 1);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d%d%d", &qt[i], &qc[i], &qu[i], &qv[i]);
		Add(qu[i], qv[i], qt[i], qc[i]);
	}
	for (int i = 1; i <= N; ++i) if (i == top[i]) Solve(i);
	if (Ans > 1e98) puts("-1");
	else printf("%.10lf\n", Ans);
	return 0;
}