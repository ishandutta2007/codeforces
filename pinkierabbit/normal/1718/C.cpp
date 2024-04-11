#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <iterator>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Solve();
int main() {
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

const int MN = 200005;

int n; LL a[MN];
int p[55], o;
std::vector<LL> v[55];

void Solve() {
	int Q;
	scanf("%d%d", &n, &Q);
	o = 0;
	{
		int x = n;
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) {
				p[++o] = i;
				while (x % i == 0)
					x /= i;
			}
		if (x > 1)
			p[++o] = x;
	}
	F(i, 1, n) scanf("%lld", a + i);
	F(j, 1, o) {
		v[j] = std::vector<LL>(n / p[j], 0ll);
		F(i, 1, n)
			v[j][i % (n / p[j])] += a[i] * (n / p[j]);
	}
	std::multiset<LL> s;
	F(j, 1, o)
		for (LL x : v[j])
			s.insert(x);
	printf("\t\t\t%lld\n", *std::prev(s.end()));
	F(q, 1, Q) {
		int i; LL x;
		scanf("%d%lld", &i, &x);
		LL d = x - a[i];
		F(j, 1, o) {
			LL &w = v[j][i % (n / p[j])];
			s.erase(s.find(w));
			w += d * (n / p[j]);
			s.insert(w);
		}
		a[i] += d;
		printf("\t\t\t%lld\n", *std::prev(s.end()));
	}
}