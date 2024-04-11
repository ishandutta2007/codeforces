#include <cstdio>
#include <cmath>
#include <algorithm>

typedef long long LL;
typedef std::pair<LL, int> pli;
const LL Inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005, MT = 320;

int N, S, T, A[MN]; LL B[MN];
int lb[MT], rb[MT], p[MN], bel[MN];
int dk[MT]; LL dB[MT];
int que[MN], ql[MT], qr[MT];
int cho[MN];
LL Ans;

inline double slope(int i, int j) {
	if (A[i] == A[j]) {
		if (B[i] == B[j]) return 1;
		return B[i] < B[j] ? 1e99 : -1e99;
	}
	return (B[j] - B[i]) / (double)(A[j] - A[i]);
}
void Rebuild(int bi) {
	for (int i = lb[bi]; i <= rb[bi]; ++i)
		B[p[i]] += dB[bi] + (LL)dk[bi] * A[p[i]];
	dB[bi] = dk[bi] = 0;
	int &l = ql[bi], &r = qr[bi];
	l = lb[bi], r = lb[bi] - 1;
	for (int i = lb[bi]; i <= rb[bi]; ++i) if (!cho[p[i]]) {
		int x = p[i];
		while (l < r && slope(que[r - 1], que[r]) < slope(que[r], x)) --r;
		que[++r] = x;
	}
}
inline pli Ask(int bi) {
	int &l = ql[bi], r = qr[bi];
	while (l < r && slope(que[l], que[l + 1]) >= -dk[bi]) ++l;
	if (l > r) return pli(-Inf, 0);
	return pli(dB[bi] + B[que[l]] + (LL)dk[bi] * A[que[l]], que[l]);
}

int main() {
	scanf("%d", &N), S = sqrt(N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]), B[i] = A[i];
		bel[i] = (i - 1) / S + 1, p[i] = i;
	} T = bel[N];
	for (int i = 1; i <= T; ++i) {
		lb[i] = (i - 1) * S + 1;
		rb[i] = std::min(i * S, N);
		std::sort(p + lb[i], p + rb[i] + 1, [](int x, int y) {
			return A[x] < A[y];
		});
		Rebuild(i);
	}
	LL nowval = 0;
	for (int i = 1; i <= N; ++i) {
		pli now(-Inf, 0);
		for (int j = 1; j <= T; ++j)
			now = std::max(now, Ask(j));
		nowval += now.first;
		Ans = std::max(Ans, nowval);
		int pos = now.second, bp = bel[pos];
		for (int j = 1; j < bp; ++j) dB[j] += A[pos];
		for (int j = T; j > bp; --j) ++dk[j];
		for (int j = lb[bp]; j < pos; ++j) B[j] += A[pos];
		for (int j = rb[bp]; j > pos; --j) B[j] += A[j];
		cho[pos] = 1;
		Rebuild(bp);
	}
	printf("%lld\n", Ans);
	return 0;
}