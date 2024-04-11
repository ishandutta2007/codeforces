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
#define N 200000


int main() {
	long long p2[60];
	long long a[30][30];
	p2[0] = 1;
	f(i, 59)p2[i + 1] = p2[i] * 2;
	f(i, 30)a[0][i] = 0;
	f(i, 30)a[i][29] = 0;
	for (long long i = 1; i < 30; i++) {
		for (long long j = 0; j < 29; j++) {
			if (a[i - 1][j + 1] == 0)a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	long long n, k, q;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &n);
	f(i, n) {
		f(j, n) {
			x = p2[i + j] * a[i][j];
			printf("%lld", x);
			if (j < (n - 1))printf(" ");
			else printf("\n");
		}
		fflush(stdout);
	}
	scanf("%lld", &q);
	f(qq, q) {
		scanf("%lld", &k);
		k /= 2;
		x = 0;
		y = 0;
		printf("%lld %lld\n", x + 1, y + 1);
		fflush(stdout);
		z = 2 * n - 2;
		f(i, z) {
			if (k % 2 == 1) {
				if (a[x + 1][y] == 1)x++;
				else y++;
			}
			else {
				if (a[x + 1][y] == 0)x++;
				else y++;
			}
			k /= 2;
			printf("%lld %lld\n", x + 1, y + 1);
			fflush(stdout);
		}
	}



	return 0;
}