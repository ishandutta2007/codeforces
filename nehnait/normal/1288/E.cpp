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
using io::rds;
using io::print;
using io::prints;

const int N = 3e5 + 7;
int n, m, p[N], c1[N], c2[N], v[N], ans[N];

inline void add(int *c, int n, int x, int o) {
	while (x <= n) c[x] += o, x += x & -x;
}

inline int ask(int *c, int x) {
	int o = 0;
	while (x) o += c[x], x -= x & -x;
	return o;
}

int main() {
	rd(n), rd(m);
	for (int i = 1, x; i <= m; i++) {
		rd(x);
		if (!v[x]) {
			v[x] = 1;
			ans[x] = x + ask(c1, n) - ask(c1, x);
			add(c1, n, x, 1);
			add(c2, m, p[x] = i, 1);
			continue;
		}
		ans[x] = max(ans[x], 1 + ask(c2, i - 1) - ask(c2, p[x]));
		add(c2, m, p[x], -1);
		add(c2, m, p[x] = i, 1);
	}
	for (int x = 1; x <= n; x++)
		if (!v[x]) ans[x] = x + ask(c1, n) - ask(c1, x);
		else ans[x] = max(ans[x], 1 + ask(c2, m) - ask(c2, p[x]));
	for (int x = 1; x <= n; x++)
		print(v[x] ? 1 : x, ' '), print(ans[x]);
	return 0;
}