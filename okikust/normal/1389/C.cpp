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
	char a[N];
	f(i, N)a[i] = 0;
	int b[10];
	int c[10][10];
	int n, k, t;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
			scanf("%s", a);
			n = strlen(a);
			k = 0;
			f(i, 10) {
				x = 0;
				f(j, n) {
					if ((a[j] - '0') == i)x++;
				}
				k = max(k, x);
			}
			f(i, 10) {
				f(j, 10) {
					v = true;
					x = 0;
					f(ii, n) {
						if (v && ((a[ii] - '0') == i)) {
							v = false;
						}
						else if ((!v) && ((a[ii] - '0') == j)) {
							x++;
							v = true;
						}
					}
					x *= 2;
					k = max(k, x);
				}
			}
			printf("%d\n", n - k);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}