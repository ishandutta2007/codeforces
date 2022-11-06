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
int m, n, k, t, mx, a[N];
vector< pi > e[N];

inline int pd(int o) {
	vector< pi > p;
	for (int i = mx; i > a[o]; i--)
		for (ui j = 0; j < e[i].size(); j++)
			p.pb(e[i][j]);
	p.pb(mp(n + 1, n + 1));
	sort(p.begin(), p.end());
	int x = 0, w = 0, ans = 0;
	for (ui i = 0; i < p.size(); i++) {
		int l = p[i].fi, r = p[i].se;
		if (l > w) {
			ans += (w - x) * 3 + (l - w - 1);
			x = l - 1;
		}
		w = max(w, r);
	}
	return ans + 1;
}

int main() {
	rd(m), rd(n), rd(k), rd(t);
	for (int i = 1; i <= m; i++) rd(a[i]);
	sort(a + 1, a + m + 1);
	reverse(a + 1, a + m + 1);
	for (int i = 1; i <= k; i++) {
		int l, r, x;
		rd(l), rd(r), rd(x);
		e[x].pb(mp(l, r));
		mx = max(mx, x);
	}
	int l = 1, r = m + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (pd(mid) <= t) l = mid + 1;
		else r = mid;
	}
	print(l - 1);
	return 0;
}