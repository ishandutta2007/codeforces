#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)

typedef long long LL;
const int MN = 500005;

int N, K, C[MN];
LL S[MN], f[MN];

int main() {
	scanf("%d%d", &N, &K), ++K;
	for (int i = 1; i <= N; ++i) scanf("%d", &C[i]);
	sort(C + 1, C + N + 1, greater<int>());
//	for (int i = 1; i <= N; ++i) printf("%d, ", C[i]); puts("");
	for (int i = 1; i <= N; ++i) S[i] = S[i - 1] + C[i];
	int pos = 0;
	for (int i = 1; i <= N; ++i) if (S[i] >= 0) pos = i;
//	printf("pos = %d\n", pos);
	for (int i = 1; i <= N; ++i) {
		if (i <= pos) {
			f[i] = f[i - 1] + S[i - 1];
		} else if (i - K <= pos) {
			f[i] = f[pos] + S[pos];
		} else {
			f[i] = f[i - K] + S[i - K];
		}
//		printf("f[%d] = %lld (tr = %lld)\n", i, f[i], f[i] + S[i]);
	}
	printf("%lld\n", f[N]);
	return 0;
}