#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, Q, w[101000];
int main() {
	int i, j;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	while (Q--) {
		int ck, a, b, c, r =0 ;
		scanf("%d%d%d%d", &ck,&a,&b,&c);
		if (ck == 1) {
			for (i = a; i <= b; i++)if (w[i] > c)w[i] -= c;
		}
		else {
			for (i = a; i <= b; i++)if (w[i] == c)r++;
			printf("%d\n", r);
		}
	}
}