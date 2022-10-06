#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Init();
void Solve();
int main() {
	Init();
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

LL fib[995]; int tot;
void Init() {
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; ; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > 1000000000000000ll) {
			tot = i - 1;
			break;
		}
	}
}

const int MN = 105;

int n, a[MN];

std::vector<int> Z(LL x) {
	std::vector<int> ret;
	for (int i = tot; i >= 1; --i)
		if (fib[i] <= x)
			ret.push_back(i),
			x -= fib[i];
	return ret;
}

void Solve() {
	scanf("%d", &n);
	static int vis[995];
	F(i, 0, tot) vis[i] = 0;
	LL sum = 0;
	F(i, 1, n) {
		scanf("%d", a + i);
		sum += a[i];
	}
	int mx = 0;
	{
		auto v = Z(sum + 1);
		if ((int)v.size() >= 2)
			return puts("NO"), void();
		mx = v[0] - 2;
	}
	F(i, 1, n) {
		auto v = Z(a[i]);
		for (int x : v)
			++vis[x];
	}
	F(i, 1, n) {
		auto v = Z(a[i]);
		int b = v.back();
		if (b & 1) {
			static int v2[995];
			F(p, 0, tot) v2[p] = vis[p];
			--v2[b];
			for (int j = b - 1; j >= 2; j -= 2)
				++v2[j];
			++v2[0];
			bool flg = true;
			F(p, 0, tot)
				if (v2[p] != (p <= mx ? 1 : 0))
					flg = false;
			if (flg)
				return puts("YES"), void();
		}
	}
	puts("NO");
}

// 1 2 3 5 8 13
// 8 - 1 = 7 = 5 + 2 ... (v)
// 5 - 1 = 4 = 3 + 1 ... (x)
// 3 - 1 = 2 = 2 ....... (v)
// 2 - 1 = 1 = 1 ....... (x)