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
	char b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k, t;
	int x, y, z;
	int ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		scanf("%s", a);
		scanf("%s", b);
		v = true;
		f(i, n) {
			if (a[i] > b[i]) {
				v = false;
				break;
			}
		}
		if (!v) {
			printf("-1\n");
			f(i, n + 1) {
				a[i] = 0;
				b[i] = 0;
			}
			continue;
		}
		ans = 0;
		while (true) {
			x = 100;
			y = 100;
			f(i, n) {
				if (a[i] < b[i]) {
					if ((a[i] - 'a') < x) {
						x = a[i] - 'a';
						y = b[i] - 'a';
					}
					else if ((a[i] - 'a') == x) {
						y = min(y, b[i] - 'a');
					}
				}
			}
			if (x == 100)break;
			ans++;
			f(i, n) {
				if (a[i] < b[i]) {
					if (a[i] == 'a' + x)a[i] = 'a' + y;
				}
			}
		}
		printf("%d\n",ans);
		f(i, n + 1) {
			a[i] = 0;
			b[i] = 0;
		}
	}

	return 0;
}