#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
int Mod;
const int MN = 50005;

int N, M, s[MN], val[MN], per[MN];
LL K, pos[MN];

struct Mat {
	int A[2][2];
	Mat() {}
	Mat(int t) { A[0][0] = A[1][1] = t; A[0][1] = A[1][0] = 0; }
	Mat(int a, int b, int c, int d) { A[0][0] = a, A[0][1] = b, A[1][0] = c, A[1][1] = d; }
	inline friend Mat operator * (const Mat &A, const Mat &B) {
		Mat C;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				C.A[i][j] = ((LL)A.A[i][0] * B.A[0][j] + (LL)A.A[i][1] * B.A[1][j]) % Mod;
		return C;
	}
} t[MN][60];

int main() {
	scanf("%lld%d", &K, &Mod);
	if (Mod == 1 || !K) return puts("0"), 0;
	if (K == 1) return puts("1"), 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &s[i]), s[i] %= Mod;
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) scanf("%lld%d", &pos[i], &val[i]), val[i] %= Mod, per[i] = i;
	std::sort(per + 1, per + M + 1, [](int i, int j) { return pos[i] < pos[j]; });
	for (int i = 0; i < N; ++i) t[i][0] = Mat(0, 1, s[i], s[(i + 1) % N]);
	for (int j = 0; j < 59; ++j)
		for (int i = 0; i < N; ++i)
			t[i][j + 1] = t[(i + (1ll << j)) % N][j] * t[i][j];
	Mat Ans(1); LL npos = 0; int jpos = 1;
	while (npos < K) {
		if (jpos <= M && pos[per[jpos]] < npos) ++jpos;
		LL nxpos = jpos <= M ? pos[per[jpos]] : 0x3f3f3f3f3f3f3f3f;
		if (nxpos > npos + 1) {
			LL dif = nxpos - npos - 1;
			if (dif > K - npos) dif = K - npos;
			for (int j = 0; dif; ++j, dif >>= 1)
				if (dif & 1) Ans = t[npos % N][j] * Ans, npos += 1ll << j;
		} else {
			int v0 = 0, v1 = 0;
			if (nxpos == npos + 1) v0 = s[npos % N], v1 = val[per[jpos]];
			else
				v0 = val[per[jpos]],
				v1 = jpos < M && pos[per[jpos + 1]] == npos + 1 ? val[per[jpos + 1]] : s[(npos + 1) % N];
			Ans = Mat(0, 1, v0, v1) * Ans;
			++npos;
		}
	}
	printf("%d\n", Ans.A[0][1]);
	return 0;
}