#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005;
const int V = 300000;
const int MV = V + 5;

int N, A[MN];
LL Ans[MN];

int b1[MV];
LL b2[MV];
template<typename T>
inline void Add(T *b, int i, T x) {
	for (; i <= V; i += i & -i)
		b[i] += x;
}
template<typename T>
inline T Qur(T *b, int i) {
	T s = 0;
	for (; i; i -= i & -i)
		s += b[i];
	return s;
}

int main() {
//	freopen("F.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
//	N = 200000;
//	for (int i = 1; i <= N; ++i)
//		A[i] = N - i + 1;
	LL now = 0, sum = 0; int maxa = 0;
	for (int i = 2; i <= N; ++i) {
		Add(b1, A[i - 1], 1);
		for (int w = A[i - 1]; w <= V; w += A[i - 1])
			Add(b2, w, (LL)A[i - 1]);
		sum += A[i - 1];
		maxa = std::max(maxa, A[i - 1]);
		int v = A[i];
		now += sum;
		LL tmp = 0;
		for (int w = v - 1, j = 1; ; w += v, ++j) {
			tmp -= Qur(b1, w);
			if (w + v >= maxa) {
				tmp += (LL)j * (i - 1);
				break;
			}
		}
		now -= v * tmp;
		now += (LL)v * (i - 1);
		now -= Qur(b2, v);
		Ans[i] = now;
	}
	for (int i = 1; i <= N; ++i)
		printf("%lld%c", Ans[i], " \n"[i == N]);
	return 0;
}