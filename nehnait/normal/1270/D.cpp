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

const int N = 507;
int n, k, a[N];

inline pi ask(vi o) {
	vi O = o;
	sort(o.begin(), o.end());
	cout << '?';
	for (auto c : o) cout << ' ' << c;
	cout << endl;
	fflush(stdout);
	int a, b;
	cin >> a >> b;
	o = O;
	return mp(a, b);
}

int main() {
	cin >> n >> k;
	if (k == 1) return cout << "! 1" << endl, 0;
	vi o, q;
	for (int i = 1; i <= k; i++) o.pb(i);
	for (int i = k; i <= n; i++) {
		pi p = ask(o);
		a[p.fi] = p.se;
		q.pb(p.fi);
		if (i != n)
			for (ui j = 0; j < o.size(); j++)
				if (o[j] == p.fi) o[j] = i + 1;
	} // n - k + 1 
	if (n - k + 1 >= k) {
		o.clear();
		for (int i = 0; i < k; i++) o.pb(q[i]);
		pi p = ask(o);
		int ans = 0;
		for (int i = 0; i < k; i++)
			if (a[o[i]] <= p.se) ++ans;
		cout << "! " << ans << endl;
		return 0;
	}
	int x = q.back();
	q.pop_back();
	int y = q.back();
	for (ui i = 1; i < o.size(); i++)
		if (o[i] == x) swap(o[0], o[i]);
	int ans = 0;
	for (ui i = 1; i < o.size(); i++) {
		int z = o[i];
		o[i] = y;
		pi p = ask(o);
		if (p.fi == x) ans += a[y] < a[x];
		else ans += a[x] < a[y];
		o[i] = z;
	}
	cout << "! "  << ans + 1 << endl;
	return 0;
}