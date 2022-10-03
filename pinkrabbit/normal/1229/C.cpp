#include <cstdio>
#include <vector>

typedef long long LL;
const int MN = 100005;

int N, M, Q, ind[MN], oud[MN];
std::vector<int> V[MN];
LL Ans;

int main() {
	int x, y;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		if (x > y) std::swap(x, y);
		V[x].push_back(y);
		++ind[x], ++oud[y];
	}
	for (int i = 1; i <= N; ++i) Ans += (LL)ind[i] * oud[i];
	printf("%lld\n", Ans);
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &x);
		Ans -= (LL)ind[x] * oud[x];
		for (auto i : V[x]) {
			Ans -= (LL)ind[i] * oud[i];
			++ind[i], --oud[i];
			Ans += (LL)ind[i] * oud[i];
			--ind[x], ++oud[x];
			V[i].push_back(x);
		}
		V[x].clear();
		printf("%lld\n", Ans);
	}
	return 0;
}