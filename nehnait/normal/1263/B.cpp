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
 
inline bool cmp(pair< string, int > x, pair< string, int > y) {
	return x.se < y.se;
}
 
inline void solve() {
	int n, ans = 0, v[11], w[11];
	memset(v, 0, sizeof(v));
	memset(w, 0, sizeof(w));
	cin >> n;
	pair< string, int > a[11];
	for (int i = 1; i <= n; i++) cin >> a[i].fi, a[i].se = i;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		if (a[i].fi == a[i-1].fi) {
			++ans;
			w[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!w[i]) v[a[i].fi[0]-'0'] = 1;
	for (int i = 1; i <= n; i++)
		if (w[i]) {
			int t = 0;
			while (v[t]) ++t;
			a[i].fi[0] = t + '0';
			v[t] = 1;
		}
	cout << ans << endl;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i].fi << endl;
}
 
int main() {
	int T;
	cin >> T; 
	while (T--) solve();
	return 0;
}