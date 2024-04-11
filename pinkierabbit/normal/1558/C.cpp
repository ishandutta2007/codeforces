#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 2035;

int N, A[MN];

inline void Solve() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i)
		if ((A[i] ^ i) & 1)
			return puts("-1"), void();
	std::vector<int> Ans;
	auto Add = [&](int x) {
		std::reverse(A + 1, A + x + 1);
		Ans.push_back(x);
	};
	for (int i = N; i >= 3; i -= 2) {
		int p1, p2;
		for (int j = 1; j <= N; ++j) {
			if (A[j] == i) p1 = j;
			if (A[j] == i - 1) p2 = j;
		}
		if (p1 < p2) {
			if (p1 != 1) Add(p1);
		} else {
			Add(p1), p2 = p1 - p2 + 1;
		}
		if (p2 != 2) {
			Add(p2 - 1);
			Add(p2 + 1);
			Add(3);
		}
		Add(i);
	}
	printf("%d\n", (int)Ans.size());
	for (int x : Ans) printf("%d ", x);
	puts("");
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) Solve();
	return 0;
}