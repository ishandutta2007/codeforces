#include <bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;

int N, M, K;
int pt[200005];

long long f(int x, int y) {
	int lp = y - x;
	lp %= 2 * N;
	lp += 2 * N;
	lp %= 2 * N;
	if (pt[lp] == -1) return INF;
	long long t = 2ll * (long long)M * (long long)pt[lp] + (long long)x;
	return t;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	swap(N, M);
	memset(pt, -1, sizeof(pt));
	int cur = 0, t = 0;
	while (true) {
		if (pt[cur] != -1) break;
		pt[cur] = t;
		t++;
		cur += 2 * M;
		cur %= 2 * N;
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long mn = min(min(f(x, y), f(2 * M - x, y)), min(f(x, 2 * N - y), f(2 * M - x, 2 * N - y)));
		if (mn == INF) printf("-1\n");
		else printf("%lld\n", mn);
	}
}