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
	int a[N];
	f(i, N)a[i] = 0;
	int n, k, t;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		if (n < 31)printf("NO\n");
		else if (n == 36) {
			printf("YES\n");
			printf("5 6 10 15\n");
		}
		else if (n == 40) {
			printf("YES\n");
			printf("2 6 10 22\n");
		}
		else if (n == 44) {
			printf("YES\n");
			printf("6 7 10 21\n");
		}
		else {
			printf("YES\n");
			printf("6 10 14 %d\n",n - 30);
		}
	}

	return 0;
}