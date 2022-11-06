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

#define vi vector< int >
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

const int N = 1e3 + 7;
int n, f[N], t;
ll a[N], b[N];
pair< ll, int > p[N];
pair< ll, pi > q[N*N];

int get(int x) {
	return x == f[x] ? x : (f[x] = get(f[x]));
}

inline ll S(int i, int j) {
	return abs(a[i] - a[j]) * abs(a[i] - a[j]) + abs(b[i] - b[j]) * abs(b[i] - b[j]);
}

inline void work(int x) {
	for (int i = 1; i <= n; i++) p[i] = mp(S(x, i), i);
	sort(p + 1, p + n + 1);
	for (int i = 1; i < n; i++)
		if (p[i].fi == p[i+1].fi)
			f[get(p[i].se)] = get(p[i+1].se);
}

int main() {
	rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]), rd(b[i]), f[i] = i;
	for (int i = 1; i <= n; i++) work(i);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			q[++t] = mp(S(i, j), mp(i, j));
	sort(q + 1, q + t + 1);
	for (int i = 1; i < t; i++)
		if (q[i].fi == q[i+1].fi) {
			int j = i + 1;
			int a1 = get(q[i].se.fi), b1 = get(q[i].se.se);
			int a2 = get(q[j].se.fi), b2 = get(q[j].se.se);
			if (a1 == a2) f[b1] = b2;
			else if (a1 == b2) f[b1] = a2;
			else if (b1 == a2) f[a1] = b2;
			else if (b1 == b2) f[a1] = a2;
			else if (a1 == b1) f[a2] = b2;
			else if (a2 == b2) f[a1] = b1;
			else f[a1] = a2, f[b1] = b2; 
		}
	vi ans;
	for (int i = 1; i <= n; i++)
		if (get(i) == get(1)) ans.pb(i);
	print(ans.size());
	for (ui i = 0; i < ans.size(); i++) print(ans[i], ' ');
	return 0;
}