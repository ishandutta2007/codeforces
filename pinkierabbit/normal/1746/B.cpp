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

const int MN = 500005;

int n;
int a[MN];

void Init() {
}

void Solve() {
	scanf("%d", &n);
	std::vector<int> V[2];
	F(i, 1, n) {
		scanf("%d", a + i);
		if (a[i])
			V[1].push_back(i);
		else
			V[0].push_back(i);
	}
	std::reverse(V[0].begin(), V[0].end());
	int k = 0;
	while (k < (int)std::min(V[0].size(), V[1].size()) && V[1][k] < V[0][k])
		++k;
	printf("%d\n", k);
}