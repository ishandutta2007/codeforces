#include <cstdio>
#include <vector>
#include <queue>

const int MN = 500005;

int N, A[MN], Id[MN], Z;
int lb[MN], rb[MN];
std::vector<int> vec[MN];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d", &N), Z = 0;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
			if (!A[i]) Id[++Z] = i;
		}
		if (Z <= 1) {
			puts("0");
			continue;
		}
		int pos = Id[Z / 2];
		for (int i = 1; i <= N; ++i) rb[i] = 0, lb[i] = N + 1, vec[i].clear();
		for (int i = 1; i <= pos; ++i) if (A[i]) rb[A[i]] = i;
		for (int i = N; i > pos; --i) if (A[i]) lb[A[i]] = i;
		for (int i = 1; i <= N; ++i) {
			rb[i] += N - pos;
			lb[i] -= pos;
			vec[lb[i]].push_back(rb[i]);
		}
		int Ans = 0;
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
		for (int i = 1; i <= N; ++i) {
			for (int r : vec[i]) pq.push(r);
			while (!pq.empty() && pq.top() < i) pq.pop();
			if (!A[(i + pos - 1) % N + 1] && !pq.empty()) ++Ans, pq.pop();
		}
		printf("%d\n", std::min(Ans, Z / 2));
	}
	return 0;
}