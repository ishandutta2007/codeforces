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
	char c[150];
	int n, k, t;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%d", &a[i]);
		}
		f(i, 150)c[i] = 'a';
		printf("%s\n", c);
		f(i, n) {
			for (int j = a[i]; j < 150; j++) {
				if (c[j] == 'a')c[j] = 'b';
				else c[j] = 'a';
			}
			printf("%s\n", c);
		}
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}