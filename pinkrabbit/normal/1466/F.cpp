#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 500005, MM = 500005;

int N, M;
int cho[MM];

int pa[MN], typ[MN];
int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x; }

int Ans;

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= M; ++i) {
		int t, x, y;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &x);
			x = fp(x);
			if (!typ[x]) {
				++Ans;
				cho[i] = 1;
				typ[x] = 1;
			}
		} else {
			scanf("%d%d", &x, &y);
			x = fp(x), y = fp(y);
			if (x != y && !(typ[x] && typ[y])) {
				++Ans;
				cho[i] = 1;
				pa[x] = y;
				typ[y] |= typ[x];
			}
		}
	}
	int Power = 1;
	for (int i = 1; i <= Ans; ++i) (Power *= 2) %= Mod;
	printf("%d %d\n", Power, Ans);
	for (int i = 1; i <= M; ++i) if (cho[i]) printf("%d ", i);
	puts("");
	return 0;
}