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
	long long b[N];
	long long c[N];
	long long ma, mb;
	long long k;
	int n, t;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %lld", &n, &k);
		ma = -1000000000000;
		f(i, n) {
			scanf("%lld", &a[i]);
			ma = max(a[i], ma);
		}
		mb = -1000000000000;
		f(i, n) {
			b[i] = ma - a[i];
			mb = max(b[i], mb);
		}
		f(i, n)c[i] = mb - b[i];
		if (k % 2 == 1) {
			f(i, n - 1)printf("%lld ", b[i]);
			printf("%lld\n", b[n - 1]);
		}
		else {
			f(i, n - 1)printf("%lld ", c[i]);
			printf("%lld\n", c[n - 1]);
		}
	}

	return 0;
}