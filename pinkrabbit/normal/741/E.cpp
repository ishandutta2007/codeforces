#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Mod = 1001943197;
const int Base = 34300;
const int MN = 100005, MQ = 100005, S = 500, MS = S + 5;

char s[MN], t[MN];
int N, lt, Lim, per[MN];
int pBase[MN];
int Hs[MN], Ht[MN];

inline int Hmerge(int h1, int h2, int l2) {
	return (int)(((LL)h1 * pBase[l2] + h2) % Mod);
}
inline int gHash(int *H, int lb, int rb) {
	return (int)(((LL)H[lb - 1] * (Mod - pBase[rb - lb + 1]) + H[rb]) % Mod);
}
inline bool smallerThan(int pos1, int pos2) {
	if (pos1 == pos2) return false;
	bool rev = false;
	if (pos1 > pos2)
		std::swap(pos1, pos2),
		rev = true;
	int lb = 0, rb = lt + (pos2 - pos1), ans = -1;
	while (lb <= rb) {
		int mid = (lb + rb) / 2;
		int hs1 = mid <= lt ? gHash(Ht, 1, mid) : Hmerge(Ht[lt], gHash(Hs, pos1 + 1, pos1 + (mid - lt)), mid - lt);
		int hs2 = mid <= pos2 - pos1 ? gHash(Hs, pos1 + 1, pos1 + mid) : Hmerge(gHash(Hs, pos1 + 1, pos2), gHash(Ht, 1, mid - (pos2 - pos1)), mid - (pos2 - pos1));
		if (hs1 == hs2) ans = mid, lb = mid + 1;
		else rb = mid - 1;
	}
	if (ans == lt + (pos2 - pos1)) return rev ? pos2 < pos1 : pos1 < pos2;
	char ch1 = ans < lt ? t[ans + 1] : s[pos1 + ans - lt + 1];
	char ch2 = ans < pos2 - pos1 ? s[pos1 + ans + 1] : t[ans - (pos2 - pos1) + 1];
	if (rev) std::swap(ch1, ch2);
	return ch1 < ch2;
}

int iper[MN], id[MN];
int ST[17][MN];
inline int gMin(int x, int y) {
	return iper[x] < iper[y] ? x : y;
}
inline int RMQ(int l, int r) {
	int j = 31 - __builtin_clz(r - l + 1);
	return gMin(ST[j][l + (1 << j) - 1], ST[j][r]);
}

int Q, ql[MQ], qr[MQ], qk[MQ], qx[MQ], qy[MQ], Ans[MQ];
std::vector<int> V[MS];

int main() {
	scanf("%s%s%d", s + 1, t + 1, &Q);
	N = (int)(strlen(s + 1)), lt = (int)(strlen(t + 1));
	for (int i = 1; i <= N; ++i) Hs[i] = (int)(((LL)Hs[i - 1] * Base + (s[i] - 'a' + 1)) % Mod);
	for (int i = 1; i <= lt; ++i) Ht[i] = (int)(((LL)Ht[i - 1] * Base + (t[i] - 'a' + 1)) % Mod);
	Lim = std::max(N, lt), pBase[0] = 1;
	for (int i = 1; i <= Lim; ++i) pBase[i] = (int)((LL)pBase[i - 1] * Base % Mod);
	for (int i = 1; i <= N + 1; ++i) per[i] = i - 1;
	std::sort(per + 1, per + N + 2, smallerThan);
	for (int i = 1; i <= N + 1; ++i) iper[per[i]] = i;
	for (int i = 0; i <= N; ++i) ST[0][i] = i;
	for (int j = 0; 2 << j <= N + 1; ++j)
		for (int i = (2 << j) - 1; i <= N; ++i)
			ST[j + 1][i] = gMin(ST[j][i - (1 << j)], ST[j][i]);
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d%d%d%d", &ql[i], &qr[i], &qk[i], &qx[i], &qy[i]);
		if (qk[i] > S) {
			int lim = N / qk[i], ans = -1;
			for (int j = 0; j <= lim; ++j) {
				int l = j * qk[i] + qx[i];
				int r = j * qk[i] + qy[i];
				l = std::max(l, ql[i]);
				r = std::min(r, qr[i]);
				if (l <= r) {
					int res = RMQ(l, r);
					if (ans == -1) ans = res;
					else ans = gMin(ans, res);
				}
			}
			Ans[i] = ans;
		} else V[qk[i]].push_back(i);
	}
	for (int k = 1; k <= S; ++k) {
		int tot = 0, mxlen = N / k + 1;
		for (int j = 0; j < k; ++j)
			for (int i = j; i <= N; i += k)
				ST[0][++tot] = i, id[i] = tot;
		for (int j = 0; 2 << j <= mxlen; ++j)
			for (int i = 2 << j; i <= tot; ++i)
				ST[j + 1][i] = gMin(ST[j][i - (1 << j)], ST[j][i]);
		for (int i : V[k]) {
			int ans = -1;
			for (int j = qx[i]; j <= qy[i]; ++j) {
				int l = id[j] + (ql[i] - j + k - 1) / k;
				int r = id[j] + (qr[i] - j + k) / k - 1;
				if (l <= r) {
					int res = RMQ(l, r);
					if (ans == -1) ans = res;
					else ans = gMin(ans, res);
				}
			}
			Ans[i] = ans;
		}
	}
	for (int i = 1; i <= Q; ++i)
		printf("%d%c", Ans[i], " \n"[i == Q]);
	return 0;
}