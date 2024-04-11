#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long LL;
const int MR = 3005, MN = 3005;

int R, C, N, K;
int px[MN], py[MN], pp[MN];
std::vector<int> vec[MR];
int lst[MN], nxt[MN], rghK[MN];
int _lst[MN], _nxt[MN], _rghK[MN];
int Ans; LL tAns;

inline void del(int i) {
	for (int j = 1, k = i; j <= K && k; ++j, k = lst[k]) {
		Ans -= (py[k] - py[lst[k]]) * (py[nxt[rghK[k]]] - py[rghK[k]]);
		rghK[k] = nxt[rghK[k]];
	}
	nxt[lst[i]] = nxt[i];
	lst[nxt[i]] = lst[i];
}

int main() {
	scanf("%d%d%d%d", &R, &C, &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &px[i], &py[i]);
		vec[px[i]].push_back(i);
		pp[i] = i;
	}
	std::sort(pp + 1, pp + N + 1, [](int i, int j) { return py[i] < py[j]; });
	pp[N + 1] = N + 1, py[N + 1] = C + 1;
	for (int i = 1; i <= N; ++i) lst[pp[i]] = pp[i - 1], nxt[pp[i]] = pp[i + 1];
	nxt[0] = pp[1], lst[N + 1] = pp[N], nxt[N + 1] = N + 1;
	rghK[pp[1]] = 0;
	for (int i = 1; i <= K; ++i) rghK[pp[1]] = nxt[rghK[pp[1]]];
	for (int i = 2; i <= N; ++i) rghK[pp[i]] = nxt[rghK[pp[i - 1]]];
	for (int i = 1; i <= N; ++i) Ans += (py[pp[i]] - py[pp[i - 1]]) * (C + 1 - py[rghK[pp[i]]]);
	for (int i = 1; i <= R; ++i) {
		for (auto id: vec[i - 1]) del(id);
		memcpy(_lst, lst, sizeof lst);
		memcpy(_nxt, nxt, sizeof nxt);
		memcpy(_rghK, rghK, sizeof rghK);
		int _Ans = Ans;
		for (int j = R; j >= i; --j) {
			for (auto id : vec[j + 1]) del(id);
			tAns += Ans;
		}
		memcpy(lst, _lst, sizeof lst);
		memcpy(nxt, _nxt, sizeof nxt);
		memcpy(rghK, _rghK, sizeof rghK);
		Ans = _Ans;
	}
	printf("%lld\n", tAns);
	return 0;
}