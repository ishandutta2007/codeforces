#include <cstdio>
#include <cmath>
#include <algorithm>

typedef long long LL;
const int MN = 1005, MK = 7;

int K, N;
int ax[MK], ay[MK];
int mx[MN], my[MN];
long double at2[MK][MN];
int s[MK], vis[MN], p[MK][MN], q[MK][MN], lp[MK][MN];
int stk[MN], top;

inline bool samedir(int i, int a, int b) {
	LL xa = mx[a] - ax[i], ya = my[a] - ay[i];
	LL xb = mx[b] - ax[i], yb = my[b] - ay[i];
	return xa * yb - ya * xb == 0 && xa * xb + ya * yb > 0;
}
inline LL dist(int i, int a) {
	LL xd = mx[a] - ax[i], yd = my[a] - ay[i];
	return xd * xd + yd * yd;
}

int Ans;

int check(int id, int tp) {
	if (!tp) return -1;
	int jd = s[tp - 1];
	int pos = q[jd][id], lpos = lp[jd][pos];
	int ntp = tp - 1;
	for (int i = lpos; i < pos; ++i) {
		if (vis[p[jd][i]]) continue;
		ntp = check(p[jd][i], ntp);
		if (ntp == -1) return -1;
	}
	vis[id] = 1, stk[++top] = id;
	return ntp;
}

int main() {
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; ++i) scanf("%d%d", &ax[i], &ay[i]);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &mx[i], &my[i]);
	for (int i = 0; i < K; ++i) {
		for (int j = 1; j <= N; ++j) {
			at2[i][j] = atan2l(my[j] - ay[i], mx[j] - ax[i]);
			p[i][j] = j;
		}
		auto cmp = [=](int a, int b) {
			if (samedir(i, a, b)) return dist(i, a) < dist(i, b);
			return at2[i][a] < at2[i][b];
		};
		std::sort(p[i] + 1, p[i] + N + 1, cmp);
		for (int j = 1; j <= N; ++j)
			lp[i][j] = j == 1 ? 1 : samedir(i, p[i][j - 1], p[i][j]) ? lp[i][j - 1] : j,
			q[i][p[i][j]] = j;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < K; ++j) s[j] = j;
		while (1) {
			int ans = check(i, K);
			while (top) vis[stk[top--]] = 0;
			if (~ans) { ++Ans; break; }
			if (!std::next_permutation(s, s + K)) break;
		}
	}
	printf("%d\n", Ans);
	return 0;
}