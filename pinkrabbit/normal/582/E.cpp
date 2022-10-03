#include <cstdio>
#include <cctype>

typedef long long LL;
const int Mod = 1000000007;
const int MZ = 168, MN = 16;

char S[MZ * 3];
int N, a[4][MN], Z;

int typ[MZ], lc[MZ], rc[MZ], cnt;
int DFS0(int i, int &r) {
	if (S[i] != '(') {
		int &t = typ[++cnt];
		if (S[i] == '?') t = 8;
		else t = S[i] - (isupper(S[i]) ? 'A' : 'a' - 4);
		return r = i + 1, cnt;
	}
	int ls = DFS0(i + 1, r), rt = ++cnt;
	lc[rt] = ls, i = r + 1;
	typ[rt] = S[i] == '?' ? 11 : 9 + (S[i] == '|');
	rc[rt] = DFS0(i + 2, r);
	return ++r, rt;
}

int Arr[MZ][1 << MN];
inline void FWT(int *A, int o, int t) {
	static int z;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < 1 << N; ++i) if ((i >> j ^ o) & 1)
			z = A[i ^ 1 << j], z = ~t ? z : Mod - z,
			A[i] -= (A[i] += z) >= Mod ? Mod : 0;
}
inline void Conv(int p, int q, int r, int t) {
	static int A[1 << MN], B[1 << MN];
	for (int i = 0; i < 1 << N; ++i) A[i] = Arr[p][i], B[i] = Arr[q][i];
	FWT(A, t, 1), FWT(B, t, 1);
	for (int i = 0; i < 1 << N; ++i) A[i] = (LL)A[i] * B[i] % Mod;
	FWT(A, t, -1);
	for (int i = 0; i < 1 << N; ++i) Arr[r][i] -= (Arr[r][i] += A[i]) >= Mod ? Mod : 0;
}
void DFS1(int i) {
	if (typ[i] < 9) {
		for (int o = 0; o < 2; ++o)
			for (int z = 0; z < 4; ++z)
				if (typ[i] == 8 || (o << 2 | z) == typ[i]) {
					int s = 0;
					for (int j = 0; j < N; ++j)
						s |= (o ^ a[z][j]) << j;
					++Arr[i][s];
				}
		return ;
	}
	DFS1(lc[i]), DFS1(rc[i]);
	if (typ[i] != 10) Conv(lc[i], rc[i], i, 1);
	if (typ[i] != 9) Conv(lc[i], rc[i], i, 0);
}

int main() {
	scanf("%s%d", S, &N);
	for (int i = 0, x; i < N; ++i) {
		for (int j = 0; j < 4; ++j) scanf("%d", &a[j][i]);
		scanf("%d", &x), Z |= x << i;
	}
	int len, rt = DFS0(0, len);
	DFS1(rt), printf("%d\n", Arr[rt][Z]);
	return 0;
}