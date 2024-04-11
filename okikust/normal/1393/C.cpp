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
	int x, y, ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		k = 0;
		f(i, n) {
			scanf("%d", &x);
			a[x - 1]++;
			k = max(k, a[x-1]);
		}
		y = 0;
		f(i, n) {
			if (a[i] == k)y++;
		}
		ans = (n - y) / (k - 1);
		ans--;
		printf("%d\n", ans);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}