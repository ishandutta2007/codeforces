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

const int N = 5e5 + 7;
int n, a[N], b[N], f[N][21], ans[N];

inline int ask(int l, int r) {
	int k = log2(r - l + 1);
	return a[f[l][k]] < a[f[r-(1<<k)+1][k]] ? f[l][k] : f[r-(1<<k)+1][k];
}

inline ll solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return a[l];
	int o = ask(l, r);
	ll L = 1ll * (o - l + 1) * a[o] + solve(o + 1, r);
	ll R = 1ll * (r - o + 1) * a[o] + solve(l, o - 1);
	b[o] = L < R;
	return max(L, R);
}

inline void work(int l, int r) {
	if (l > r) return;
	if (l == r) return ans[l] = a[l], void();
	int o = ask(l, r);
	if (b[o]) {
		for (int i = o; i <= r; i++) ans[i] = a[o];
		work(l, o - 1);
	} else {
		for (int i = l; i <= o; i++) ans[i] = a[o];
		work(o + 1, r);
	}
}

int main() {
	rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]), f[i][0] = i;
	int w = log2(n);
	for (int j = 1; j <= w; j++)
		for (int i = 1; i+(1<<(j-1)) <= n; i++)
			f[i][j] = a[f[i][j-1]] < a[f[i+(1<<(j-1))][j-1]] ? f[i][j-1] : f[i+(1<<(j-1))][j-1];
	solve(1, n);
	work(1, n);
	for (int i = 1; i <= n; i++) print(ans[i], " \n"[i==n]);
	return 0;
}