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

const int N = 63;
int n, m;
char s[N][N];

inline bool pd() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'A') return 0;
	return 1;
}

inline bool pd0() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'P') return 0;
	return 1;
}

inline bool pd1() {
	bool ok = 1;
	for (int i = 1; i <= n; i++)
		if (s[i][1] == 'P') ok = 0;
	if (ok) return 1;
	
	ok = 1;
	for (int i = 1; i <= n; i++)
		if (s[i][m] == 'P') ok = 0;
	if (ok) return 1;
	
	ok = 1;
	for (int i = 1; i <= m; i++)
		if (s[1][i] == 'P') ok = 0;
	if (ok) return 1;
	
	ok = 1;
	for (int i = 1; i <= m; i++)
		if (s[n][i] == 'P') ok = 0;
	if (ok) return 1;
	
	return 0;
}

inline bool pd4() {
	for (int i = 1; i <= n; i++)
		if (s[i][1] == 'A' || s[i][m] == 'A') return 0;
	for (int i = 1; i <= m; i++)
		if (s[1][i] == 'A' || s[n][i] == 'A') return 0;
	return 1;
}

inline bool pd2() {
	if (s[1][1] == 'A') return 1;
	if (s[1][m] == 'A') return 1;
	if (s[n][1] == 'A') return 1;
	if (s[n][m] == 'A') return 1;
	for (int i = 2; i < n; i++) {
		bool ok = 1;
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'P') ok = 0;
		if (ok) return 1;
	}
	for (int j = 2; j < m; j++) {
		bool ok = 1;
		for (int i = 1; i <= n; i++)
			if (s[i][j] == 'P') ok = 0;
		if (ok) return 1;
	}
	return 0;
}

inline void solve() {
	rd(n), rd(m);
	for (int i = 1; i <= n; i++) rds(s[i], m);
	if (pd()) return prints("MORTAL"), void();
	if (pd0()) return print(0), void();
	if (pd1()) return print(1), void();
	if (pd4()) return print(4), void();
	if (pd2()) return print(2), void();
	print(3);
}

int main() {
	int T;
	rd(T);
	while (T--) solve();
	return 0;
}