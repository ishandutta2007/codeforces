#include <cstdio>
#include <vector>

const int MN = 2005;

int N;

int A[MN];
void Ask(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
}

int dep[MN];
std::vector<std::pair<int, int>> Ans;

int main() {
	scanf("%d", &N);
	Ask(1);
	int num[2] = {0, 0};
	for (int i = 2; i <= N; ++i) {
		dep[i] = A[i];
		++num[dep[i] & 1];
		if (dep[i] == 1)
			Ans.push_back({1, i});
	}
	int op = num[0] < num[1] ? 0 : 1;
	for (int i = 2; i <= N; ++i) if ((dep[i] & 1) == op) {
		Ask(i);
		for (int j = 2; j <= N; ++j) if (A[j] == 1)
			Ans.push_back({i, j});
	}
	puts("!");
	for (auto [x, y] : Ans)
		printf("%d %d\n", x, y);
	return 0;
}