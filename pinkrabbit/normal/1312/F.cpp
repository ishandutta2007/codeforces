#include <cstdio>
#include <vector>

typedef long long LL;
const int MN = 300005;

int N, X, Y, Z; LL A[MN];

int sg[37][3], sp[37], tmp[6][3], cycst, cyclen;
inline int mex(std::vector<int> V) {
	static int buk[4];
	for (int x : V) buk[x] = 1;
	int y = 0;
	while (buk[y]) ++y;
	for (int x : V) buk[x] = 0;
	return y;
}
inline void Init() {
	for (int i = 1, ok = 0; !ok; ++i) {
		int cv = sp[i - 1];
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 3; ++k)
				tmp[j + 1][k] = cv >> (2 * (3 * j + k)) & 3;
		int a = mex({tmp[X][0], tmp[Y][1], tmp[Z][2]});
		int b = mex({tmp[X][0], tmp[Z][2]});
		int c = mex({tmp[X][0], tmp[Y][1]});
		sg[i][0] = a, sg[i][1] = b, sg[i][2] = c;
		sp[i] = (cv << 6 | c << 4 | b << 2 | a) & 0x3fffffff;
		for (int j = 0; j < i; ++j) if (sp[j] == sp[i]) {
			cycst = j, cyclen = i - j;
			ok = 1;
			break;
		}
	}
}
inline int getSG(LL i, int j) {
	if (i <= 0) return 0;
	if (i < cycst) return sg[i][j];
	return sg[cycst + (i - cycst) % cyclen][j];
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &N, &X, &Y, &Z);
		Init();
		int val = 0, Ans = 0;
		for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]), val ^= getSG(A[i], 0);
		for (int i = 1; i <= N; ++i)
			Ans += !(val ^ getSG(A[i], 0) ^ getSG(A[i] - X, 0)),
			Ans += !(val ^ getSG(A[i], 0) ^ getSG(A[i] - Y, 1)),
			Ans += !(val ^ getSG(A[i], 0) ^ getSG(A[i] - Z, 2));
		printf("%d\n", Ans);
	}
	return 0;
}