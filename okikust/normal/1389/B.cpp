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
	int b[N];
	int c[N];
	int d[N];
	int n, k, t;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d %d", &n, &k, &z);
		f(i, n) {
			scanf("%d", &a[i]);
		}
		b[0] = a[0];
		f(i, n - 1)b[i + 1] = b[i] + a[i+1];
		f(i, n - 1)c[i] = a[i] + a[i + 1];
		d[0] = c[0];
		f(i, n - 2)d[i + 1] = max(d[i], c[i + 1]);
		ans = b[k];
		for(int zz=1;zz<=z;zz++){
			x = k - zz * 2;
			if (x >= 0) {
				s = b[x];
				s += zz * d[x];
				ans = max(ans, s);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}