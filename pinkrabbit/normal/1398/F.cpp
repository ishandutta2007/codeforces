#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 1000005;

int N;
char s[MN];
int len[MN];
std::vector<int> V[MN];
int pa[MN];
inline int fp(int x) {
	while (pa[x] && pa[pa[x]]) x = pa[x] = pa[pa[x]];
	return pa[x] ? pa[x] : x;
}
int Ans[MN];

int main() {
	scanf("%d%s", &N, s + 1);
	int lst0 = 0, lst1 = 0;
	for (int i = 1; i <= N; ++i) {
		if (s[i] == '?') len[i] = i - std::min(lst0, lst1);
		if (s[i] == '0') len[i] = i - lst1, lst0 = i;
		if (s[i] == '1') len[i] = i - lst0, lst1 = i;
		V[len[i]].push_back(i);
	}
	for (int i = 1; i <= N; ++i) {
		int lstp = 0, ans = 0;
		while (1) {
			if (lstp + i > N) break;
			int k = fp(lstp + i);
			if (k == N + 1) break;
			++ans, lstp = k;
		}
		printf("%d%c", ans, " \n"[i == N]);
		for (int x : V[i]) pa[x] = x + 1;
	}
	return 0;
}