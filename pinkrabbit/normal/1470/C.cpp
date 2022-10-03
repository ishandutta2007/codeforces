#include <cstdio>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

const int MN = 100005;

int Cnt2;
int N, K, A[MN], B[MN], C[MN], D[MN], ans;
inline int Ask(int x) {
	printf("? %d\n", x + 1);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) A[i] = K, D[i] = 1;
	int pos = range(0, N - 1);
	while (1) {
		int val = Ask(pos);
		for (int i = 0; i < N; ++i) C[i] = 0;
		for (int i = 0; i < N; ++i) if (A[i] == val) C[(pos - i + N) % N] = 1;
		int num = 0;
		for (int i = 0; i < N; ++i) num += D[i] &= C[i];
		if (num == 1) {
			for (int i = 0; i < N; ++i) if (D[i]) ans = i;
			break;
		}
		if (num >= 316) (pos += 316) %= N;
		else if (Cnt2 <= 330) ++pos %= N, ++Cnt2;
		else (pos += N - 1) %= N, ++Cnt2;
		for (int i = 0; i < N; ++i) B[i] = 0;
		for (int i = 0; i < N; ++i) {
			int lf = A[i] / 2, rg = A[i] - lf;
			if (!i) rg += lf, lf = 0;
			B[(i - 1 + N) % N] += lf;
			B[(i + 1 + N) % N] += rg;
		}
		for (int i = 0; i < N; ++i) A[i] = B[i];
	}
	printf("! %d\n", ans + 1);
	fflush(stdout);
	return 0;
}