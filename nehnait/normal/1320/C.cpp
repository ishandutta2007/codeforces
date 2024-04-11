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
	inline void rda(I *a, int &n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
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
using io::rds;
using io::print;
using io::prints;

const int N = 2e5 + 7, M = 1e6 + 1;
const ll inf = 1e18;
int n, m, k;
ll a[M], b[M];
vector<pi> p[M];

struct T {
    int l, r;
    ll x, z;
} t[M*5];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) return t[p].x = -b[l], void();
    build(ls, l, md), build(rs, md + 1, r);
    t[p].x = max(t[ls].x, t[rs].x);
}

void spd(int p) {
    if (t[p].z) {
        t[ls].x += t[p].z;
        t[ls].z += t[p].z;
        t[rs].x += t[p].z;
        t[rs].z += t[p].z;
        t[p].z = 0;
    }
}

void add(int p, int l, int r, ll k) {
    if (t[p].l >= l && t[p].r <= r) return t[p].x += k, t[p].z += k, void();
    spd(p);
    if (l <= md) add(ls, l, r, k);
    if (r > md) add(rs, l, r, k);
    t[p].x = max(t[ls].x, t[rs].x);
}

int main() {
	rd(n), rd(m), rd(k);
	for (int i = 1; i < M; i++) a[i] = b[i] = inf;
	for (int i = 1, x, y; i <= n; i++)
		rd(x), rd(y), a[x] = min(a[x], 1ll * y);
	for (int i = 1, x, y; i <= m; i++)
		rd(x), rd(y), b[x] = min(b[x], 1ll * y);
	for (int i = 1, x, y, z; i <= k; i++)
		rd(x), rd(y), rd(z), p[x].pb(mp(y, z));
	build(1, 1, M - 1);
	ll ans = -inf;
	for (int i = 1; i < M; i++) {
		ans = max(ans, t[1].x - a[i]);
		for (pi o : p[i]) if (o.fi != M - 1) add(1, o.fi + 1, M, o.se);
	}
	print(ans);
    return 0;
}