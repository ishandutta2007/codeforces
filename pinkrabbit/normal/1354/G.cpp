#include <cstdio>
#include <algorithm>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

int N;
char str[9];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%*d", &N);
		int ok1 = 0;
		for (int i = 1; i <= 30; ++i) {
			printf("? 1 1\n1\n%d\n", range(2, N));
			fflush(stdout);
			scanf("%s", str);
			if (*str == 'S') ok1 = 1;
		}
		if (ok1) {
			puts("! 1");
			fflush(stdout);
			continue;
		}
		int j = 0;
		while (2 << j <= N) {
			printf("? %d %d\n", 1 << j, 1 << j);
			for (int i = 1; i <= 1 << j; ++i) printf("%d%c", i, " \n"[i == 1 << j]);
			for (int i = 1; i <= 1 << j; ++i) printf("%d%c", (1 << j) + i, " \n"[i == 1 << j]);
			fflush(stdout);
			scanf("%s", str);
			if (*str == 'F') break;
			++j;
		}
		int lb = (1 << j) + 1, rb = std::min(2 << j, N), mid, ans = 0;
		while (lb <= rb) {
			mid = (lb + rb) >> 1;
			int num = mid - (1 << j);
			printf("? %d %d\n", num, num);
			for (int i = 1; i <= num; ++i) printf("%d%c", i, " \n"[i == num]);
			for (int i = 1; i <= num; ++i) printf("%d%c", (1 << j) + i, " \n"[i == num]);
			fflush(stdout);
			scanf("%s", str);
			if (*str == 'F') ans = mid, rb = mid - 1;
			else lb = mid + 1;
		}
		printf("! %d\n", ans);
		fflush(stdout);
	}
	return 0;
}