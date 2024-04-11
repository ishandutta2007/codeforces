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
int n, a[N], f[N][N][N];

inline void upd(int &x, int y) {
	x = min(x, y);
}

int main() {
	rd(n);
	if (n == 1) return print(0), 0;
	for (int i = 1; i <= n; i++) rd(a[i]);
	memset(f, 0x3f, sizeof(f));
	
	if (a[1]) {
		if (a[1] & 1) {
			upd(f[1][0][a[1]], 0);
		} else {
			upd(f[1][1][a[1]], 0);
		}
	} else {
		for (a[1] = 1; a[1] <= n; a[1]++) {
			if (a[1] & 1) {
				upd(f[1][0][a[1]], 0);
			} else {
				upd(f[1][1][a[1]], 0);
			}
		}
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= min(i - 1, n >> 1); j++)
			for (int k = 1; k <= n; k++) {
				if (a[i]) {
					if (a[i] & 1) {
						if (i - 1 - j == n - (n >> 1)) continue;
						upd(f[i][j][a[i]], f[i-1][j][k] + ((k ^ a[i]) & 1));
					} else {
						if (j == (n >> 1)) continue;
						upd(f[i][j+1][a[i]], f[i-1][j][k] + ((k ^ a[i]) & 1));
					}
				} else {
					for (a[i] = 1; a[i] <= n; a[i]++) {
//							if (i == 3 && j == 0 && a[i] == 4 && k == 5)
//								int kkk = 0;
						if (a[i] & 1) {
							if (i - 1 - j == n - (n >> 1)) continue;
							upd(f[i][j][a[i]], f[i-1][j][k] + ((k ^ a[i]) & 1));
						} else {
							if (j == (n >> 1)) continue;
							upd(f[i][j+1][a[i]], f[i-1][j][k] + ((k ^ a[i]) & 1));
						}
					}
					a[i] = 0;
				}
			}
	}
	
//	dbg(f[1][0][1]);
//	dbg(f[2][0][5]);
//	dbg(f[3][1][4]);
	
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) ans = min(ans, f[n][n>>1][i]);
	print(ans);
	return 0;
}