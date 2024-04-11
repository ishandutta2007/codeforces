#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
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

int f[105][105][2][2]; // false: Alice wins
bool dfs(int a0, int a1, int w, int p) {
	if (f[a0][a1][w][p] != -1)
		return f[a0][a1][w][p];
	if (a0 == 0 && a1 == 0)
		return p ? true : false;
	bool ret = w ? false : true;
	if (a0) {
		bool r = dfs(a0 - 1, a1, w ^ 1, p);
		if (w)
			ret = r ? true : ret;
		else
			ret = r ? ret : false;
	}
	if (a1) {
		bool r = dfs(a0, a1 - 1, w ^ 1, w ? p : (p ^ 1));
		if (w)
			ret = r ? true : ret;
		else
			ret = r ? ret : false;
	}
	return (f[a0][a1][w][p] = ret);
}

void Init() {
	std::memset(f, 0xff, sizeof f);
}

void Solve() {
	int n;
	scanf("%d", &n);
	int a0 = 0, a1 = 0;
	F(i, 1, n) {
		int x;
		scanf("%d", &x);
		if (x & 1)
			++a1;
		else
			++a0;
	}
	puts(dfs(a0, a1, 0, 0) ? "Bob" : "Alice");
}