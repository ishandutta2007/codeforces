#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
int T, n, a[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	if(n == 1) {
		printf("1 1\n");
		printf("%d\n", -a[1]);
		printf("1 1\n");
		printf("%d\n", 0);
		printf("1 1\n");
		printf("%d\n", 0);
		return 0;
	}
	printf("1 1\n");
	printf("%d\n", -a[1]);
	printf("%d %d\n", 2, n);
	L(i, 2, n) printf("%lld ", 1ll * (n - 1) * a[i]);
	puts("");
	printf("%d %d\n", 1, n);
	a[1] = 0;
	L(i, 1, n) printf("%lld ", -1ll * n * a[i]);
	puts("");
	return 0;
}