#include <cstdio>
#include <cstring>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 1005, SIG = 14, ML = 1005;
const int MS = 400005;

inline void chkmx(LL &x, LL y) { x = x < y ? y : x; }

int N, Id[MN], Len;
char str[MS];

int nxt[ML][SIG], fail[ML], Num[ML], cnt;

inline int Ins(char *S, int val) {
	int now = 0;
	for (; *S; ++S) {
		int j = *S - 'a';
		if (!nxt[now][j]) nxt[now][j] = ++cnt;
		now = nxt[now][j];
	} Num[now] += val;
	return now;
}

int que[ML], l, r;

inline void BuildAC() {
	fail[0] = -1;
	que[l = r = 1] = 0;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < SIG; ++j) {
			if (nxt[u][j]) {
				fail[nxt[u][j]] = u ? nxt[fail[u]][j] : 0;
				que[++r] = nxt[u][j];
			}
			else nxt[u][j] = u ? nxt[fail[u]][j] : 0;
		}
	}
	for (int i = 2; i <= r; ++i) Num[que[i]] += Num[fail[que[i]]];
}

int trans[ML]; LL nums[ML];
LL dp[1 << SIG][ML], Ans;

int main() {
	scanf("%d", &N), Ans = -Infll;
	for (int i = 1; i <= N; ++i) {
		int val;
		scanf("%s%d", str, &val);
		Id[i] = Ins(str, val);
	}
	BuildAC();
	scanf("%s", str);
	Len = strlen(str);
	for (int S = 0; S < 1 << SIG; ++S)
		for (int u = 0; u <= cnt; ++u)
			dp[S][u] = -Infll;
	dp[0][0] = 0;
	int lastpos = -1, Cnt = 0;
	for (int i = 0; i < Len; ++i) if (str[i] == '?') {
		++Cnt;
		for (int k = 0; k <= cnt; ++k) trans[k] = k, nums[k] = 0;
		for (int j = lastpos + 1; j < i; ++j)
			for (int k = 0; k <= cnt; ++k)
				trans[k] = nxt[trans[k]][str[j] - 'a'],
				nums[k] += Num[trans[k]];
		for (int S = 0; S < 1 << SIG; ++S) if (__builtin_popcount(S) == Cnt - 1)
			for (int u = 0; u <= cnt; ++u)
				for (int j = 0; j < SIG; ++j) if (~S >> j & 1) {
					int v = nxt[trans[u]][j];
					chkmx(dp[S ^ 1 << j][v], dp[S][u] + nums[u] + Num[v]);
				}
		lastpos = i;
	} {
		for (int k = 0; k <= cnt; ++k) trans[k] = k, nums[k] = 0;
		for (int j = lastpos + 1; j < Len; ++j)
			for (int k = 0; k <= cnt; ++k)
				trans[k] = nxt[trans[k]][str[j] - 'a'],
				nums[k] += Num[trans[k]];
		for (int S = 0; S < 1 << SIG; ++S) if (__builtin_popcount(S) == Cnt)
			for (int u = 0; u <= cnt; ++u)
				chkmx(Ans, dp[S][u] + nums[u]);
		lastpos = Len;
	}
	printf("%lld\n", Ans);
	return 0;
}