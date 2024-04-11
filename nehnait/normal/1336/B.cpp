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

const int N = 1e5 + 7;
int x, y, z;
ll a[N], b[N], c[N], ans;

inline void upd(ll x, ll y, ll z) {
//	debug("%lld %lld %lld\n", x, y, z);
	ans = min(ans, (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x));
}

inline void work(ll *a, int x, ll *b, int y, ll *c, int z) {
	for (int i = 1, j, k; i <= x; i++) {
		j = lower_bound(b + 1, b + y + 1, a[i]) - b;
		if (j <= y) {
			k = lower_bound(c + 1, c + z + 1, (a[i] + b[j]) >> 1) - c;
			if (k <= z) upd(a[i], b[j], c[k]);
			if (k > 1) upd(a[i], b[j], c[k-1]);
		}
		if (j > 1) {
			k = lower_bound(c + 1, c + z + 1, (a[i] + b[j-1]) >> 1) - c;
			if (k <= z) upd(a[i], b[j-1], c[k]);
			if (k > 1) upd(a[i], b[j-1], c[k-1]);
		}
	}
}

inline void solve() {
	rd(x, y, z), rda(a, x), rda(b, y), rda(c, z);
	sort(a + 1, a + x + 1);
	sort(b + 1, b + y + 1);
	sort(c + 1, c + z + 1);
	ans = 4e18;
	work(a, x, b, y, c, z);
	work(b, y, c, z, a, x);
	work(c, z, a, x, b, y);
	print(ans);
}

int main() {
	int T;
	rd(T);
	while (T--) solve();
	return 0;
}