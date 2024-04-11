#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
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

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, k;
int a[MN];
int bit1[MN], bit2[MN];
inline void Add(int i) {
	int x = i;
	for (; i <= n; i += i & -i)
		++bit1[i],
		bit2[i] += x;
}
inline int Ask(int s) {
	int i = 0, ret = 0;
	for (int j = 16; j >= 0; --j) if ((i | 1 << j) <= n) {
		if (bit2[i | 1 << j] <= s)
			i |= 1 << j,
			s -= bit2[i],
			ret += bit1[i];
	}
	return ret + (s / (i + 1));
}

void Solve() {
	scanf("%d%d", &n, &k), k = min(k, n);
	map<int, int> b;
	F(i, 1, n) scanf("%d", a + i), ++b[a[i]];
	sort(a + 1, a + n + 1);
	F(i, 1, n) bit1[i] = bit2[i] = 0;
	if (k == 0) {
		int dif = (int)b.size();
		int mex = 0;
		while (b.find(mex) != b.end())
			++mex;
		printf("%d\n", dif - mex);
		return ;
	}
	static int seq[MN];
	int cnt = 0;
	for (auto [x, y] : b)
		seq[++cnt] = x;
//	for (int i = 1; i <= cnt; ++i) printf("%d%c", seq[i], " \n"[i == cnt]);
	int ans = n;
	int num = 0, sum = 0;
	for (int i = cnt; i >= 1; --i) {
		if (i == cnt || seq[i + 1] != seq[i] + 1) {
			int x = seq[i] + 1;
			if (x <= n) {
//				printf("mex = %d:\n", x);
				int emp = x - i;
				if (emp <= k) {
//					printf("\temp = %d\n\tsum = %d\n", emp, sum);
					if (sum >= emp) {
						if (k >= sum)
							ans = 0;
						else {
							int del = Ask(k);
							ans = min(ans, num - del);
						}
					} else
						ans = 0;
				}
			}
		}
		if (seq[i] >= 2) {
			++num;
			sum += b[seq[i]];
			Add(b[seq[i]]);
		}
	}
	if (seq[1] >= 2) {
		int del = Ask(k);
		ans = min(ans, num - del);
	}
	printf("%d\n", ans);
}