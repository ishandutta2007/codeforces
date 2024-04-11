#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 5005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n, k;
int a[MN], s[MN];
int binom[MN][MN];

void Solve();

int main() {
	binom[0][0] = 1;
	F(i, 1, 5000) {
		binom[i][0] = 1;
		F(j, 1, 5000) {
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % mod;
		}
	}
	int tests = 1;
	while (tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	scanf("%d%d", &n, &k);
	F(i, 1, n) scanf("%1d", a + i), s[i] = s[i - 1] + a[i];
	if (s[n] < k)
		return puts("1"), void();
	static int b[MN];
	int c = 0;
	F(i, 1, n)
		if (a[i])
			b[++c] = i;
	b[0] = 0;
	b[c + 1] = n + 1;
	int ans = 1;
	F(i, 0, c - 1) {
		F(j, i + 2, c + 1) if (j - i - 1 <= k) {
			int len = b[j] - b[i] - 1;
			int cnt = j - i - 1;
			int num = binom[len][cnt];
			if (cnt >= 2) {
				num = (num - binom[b[j] - b[i + 1] - 1][cnt - 1] + mod) % mod;
				num = (num - binom[b[j - 1] - b[i] - 1][cnt - 1] + mod) % mod;
				num = (num + binom[b[j - 1] - b[i + 1] - 1][cnt - 2]) % mod;
			} else
				num = (num - 1 + mod) % mod;
			ans = (ans + num) % mod;
		}
	}
	printf("%d\n", ans);
}