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
#define N 600000


int main() {
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k, t, l;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld %lld", &n, &k, &l);
		f(i, n) {
			scanf("%lld", &a[i]);
		}
		x = -1000000000000;
		y = 1000000000000;
		v = true;
		f(i, n) {
			if (a[i] + k <= l) {
				if (x > y) {
					v = false;
					break;
				}
				x = -1000000000000;
				y = 1000000000000;
			}
			else if (a[i] > l) {
				v = false;
				break;
			}
			else {
				x = max(a[i] - l + i, x);
				y = min(l - a[i] + i, y);
			}
		}
		if (x > y) {
			v = false;
		}
		if (v)printf("Yes\n");
		else printf("No\n");
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}