#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <random>
#include <chrono>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

void Solve();
int main() {
	Solve();
	return 0;
}

typedef unsigned long long ULL;
const int Mod = 998244353;

const int MN = 500005;

int n, q;
ULL a[MN];
std::map<int, ULL> mp;

int bit[40][MN];
void Add(int b, int i, int x) {
	for (; i <= n; i += i & -i)
		bit[b][i] += x;
}
int Qur(int b, int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[b][i];
	return s;
}

void Solve() {
	scanf("%d%d", &n, &q);
	F(i, 1, n) {
		int w;
		scanf("%d", &w);
		if (!mp.contains(w))
			mp[w] = rng() & 0xffffffffff;
		a[i] = mp[w];
		F2(j, 0, 40)
			if (a[i] >> j & 1)
				Add(j, i, (int)(a[i] >> j & 1));
	}
	F(q_, 1, q) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int i, w;
			scanf("%d%d", &i, &w);
			if (!mp.contains(w))
				mp[w] = rng() & 0xffffffffff;
			ULL x = mp[w];
			F2(j, 0, 40)
				if ((a[i] ^ x) >> j & 1)
					Add(j, i, (int)(x >> j & 1) - (int)(a[i] >> j & 1));
			a[i] = x;
		} else if (op == 2) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			if ((r - l + 1) % k) {
				puts("NO");
				continue;
			}
			if (k == 1) {
				puts("YES");
				continue;
			}
			bool ok = true;
			F2(j, 0, 40) {
				int s = Qur(j, r) - Qur(j, l - 1);
//				printf("s = %d\n", s);
				if (s % k) {
					ok = false;
					break;
				}
			}
			puts(ok ? "YES" : "NO");
		}
	}
}