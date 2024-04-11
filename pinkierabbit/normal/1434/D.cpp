#include <cstdio>
#include <algorithm>
#include <vector>

namespace io {
	const int SI = 1 << 21 | 1;
	char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
	int f, t;
	#define gc() (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin), IS == IT ? EOF : *IS++) : *IS++)
	inline void flush() {
		fwrite(OB, 1, OS - OB, stdout), OS = OB;
	}
	inline void pc(char x) {
		*OS++ = x;
		if (OS == OT) flush();
	}
	
	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	
	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::print;

const int MN = 500005;

int N;
int eu[MN], ev[MN], ew[MN];
std::vector<int> G[MN];

int par[MN], dep[MN], col[MN];
int oldf[MN], ordf[MN], oidf[MN], odfc;
int edfn[MN], eidf[MN * 2], edfc;
void DFS(int u, int p) {
	dep[u] = dep[par[u] = p] + 1;
	oidf[oldf[u] = ++odfc] = u;
	eidf[edfn[u] = ++edfc] = u;
	for (int i : G[u]) {
		int v = eu[i] ^ ev[i] ^ u;
		if (v == p) continue;
		col[v] = col[u] ^ ew[i];
		DFS(v, u);
		eidf[++edfc] = u;
	}
	ordf[u] = odfc;
}
inline int mindep(int u, int v) {
	return dep[u] < dep[v] ? u : v;
}
int Lg[MN * 2], ST[20][MN * 2];
void BuildST() {
	Lg[0] = -1;
	for (int i = 1; i <= edfc; ++i) {
		ST[0][i] = eidf[i];
		Lg[i] = Lg[i >> 1] + 1;
	}
	for (int j = 0; 2 << j <= edfc; ++j)
		for (int i = 2 << j; i <= edfc; ++i)
			ST[j + 1][i] = mindep(ST[j][i - (1 << j)], ST[j][i]);
}
inline int LCA(int u, int v) {
	int l = edfn[u], r = edfn[v];
	if (l > r) std::swap(l, r);
	int j = Lg[r - l + 1];
	return mindep(ST[j][l + (1 << j) - 1], ST[j][r]);
}
inline int Dist(int u, int v) {
	if (!u || !v) return -1;
	return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
const int MS = 1 << 20 | 7;
struct dat {
	int u, v, d;
	dat() {
		u = v = 0;
		d = -1;
	}
	dat(int x, int y) {
		u = x, v = y;
		d = Dist(x, y);
	}
	dat(int x, int y, int z) {
		u = x, v = y, d = z;
	}
	friend bool operator < (dat p, dat q) {
		return p.d < q.d;
	}
	friend dat operator + (dat p, dat q) {
		dat r = std::max(p, q);
		r = std::max(r, dat(p.u, q.u));
		r = std::max(r, dat(p.u, q.v));
		r = std::max(r, dat(p.v, q.u));
		r = std::max(r, dat(p.v, q.v));
		return r;
	}
} tr0[MS], tr1[MS];
int rev[MS];
inline void P(int i) { std::swap(tr0[i], tr1[i]), rev[i] ^= 1; }
inline void Pushdown(int i) {
	if (rev[i]) P(li), P(ri), rev[i] = 0;
}
void Build(int i, int l, int r) {
	if (l == r) {
		int u = oidf[l];
		if (col[u])
			tr1[i] = dat(u, u, 0);
		else
			tr0[i] = dat(u, u, 0);
		return ;
	}
	Build(ls), Build(rs);
	tr0[i] = tr0[li] + tr0[ri];
	tr1[i] = tr1[li] + tr1[ri];
}
void Mdf(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i);
	Pushdown(i);
	Mdf(ls, a, b), Mdf(rs, a, b);
	tr0[i] = tr0[li] + tr0[ri];
	tr1[i] = tr1[li] + tr1[ri];
}

int main() {
	rd(N);
	for (int i = 1; i <= N - 1; ++i) {
		rd(eu[i]), rd(ev[i]), rd(ew[i]);
		G[eu[i]].push_back(i);
		G[ev[i]].push_back(i);
	}
	DFS(1, 0);
	BuildST();
	Build(1, 1, N);
	int Q;
	rd(Q);
	while (Q--) {
		int id;
		rd(id);
		int u = dep[eu[id]] > dep[ev[id]] ? eu[id] : ev[id];
		Mdf(1, 1, N, oldf[u], ordf[u]);
		print(std::max(tr0[1].d, tr1[1].d));
	}
	return 0;
}