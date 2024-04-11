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
#define N 300010


int main() {
	char a[N];
	f(i, N)a[i] = 0;
	char b[N];
	int n, t;
	int ans;
	bool v;
	int k;
	int x;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		scanf("%s", a);
		ans = 0;
		v = true;
		f(i, n) {
			if (a[i] != a[0]) {
				k = i;
				v = false;
				break;
			}
		}
		if (v) {
			ans = (n + 2) / 3;
		}
		else {
			f(i, n) {
				x = (i + k) % n;
				b[i] = a[x];
			}
			k = 0;
			x = 0;
			f(i, n) {
				if (b[i] != b[k]) {
					ans += (x / 3);
					x = 1;
					k = i;
				}
				else x++;
			}
			ans += (x / 3);
		}
		printf("%d\n", ans);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}