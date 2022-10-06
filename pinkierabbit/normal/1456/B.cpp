#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)

const int MN = 100005;

int N, A[MN], S[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]), S[i] = S[i - 1] ^ A[i];
	if (N >= 65) return puts("1"), 0;
	int ans = 0x3f3f3f3f;
	for (int l = 0; l <= N; ++l)
		for (int mid = l + 1; mid <= N; ++mid)
			for (int r = mid + 1; r <= N; ++r)
				if ((S[l] ^ S[mid]) > (S[mid] ^ S[r])) {
					ans = min(ans, r - l);
				}
	if (ans == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", ans - 2);
	return 0;
}