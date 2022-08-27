#include<bits/stdc++.h>
#define N 110000
#define ll long long
using namespace std;
int T, n;
ll a[N], dpa[N][6], dpb[N][6];
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		dpa[0][0] = dpb[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			dpa[i][0] = dpb[i][0] = 1;
			for(int j = 1; j <= min(i, 5); j++) {
				if(j != i) dpa[i][j] = dpa[i - 1][j], dpb[i][j] = dpb[i - 1][j];
				else dpa[i][j] = 1e18+7, dpb[i][j] = -1e18-7;
				if(a[i] < 0) 
					dpa[i][j] = min(dpa[i][j], dpb[i - 1][j - 1] * a[i]),
					dpb[i][j] = max(dpb[i][j], dpa[i - 1][j - 1] * a[i]);
				else 
					dpa[i][j] = min(dpa[i][j], dpa[i - 1][j - 1] * a[i]),
					dpb[i][j] = max(dpb[i][j], dpb[i - 1][j - 1] * a[i]);
			}
		}
		printf("%lld\n", dpb[n][5]);
	}
	return 0;
}