#include<bits/stdc++.h>
#define N 2010
using namespace std;
int n, m;
char a[N][N];
short dpa[N][N], dpb[N][N], dpc[N][N], dpd[N][N];
long long Ans;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%s", a[i]+1);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) {
			if(a[i][j] != a[i-1][j] || a[i][j] != a[i][j-1]) dpa[i][j] = 1;
			else dpa[i][j] = min(dpa[i-1][j], dpa[i][j-1]) + 1;
		}
	for(int i = n; i >= 1; i--) 
		for(int j = 1; j <= m; j++) {
			if(a[i][j] != a[i+1][j] || a[i][j] != a[i][j-1]) dpb[i][j] = 1;
			else dpb[i][j] = min(dpb[i+1][j], dpb[i][j-1]) + 1;
		}
	for(int i = 1; i <= n; i++) 
		for(int j = m; j >= 1; j--) {
			if(a[i][j] != a[i-1][j] || a[i][j] != a[i][j+1]) dpc[i][j] = 1;
			else dpc[i][j] = min(dpc[i-1][j], dpc[i][j+1]) + 1;
		}
	for(int i = n; i >= 1; i--) 
		for(int j = m; j >= 1; j--) {
			if(a[i][j] != a[i+1][j] || a[i][j] != a[i][j+1]) dpd[i][j] = 1;
			else dpd[i][j] = min(dpd[i+1][j], dpd[i][j+1]) + 1;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) 
			Ans += min(min(dpa[i][j], dpb[i][j]), min(dpc[i][j], dpd[i][j]));
	printf("%lld\n", Ans);
	return 0;
}