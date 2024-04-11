#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bit>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Add(int &x, int y) {
	x -= mod - y;
	if (x < 0)
		x += mod;
}

void Solve();

int main() {
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

char str[MN];
int a[MN];
int val[8];

void Solve() {
	scanf("%s", str);
	int n = (int)strlen(str);
	F2(i, 0, n)
		a[i] = str[n - 1 - i] - '0';
	a[n] = 0;
	++a[0];
	for (int p = 0; a[p] == 2; ++p)
		a[p] = 0,
		++a[p + 1];
	if (a[n] == 1)
		++n;
//	dF(i, n - 1, 0) printf("%d", a[i]);
//	puts("");
	F2(c, 0, 8) {
		val[c] = c;
		int pc = std::popcount((unsigned)c);
		if (pc >= 2)
			val[c] ^= 7;
	}
	// =======================
	int f_[2][8][8];
	auto f = f_[0], g = f_[1];
	memset(f_, 0, sizeof(f_));
	f[0][0] = 1;
	dF(i, n - 1, 0) {
		// f -> g
		F2(a, 0, 8) F2(b, 0, 8) g[a][b] = 0;
		if (!a[i]) {
			F2(a, 0, 8) F2(b, 0, 8) if (f[a][b]) {
				int v = f[a][b];
				F2(c, 0, 8) if (!((a ^ 7) & c))
					Add(g[a][b | val[c]], v);
			}
		} else {
			F2(a, 0, 8) F2(b, 0, 8) if (f[a][b]) {
				int v = f[a][b];
				F2(c, 0, 8)
					Add(g[a | (c ^ 7)][b | val[c]], v);
			}
		}
		swap(f, g);
	}
	printf("%d\n", f[7][7]);
}