#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp=pair<int,int>;
#define x first
#define y second

const int maxv = int(5e3) + 10;

int n, a, b;
pp rng[maxv];

namespace Prob1 {
vector<int> ge[maxv];
int sz[maxv];
int os[maxv];
bitset<2000010> orig;

void in() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b;
	static char buf[2000010];
	for (int i=1; i<=n; ++i) {
		cin >> (buf+1);
		for (int j=1; j<=n; ++j) if (buf[j] == '1') ge[i].push_back(j);
	}
	for (int i=1; i<=n; ++i) {
		int s; cin >> s;
		sz[i] = s;
		os[i] = os[i-1]+sz[i-1];
		int osi = os[i];
		cin >> buf;
		for (int j=0; j<s; ++j) {
			orig[osi+j] = (buf[j] == '1');
		}
	}
}

int idx[maxv], low[maxv], nt;
int stk[maxv], top; bitset<maxv> onstk;
int cyc[maxv], cn;

void dfs(int x) {
	idx[x] = low[x] = ++nt;
	stk[top++] = x; onstk.set(x);
	for (int y:ge[x]) {
		if (!idx[y]) dfs(y), low[x] = min(low[x], low[y]);
		else if (onstk[y]) low[x] = min(low[x], idx[y]);
	}
	if (idx[x] != low[x]) return;
	++cn;
	for(;top--;) {
		int a = stk[top]; onstk.reset(a); cyc[a] = cn;
		if (a == x) break;
	}
}

int gcd(int a, int b) { return b?gcd(b, a%b):a; }
int gg[maxv];
vector<bool> gchk[maxv];

void Work() {
	for (int i=1; i<=n; ++i) if (!idx[i]) dfs(i);

	for (int i=1; i<=n; ++i) gg[cyc[i]] = gcd(gg[cyc[i]], sz[i]);
	for (int i=1; i<=cn; ++i) gchk[i].resize(gg[i]);

	for (int i=1; i<=n; ++i) {
		int s = sz[i], myos = os[i];
		int g = gg[cyc[i]];
		auto &writing = gchk[cyc[i]];
		int wi = 0;
		for (int j=0; j<s; ++j) {
			if (orig[myos+j]) writing[wi] = true;
			if (++wi == g) wi = 0;
		}
	}

	for (int i=cn; 1<i; --i) {
		auto &v1 = gchk[i], &v2 = gchk[i-1];
		int s1 = gg[i], s2 = gg[i-1];
		int g = gcd(s1, s2);
		vector<bool> mo(g);
		for (int j=0, j2=0; j<s1; ++j) {
			if (v1[j]) mo[j2] = true;
			if (++j2 == g) j2 = 0;
		}
		for (int j=0, j2=0; j<s2; ++j) {
			if (mo[j2]) v2[j] = true;
			if (++j2 == g) j2 = 0;
		}
	}

	for (int i=1; i<=n; ++i) {
		int s = sz[i], myos = os[i];
		auto &vg = gchk[cyc[i]];
		int g = gg[cyc[i]];
		int coin = 0, real = 0;
		for (int j=0, j2=0; j<s; ++j) {
			if (orig[myos+j]) ++real, ++coin;
			else if (vg[j2]) ++coin;
			if (++j2 == g) j2 = 0;
		}
		rng[i] = {real, coin};
	}
}
}

void Comp() {
	static int pts[2*maxv], ptn;
	for (int i=1; i<=n; ++i) {
		pts[ptn++] = rng[i].x;
		pts[ptn++] = rng[i].y;
	}

	sort(pts, pts+ptn); ptn = unique(pts, pts+ptn)-pts;

	for (int i=1; i<=n; ++i) {
		rng[i].x = int(lower_bound(pts, pts+ptn, rng[i].x)-pts)+1;
		rng[i].y = int(lower_bound(pts, pts+ptn, rng[i].y)-pts)+1;
	}
}

const int mod = int(1e9) + 7;
int comb[maxv][maxv];
struct _ { _() {
	comb[0][0] = 1;
	for (int i=1; i<=5000; ++i) {
		comb[i][0] = comb[i][i] = 1;
		for (int j=1; j<i; ++j) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			if (comb[i][j] >= mod) comb[i][j] -= mod;
		}
	}
} } _;

int main() {
	Prob1::in();
	Prob1::Work();

	Comp();
	sort(rng+1, rng+n+1, [&](const pp& a, const pp& b) {
		return a.y < b.y;
	});

	static int lpc[maxv*2];

	int ans = 0;

	int largers = 0;
	int bl = 2*n;
	for (int i=n; 1<=i; --i) {
		int l, r; tie(l, r) = rng[i];
		while (r < bl) largers += lpc[bl--];
		++lpc[l];

		int X = (n-i) - largers, Y = largers;
		int tmin = max(0, b-1-Y);
		int tmax = min({X, b-1, a-1-Y});

		for (int t=tmin; t<=tmax; ++t) {
			ans += comb[X][t] * 1ll * comb[Y][b-1-t] % mod;
			if (ans >= mod) ans -= mod;
		}
	}

	printf("%d\n", ans);

	return 0;
}