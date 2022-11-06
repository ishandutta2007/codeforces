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

const int N = 107;
int n, ans;
ll ax, ay, bx, by, xs, ys, t, mx, my, x[N], y[N];

int main() {
	rd(x[0]), rd(y[0]), rd(ax), rd(ay), rd(bx), rd(by);
	rd(xs), rd(ys), rd(t), mx = xs + t, my = ys + t;
	while (x[n] <= mx && y[n] <= my)
		++n, x[n] = x[n-1] * ax + bx, y[n] = y[n-1] * ay + by;
	for (int i = 0; i < n; i++)
		for (int j = -1; j <= 1; j += 2) {
			int cnt = 0, now = i;
			ll T = t;
			t -= abs(xs - x[i]) + abs(ys - y[i]);
//			dbg(t);
			while (t >= 0) {
				++cnt;
				now += j;
				if (now < 0 || now >= n) break;
				t -= abs(x[now-j] - x[now]) + abs(y[now-j] - y[now]);
//				dbg(t);
			}
//			debug("%d %d %d %d\n", i, j, now, cnt);
			ans = max(ans, cnt);
			t = T;
		}
	print(ans);
	return 0;
}