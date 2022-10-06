#include <cstdio>

typedef long long LL;
const int MN = 500005;

int N, A[MN];

int bit[MN];
inline void Add(int i, int x) {
	for (; i <= N; i += i & -i)
		bit[i] += x;
}
inline int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
}
inline int BS(int x) {
	// returning rightmost pos
	// s.t. Arr[pos] >= x
	// if not fount, return 0
	int i = 0;
	for (int j = 18; j >= 0; --j)
		if ((i | 1 << j) <= N && bit[i | 1 << j] >= x)
			x -= bit[i |= 1 << j];
	return i;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%1d", &A[i]);
	int prek = 0;
	LL Sum = 0, Ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (A[i]) {
			++prek;
			int pos = BS(prek) + 1;
			Add(pos, 1);
			Add(i + 1, -1);
			Sum += i - pos + 1;
		} else prek = 0;
		Ans += Sum;
	}
	printf("%lld\n", Ans);
	return 0;
}