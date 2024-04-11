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

const int N = 3e3 + 7;
int n, fa[N], s[N], l[N], r[N], k, p[N];
vi e[N];
ll f[N][N], ans;

void dfs2(int x, int fa, int X, int Y) {
	for (auto y : e[x])
		if (y != fa) {
			f[y][X] = f[X][y] = max(f[X][x], f[Y][y]) + s[y] * (n - s[Y]);
			dfs2(y, x, X, Y);
		}
}

void dfs1(int x, int fa) {
	s[x] = 1, l[x] = ++k, p[k] = x;
	for (auto y : e[x])
		if (y != fa) {
			::fa[y] = x;
			dfs1(y, x), s[x] += s[y];
			f[y][x] = f[x][y] = s[y] * (n - s[y]);
			dfs2(y, x, x, y);
		}
	r[x] = k;
	for (auto y : e[x])
		if (y != fa)
			for (auto z : e[x])
				if (z != fa && z != y)
					for (int i = l[y]; i <= r[y]; i++)
						for (int j = l[z]; j <= r[z]; j++)
							f[p[i]][p[j]] = f[p[j]][p[i]] = max(f[p[i]][::fa[p[j]]], f[::fa[p[i]]][p[j]]) + s[p[i]] * s[p[j]];
}

int main() {
	rd(n);
	for (int i = 1, x, y; i < n; i++)
		rd(x), rd(y), e[x].pb(y), e[y].pb(x);
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans = max(ans, f[i][j]);
	print(ans);
	return 0;
}