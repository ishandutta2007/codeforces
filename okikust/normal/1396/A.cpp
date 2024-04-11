#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200010


int main() {
	long long a[N];
	long long n;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &a[i]);
	}
	if (n == 1) {
		printf("1 1\n");
		printf("%lld\n", -a[0]);
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		return 0;
	}
	printf("1 %lld\n", n);
	f(i, n - 1)printf("%lld ", -a[i] * n);
	printf("0\n");
	printf("1 %lld\n", n - 1);
	f(i, n - 2)printf("%lld ", a[i] * (n - 1));
	printf("%lld\n", a[n - 2] * (n - 1));
	printf("%lld %lld\n", n, n);
	printf("%lld\n", -a[n - 1]);
	return 0;
}