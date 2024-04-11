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
#define N 200000


int main() {
	int n, k, t;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%lld %lld", &x, &y);
		if (2 * x <= y) {
			printf("%lld %lld\n", x, 2 * x);
		}
		else printf("-1 -1\n");
	}

	return 0;
}