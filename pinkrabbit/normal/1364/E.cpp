#include <cstdio>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

inline int ask(int x, int y) {
	printf("? %d %d\n", x, y), fflush(stdout);
	int z; scanf("%d", &z);
	return z;
}

const int MN = 1 << 11 | 7;

int N, per[MN], A[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) per[i] = i;
	std::shuffle(per + 1, per + N + 1, rng);
	int lst = -1, lstp = per[1], left = 2222, pos = 1;
	while (left) {
		++pos;
		if (pos > N) {
			std::shuffle(per + 1, per + N + 1, rng);
			pos = 1;
		}
		if (per[pos] == lstp) continue;
		--left;
		int v = ask(lstp, per[pos]);
		lst &= v;
		if (lst == v) lstp = per[pos];
	}
	A[lstp] = 0;
	for (int i = 1; i <= N; ++i) if (i != lstp) A[i] = ask(i, lstp);
	printf("! ");
	for (int i = 1; i <= N; ++i) printf("%d%c", A[i], " \n"[i == N]);
	return 0;
}