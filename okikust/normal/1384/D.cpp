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
	int p[31];
	p[0] = 1;
	f(i, 30)p[i + 1] = p[i] * 2;
	f(i, N)a[i] = 0;
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
		z = 0;
		for (int i = 30; i >= 0; i--) {
			x = 0;
			f(j, n) {
				if ((a[j] & p[i]) == p[i])x++;
			}
			if (x % 4 == 1) {
				z = 1;
				break;
			}
			else if (x % 4 == 3) {
				if (n % 2 == 0)z = 1;
				else z = 2;
				break;
			}
		}
		if (z == 0)printf("DRAW\n");
		else if (z == 1)printf("WIN\n");
		else printf("LOSE\n");
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}