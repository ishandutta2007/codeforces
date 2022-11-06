//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair <int, int>
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define vi vector <int>
#define pb push_back
#define pq priority_queue

#define dbg(x) cerr << #x" = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

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
	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	template <class I>
	inline void rd(I &x, I &y) {
		rd(x), rd(y);
	}
	template <class I>
	inline void rd(I &x, I &y, I &z) {
		rd(x), rd(y), rd(z);
	}
	template <class I>
	inline void rda(I *a, int n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
	}
	inline void rdc(char &c) {
		for (c = gc(); c < 33 || c > 126; c = gc());
	}
	inline void rds(char *s, int &x) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (x = 0; c >= 33 && c <= 126; s[++x] = c, c = gc());
		s[x+1] = '\0';
	}
	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	template <class I>
	inline void print(I x, I y) {
		print(x, ' '), print(y);
	}
	template <class I>
	inline void print(I x, I y, I z) {
		print(x, ' '), print(y, ' '), print(z);
	}
	inline void printc(char c) {
		pc(c);
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
using io::rda;
using io::rdc;
using io::rds;
using io::print;
using io::printc;
using io::prints;

const int P = 998244353, NP = 1e6 + 7;

struct modint {
    int x;
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
    template <class I>
    inline friend modint operator + (modint a, I b) { return a += b; }
    template <class I>
    inline friend modint operator - (modint a, I b) { return a -= b; }
    template <class I>
    inline friend modint operator * (modint a, I b) { return a *= b; }
    inline friend modint operator ^ (modint a, ll b) { return a ^= b; }
    template <class I>
    inline friend modint operator / (modint a, I b) { return a /= b; }
    inline friend bool operator == (modint a, int b) { return a.x == b; }
    inline friend bool operator != (modint a, int b) { return a.x != b; }
    inline friend bool operator < (modint a, int b) { return a.x < b; }
    inline friend bool operator <= (modint a, int b) { return a.x <= b; }
    inline friend bool operator > (modint a, int b) { return a.x > b; }
    inline friend bool operator >= (modint a, int b) { return a.x >= b; }
    inline friend bool operator == (modint a, modint b) { return a.x == b.x; }
    inline friend bool operator != (modint a, modint b) { return a.x != b.x; }
    inline friend bool operator < (modint a, modint b) { return a.x < b.x; }
    inline friend bool operator <= (modint a, modint b) { return a.x <= b.x; }
    inline friend bool operator > (modint a, modint b) { return a.x > b.x; }
    inline friend bool operator >= (modint a, modint b) { return a.x >= b.x; }
    inline bool operator ! () { return !x; }
    inline modint operator - () { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }

modint p[NP], v[NP], vp[NP];
inline void init(int n) {
    p[0] = v[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] * i;
    vp[n] = 1 / p[n];
    for (int i = n; i; i--) v[i] = vp[i] * p[i-1], vp[i-1] = vp[i] * i;
}
inline modint binom(int n, int m) {
    return n < m ? 0 : p[n] * vp[m] * vp[n-m];
}

int n, m, t;
ll x, a[57], b[57];
modint ans[57];
unordered_map<ll, modint> f[57][57];

inline void ins(ll x) {
	for (int i = m - 1; ~i; i--)
		if (x >> i & 1) {
			if (b[i]) x ^= b[i];
			else return a[++t] = b[i] = x, void();
		}
}

void dfs1(int o, ll x) {
	if (o == t + 1) return ans[__builtin_popcountll(x)] += 1, void();
	dfs1(o + 1, x), dfs1(o + 1, x ^ a[o]);
}

int main() {
	rd(n, m);
	for (int i = 1; i <= n; i++) rd(x), ins(x);
	if (t <= 25) dfs1(1, 0);
	else {
		for (int i = m - 1; ~i; i--)
			for (int j = 1; j <= t; j++)
				if (b[i] && b[i] != a[j] && (a[j] >> i & 1)) a[j] ^= b[i];
		
		ll w = 0;
		for (int i = 0; i < m; i++)
			if (!b[i]) w |= 1ll << i;
//		dbg(w);
		f[0][0][0] = 1;
		for (int i = 1; i <= t; i++) {
			for (int j = 0; j < i; j++) f[i][j] = f[i-1][j];
			for (int j = 0; j < i; j++) {
				for (auto k : f[i-1][j])
//					debug("f[%d][%d][%d] = %d\n", i - 1, j, k.fi, k.se.x),
//					debug("%lld <- %d\n", k.fi^(a[i]&w), k.fi),
					f[i][j+1][k.fi^(a[i]&w)] += k.se;
			}
		}
		for (int j = 0; j <= t; j++)
			for (auto k : f[t][j])
//				debug("f[%d][%d][%lld] = %d\n", t, j, k.fi, k.se.x),
				ans[j+__builtin_popcountll(k.fi)] += k.se;
	}
	modint now = (modint)2 ^ (n - t);
	for (int i = 0; i <= m; i++) print(ans[i] * now, ' ');
	return 0;
}