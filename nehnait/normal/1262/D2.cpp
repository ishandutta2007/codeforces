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

const int N = 2e5 + 7;
int n, m, a[N], c[N], ans[N];
pq< pi > q;
pair< pi, int > p[N];

inline void add(int x) {
	while (x <= n) c[x]++, x += x & -x;
}

inline int ask(int x) {
	int k = 0;
	while (x) k += c[x], x -= x & -x;
	return k;
}

inline int qry(int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ask(mid) < x) l = mid + 1;
		else r = mid;
	}
	return a[l];
}

int main() {
	rd(n);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		q.push(mp(a[i], -i));
	}
	rd(m);
	for (int i = 1, x, y; i <= m; i++) {
		rd(x), rd(y), p[i] = mp(mp(x, y), i);
	}
	sort(p + 1, p + m + 1);
	int t = 0;
	for (int i = 1; i <= m; i++) {
		while (t < p[i].fi.fi) {
			int x = -q.top().se;
			q.pop();
			add(x);
			++t;
		}
		ans[p[i].se] = qry(p[i].fi.se);
	}
	for (int i = 1; i <= m; i++) print(ans[i]);
	return 0;
}