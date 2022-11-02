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
	int c4, c2;
	char c[3];
	int n, q;
	int x;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a[x]++;
	}
	c4 = 0;
	c2 = 0;
	f(i, N) {
		c4 += (a[i] / 4);
		c2 += (a[i] / 2);
	}
	scanf("%d", &q);
	f(qq, q) {
		f(i, 3)c[i] = 0;
		scanf("%s", c);
		scanf("%d", &x);
		c4 -= (a[x] / 4);
		c2 -= (a[x] / 2);
		if (c[0] == '+')a[x]++;
		else a[x]--;
		c4 += (a[x] / 4);
		c2 += (a[x] / 2);
		if ((c4 > 0) && (c2 >= 4))printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}