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
	template <class I>
	inline void rda(I *a, int &n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
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
using io::rda;
using io::rds;
using io::print;
using io::prints;

const int N = 1e3 + 7;
int n, d[N], v[N];
vi e[N]; 

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1, x, y; i < n; i++)
		cin >> x >> y, e[x].pb(y), e[y].pb(x), d[x]++, d[y]++;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (d[i] == 1) q.push(i);
	for (int i = 1; i <= n / 2; i++) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		cout << "? " << x << " " << y << endl;
		fflush(stdout);
		int z;
		cin >> z;
		if (z == x || z == y) {
			cout << "! " << z << endl;
			return 0;
		}
		for (int z : e[x])
			if (!v[z] && (--d[z] == 1)) q.push(z);
		for (int z : e[y])
			if (!v[z] && (--d[z] == 1)) q.push(z);
		v[x] = v[y] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!v[i]) cout << "! " << i << endl;
	return 0;
}