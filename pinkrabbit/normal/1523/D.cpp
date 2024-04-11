#include <cstdio>
#include <random>
#include <chrono>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

typedef long long LL;
const int MN = 200005;

int N, M;
LL A[MN];
LL Ans;
int AnsC;

int f[1 << 15];

int main() {
	scanf("%d%d%*d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 0, x; j < M; ++j)
			scanf("%1d", &x), A[i] |= (LL)x << j;
	for (int t = 1; t <= 80; ++t) {
		int p = range(1, N);
		std::vector<int> v;
		for (int j = 0; j < M; ++j) if (A[p] >> j & 1)
			v.push_back(j);
		int sz = (int)v.size();
		for (int k = 0; k < 1 << sz; ++k)
			f[k] = 0;
		for (int i = 1; i <= N; ++i) {
			int x = 0;
			for (int j = 0; j < sz; ++j)
				x |= (int)(A[i] >> v[j] & 1) << j;
			++f[x];
		}
		for (int j = 0; j < sz; ++j)
			for (int k = 0; k < 1 << sz; ++k) if (~k >> j & 1)
				f[k] += f[k ^ 1 << j];
		for (int k = 0; k < 1 << sz; ++k) if (f[k] * 2 >= N) {
			int c = __builtin_popcount(k);
			if (c > AnsC) {
				Ans = 0;
				for (int j = 0; j < sz; ++j)
					Ans |= (LL)(k >> j & 1) << v[j];
				AnsC = c;
			}
		}
	}
	for (int j = 0; j < M; ++j)
		printf("%d", (int)(Ans >> j & 1));
	puts("");
	return 0;
}