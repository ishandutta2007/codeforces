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

struct modint {
    int x;
    #define P 998244353
    inline modint(int x = 0) : x(x) {}
    inline modint &operator = (int o) { return x = o, *this; }
    inline modint &operator += (modint o) { return x = x + o.x >= P ? x + o.x - P : x + o.x, *this; }
    inline modint &operator -= (modint o) { return x = x - o.x < 0 ? x - o.x + P : x - o.x, *this; }
    inline modint &operator *= (modint o) { return x = 1ll * x * o.x % P, *this; }
    inline modint &operator ^= (ll b) {
        modint a = *this, c;
        if (!~b) b = P - 2;
        c.x = 1 % P;
        while (b) {
            if (b & 1) c *= a;
            a *= a, b >>= 1;
        }
        return x = c.x, *this;
    }
    inline modint &operator /= (modint o) { return *this *= o ^= -1; }
    inline modint &operator += (int o) { return x = x + o >= P ? x + o - P : x + o, *this; }
    inline modint &operator -= (int o) { return x = x - o < 0 ? x - o + P : x - o, *this; }
    inline modint &operator *= (int o) { return x = 1ll * x * o % P, *this; }
    inline modint &operator /= (int o) { modint y = modint(o); return *this *= y ^= -1; }
    template<class I>
    inline friend modint operator + (modint a, I b) { return a += b; }
    template<class I>
    inline friend modint operator - (modint a, I b) { return a -= b; }
    template<class I>
    inline friend modint operator * (modint a, I b) { return a *= b; }
    inline friend modint operator ^ (modint a, ll b) { return a ^= b; }
    template<class I>
    inline friend modint operator / (modint a, I b) { return a /= b; }
    inline friend bool operator == (modint a, int b) { return a.x == b; }
    inline bool operator ! () { return !x; }
    inline modint operator - () { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }

const int N = 2e5 + 7;
int n, k, a[N], c;
modint p[N], ans;

int main() {
	rd(n), rd(k);
	for (int i = 1; i <= n; i++) rd(a[i]);
	c = a[1] != a[n];
	for (int i = 1; i < n; i++) c += a[i] != a[i+1];
	p[0] = 1;
	for (int i = 1; i <= c; i++) p[i] = p[i-1] * i;
	for (int i = 0; i <= c; i++) ans += (p[c] / p[i] / p[c-i]) * (((modint)2 ^ i) - ((i & 1) ? 0 : p[i] / p[i>>1] / p[i>>1])) * ((modint)(k - 2) ^ (c - i)) / 2;
	ans *= (modint)k ^ (n - c);
	print(ans);
	return 0;
}