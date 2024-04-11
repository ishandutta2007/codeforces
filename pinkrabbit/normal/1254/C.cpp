#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 1005;

int N;

inline LL ask(int t, int i, int j, int k) {
	printf("%d %d %d %d\n", t, i, j, k);
	fflush(stdout);
	LL x;
	scanf("%lld", &x);
	return x;
}

LL are[MN];
int sid[MN];
int a1[MN], a2[MN], c1, c2;

int main() {
	scanf("%d", &N);
	int p = 2;
	for (int i = 3; i <= N; ++i)
		if (ask(2, 1, i, p) == 1)
			p = i;
	for (int i = 2; i <= N; ++i) if (i != p)
		are[i] = ask(1, 1, p, i);
	int mx = std::max_element(are + 2, are + N + 1) - are;
	for (int i = 2; i <= N; ++i) if (i != p && i != mx)
		sid[i] = ask(2, 1, mx, i);
	for (int i = 2; i <= N; ++i) if (i != p && i != mx) {
		if (sid[i] == -1) a1[++c1] = i;
		else a2[++c2] = i;
	}
	std::sort(a1 + 1, a1 + c1 + 1, [](int i, int j) { return are[i] < are[j]; });
	std::sort(a2 + 1, a2 + c2 + 1, [](int i, int j) { return are[i] > are[j]; });
	printf("0 1 %d", p);
	for (int i = 1; i <= c1; ++i) printf(" %d", a1[i]);
	printf(" %d", mx);
	for (int i = 1; i <= c2; ++i) printf(" %d", a2[i]);
	puts(""), fflush(stdout);
	return 0;
}