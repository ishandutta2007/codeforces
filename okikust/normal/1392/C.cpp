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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 300000


int main() {
	long long a[N];
	int n, t;
	long long ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%lld", &a[i]);
		}
		ans = 0;
		f(i, n-1) {
			if (a[i] > a[i + 1])ans += (a[i] - a[i + 1]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}