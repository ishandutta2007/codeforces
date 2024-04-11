#include <bits/stdc++.h>
using namespace std;

int N, K, S, T, C[200005], V[200005], G[200005];

bool attempt(int a) {
	long long ans = 0;
	for (int i = 0; i <= K; i++) {
		int dis = G[i] - ((i == 0) ? 0 : G[i - 1]);
		if (dis * 2 <= a) ans += dis;
		else if (dis > a) return 0;
		else {
			int fast_dis = a - dis;
			ans += fast_dis + (dis - fast_dis) * 2;
		}
	}
	return (ans <= T);
}

int main() {
	scanf("%d%d%d%d", &N, &K, &S, &T);
	for (int i = 0; i < N; i++) scanf("%d%d", &C[i], &V[i]);
	for (int i = 0; i < K; i++) scanf("%d", &G[i]);
	sort(G, G + K);
	G[K] = S;
	long long bot = 0, top = 2000000001, mid;
	while (bot + 1 < top) {
		mid = (bot + top) / 2;
		if (attempt(mid)) top = mid;
		else bot = mid;
	}
	int mini = bot + 1;
	int val = 2000000000;
	for (int i = 0; i < N; i++) {
		if (V[i] >= mini) val = min(val, C[i]);
	}
	if (val == 2000000000) printf("-1\n");
	else printf("%d\n", val);
}