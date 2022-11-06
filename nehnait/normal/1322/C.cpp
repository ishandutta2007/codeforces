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

namespace Rd {
    inline bool gt() {
        int a = rand(), b = rand();
        while (a == b) a = rand(), b = rand();
        return a < b;
    }
    template <class I>
    inline I rd(I k) {
        I w = 1;
        while (w < k) w <<= 1;
        while (w >= k) {
            I o = 1, x = 0;
            while (o < k) o <<= 1, x = x << 1 | gt();
            w = x;
        }
        return w;
    }
    template <class I>
    inline I rdm(I l, I r) {
        return l == r ? l : l + rd(r - l + 1);
    }
    template <class I>
    inline void rdms(I *a, int n) {
        for (int i = n; i; i--) swap(a[i], a[rdm(1,i)]);
    }
}
using Rd::rdm;
using Rd::rdms;

const int N = 5e5 + 7;
int n, m, B, P;
ll a[N];
vi e[N];

inline int h(vi p) {
	sort(p.begin(), p.end());
	int ret = 0;
	for (int x : p) ret = (1ll * ret * B + x) % P;
	return ret;
}

inline void solve() {
	rd(n), rd(m), rda(a, n);
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1, x, y; i <= m; i++) rd(x), rd(y), e[y].pb(x);
	map<int, ll> p;
	for (int i = 1; i <= n; i++)
		if (e[i].size()) p[h(e[i])] += a[i];
	ll d = 0;
	for (auto o : p) d = d ? __gcd(d, o.se) : o.se;
	print(d);
}

int main() {
	srand(time(0));
	P = rdm((int)1e8, (int)1e9);
	B = rdm((int)1e7, (int)1e8);
	int T;
	rd(T);
	while (T--) solve();
	return 0;
}