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

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int c0 = 0, c2 = 0, S = 0;
		int l = s.length();
		for (int i = 0; i < l; i++) {
			if (s[i] == '0') c0++;
			if ((s[i] - '0') % 2 == 0) c2++;
			S += s[i] - '0';
		}
		if (c0 && c2 > 1 && S % 3 == 0) cout << "red" << endl;
		else cout << "cyan" << endl;
	}
	return 0;
}