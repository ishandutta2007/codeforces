#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MK = 100005, MN = 100005;

int K, N, M;
LL A[MK], B[MK];
int typ[MN], pos[MN];
LL val[MN], denom[MN];
std::vector<int> Vadd[MN];
int padd[MN], cadd;
int pmul[MN], cmul;
int Ans[MN], Cnt;

int main() {
	scanf("%d%d%d", &K, &N, &M);
	for (int i = 1; i <= K; ++i) scanf("%lld", &A[i]), B[i] = A[i];
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d%lld", &typ[i], &pos[i], &val[i]);
		if (typ[i] == 1) B[pos[i]] = std::max(B[pos[i]], val[i]);
	}
	for (int i = 1; i <= N; ++i) {
		if (typ[i] != 3) {
			if (typ[i] == 1) {
				if (val[i] != B[pos[i]]) continue;
				val[i] -= A[pos[i]];
			}
			padd[++cadd] = i;
			Vadd[pos[i]].push_back(i);
		} else if (val[i] > 1) pmul[++cmul] = i;
	}
	typ[N + 1] = 2, pos[N + 1] = 0, val[N + 1] = 0, denom[N + 1] = 1;
	typ[N + 2] = 3, pos[N + 2] = 0, val[N + 2] = 1;
	while (cadd < M) padd[++cadd] = N + 1;
	while (cmul < M) pmul[++cmul] = N + 2;
	auto cmp = [](int i, int j) { return val[i] > val[j]; };
	std::sort(pmul + 1, pmul + cmul + 1, cmp);
	for (int i = 1; i <= K; ++i) {
		std::sort(Vadd[i].begin(), Vadd[i].end(), cmp);
		LL v = A[i];
		for (auto x : Vadd[i]) denom[x] = v, v += val[x];
	}
	std::sort(padd + 1, padd + cadd + 1, [](int i, int j) { return val[i] * denom[j] > val[j] * denom[i]; });
	int j2 = M, j1 = 1;
	while (j2 && val[pmul[j2]] * denom[padd[j1]] < denom[padd[j1]] + val[padd[j1]]) ++j1, --j2;
	--j1;
	for (int i = 1; i <= j1; ++i) if (padd[i] <= N) Ans[++Cnt] = padd[i];
	for (int i = 1; i <= j2; ++i) if (pmul[i] <= N) Ans[++Cnt] = pmul[i];
	std::sort(Ans + 1, Ans + Cnt + 1, [](int i, int j) { return typ[i] < typ[j]; });
	printf("%d\n", Cnt);
	for (int i = 1; i <= Cnt; ++i) printf("%d%c", Ans[i], " \n"[i == Cnt]);
	return 0;
}