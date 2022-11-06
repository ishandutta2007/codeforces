//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair< int, int >
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define pq priority_queue
#define pb push_back
#define vi vector< int >
#define si set< int >::iterator

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);

using namespace std;

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
	template<class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	inline void rds(char *s, int &x) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (x = 0; c >= 33 && c <= 126; s[++x] = c, c = gc());
		s[x+1] = '\0';
	}
	template<class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	inline void prints(string s) {
		int x = s.length();
		while (t < x) pc(s[t++]);
		pc('\n'), t = 0;
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::rds;
using io::print;
using io::prints;

struct modint {
    int x;
    #define P 1000000007
    inline modint(int x = 0) : x(x) {}
    inline modint &operator = (int o) { return x = o, *this; }
    inline modint &operator += (modint o) { return x = x + o.x >= P ? x + o.x - P : x + o.x, *this; }
    inline modint &operator -= (modint o) { return x = x - o.x < 0 ? x - o.x + P : x - o.x, *this; }
    inline modint &operator *= (modint o) { return x = 1ll * x * o.x % P, *this; }
    inline modint &operator ^= (ll b) {
        modint a = *this, c;
        if (!~b) b = P - 2;
        c.x = 1 % P;
        while (b) {
            if (b & 1) c *= a;
            a *= a, b >>= 1;
        }
        return x = c.x, *this;
    }
    inline modint &operator /= (modint o) { return *this *= o ^= -1; }
    inline modint &operator += (int o) { return x = x + o >= P ? x + o - P : x + o, *this; }
    inline modint &operator -= (int o) { return x = x - o < 0 ? x - o + P : x - o, *this; }
    inline modint &operator *= (int o) { return x = 1ll * x * o % P, *this; }
    inline modint &operator /= (int o) { modint y = modint(o); return *this *= y ^= -1; }
    template<class I>
    inline friend modint operator + (modint a, I b) { return a += b; }
    template<class I>
    inline friend modint operator - (modint a, I b) { return a -= b; }
    template<class I>
    inline friend modint operator * (modint a, I b) { return a *= b; }
    inline friend modint operator ^ (modint a, ll b) { return a ^= b; }
    template<class I>
    inline friend modint operator / (modint a, I b) { return a /= b; }
    inline friend bool operator == (modint a, int b) { return a.x == b; }
    inline bool operator ! () { return !x; }
    inline modint operator - () { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }

const int N = 1e5 + 7;
int n, C, l[N], r[N], d[N], f[N], s[N], son[N], dfn[N], rnk[N], top[N], num;
modint g[N], vg[N], p, vp, now, A1, A2, A3, ans, c1[N], c2[N];
vi e[N], L[N], R[N];

void dfs(int x) {
	s[x] = 1;
	for (ui i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y == f[x]) continue;
		d[y] = d[x] + 1;
		f[y] = x;
		dfs(y);
		s[x] += s[y];
		if (s[y] > s[son[x]]) son[x] = y; 
	}
}

void dfs(int x, int p) {
	top[x] = p;
	dfn[x] = ++num;
	rnk[num] = x;
	if (!son[x]) return;
	dfs(son[x], p);
	for (ui i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y == f[x] || y == son[x]) continue;
		dfs(y, y);
	}
}

inline void add(modint *c, int x, modint k) {
	while (x <= n + 1) c[x] += k, x += x & -x;
}

inline modint ask(modint *c, int x) {
	modint ret = 0;
	while (x) ret += c[x], x -= x & -x;
	return ret;
}

inline void Add(int x, modint k) {
	while (x) {
		add(c1, dfn[top[x]], k);
		add(c1, dfn[x] + 1, -k);
		add(c2, dfn[top[x]], k * dfn[top[x]]);
		add(c2, dfn[x] + 1, -k * (dfn[x] + 1));
		x = f[top[x]];
	}
}

inline modint Ask(int x) {
	modint ret = -(ask(c1, 1) * 2 - ask(c2, 1));
	while (x) {
		ret += ask(c1, dfn[x]) * (dfn[x] + 1) - ask(c2, dfn[x]);
		ret -= ask(c1, dfn[top[x]] - 1) * dfn[top[x]] - ask(c2, dfn[top[x]] - 1);
		x = f[top[x]];
	}
	return ret;
}

int main() {
//	fl("1");
	rd(n), p = 1;
	for (int i = 1; i <= n; i++) {
		rd(l[i]), rd(r[i]);
		g[i] = r[i] - l[i] + 1;
		vg[i] = g[i] ^ -1;
		p *= g[i];
		C = max(C, r[i]);
		L[l[i]].pb(i), R[r[i]].pb(i);
	}
	for (int i = 1, x, y; i < n; i++)
		rd(x), rd(y), e[x].pb(y), e[y].pb(x);
	vp = p ^ -1;
	dfs(1);
	dfs(1, 1);
	for (int c = 1; c <= C; c++) {
		for (ui i = 0; i < L[c].size(); i++) {
			int x = L[c][i];
			A1 += d[x] * vg[x];
			A2 += vg[x];
			A3 += d[x] * vg[x] * vg[x];
			now += Ask(x) * vg[x];
			Add(x, vg[x]);
//			for (int j = 0; j <= n + 1; j++) print(ask(c1, j) * (j + 1) - ask(c2, j), " \n"[j==n+1]);
		}
		ans += A1 * A2 - A3 - 2 * now;
//		print(A1);
//		print(A2);
//		print(A3);
//		print(now);
//		print(ans);
		for (ui i = 0; i < R[c].size(); i++) {
			int x = R[c][i];
			A1 -= d[x] * vg[x];
			A2 -= vg[x];
			A3 -= d[x] * vg[x] * vg[x];
			Add(x, -vg[x]);
			now -= Ask(x) * vg[x];
//			for (int j = 0; j <= n + 1; j++) print(ask(c1, j) * (j + 1) - ask(c2, j), " \n"[j==n+1]);
		}
	}
	print(ans * p);
	return 0;
}