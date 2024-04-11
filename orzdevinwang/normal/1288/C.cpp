#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 7;
const int mod = 1e9 + 7;
int n, m, dpa[12][N], dpb[12][N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) dpa[1][i] = dpb[1][i] = 1;
	for(int i = 2; i <= m; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			(cnt += dpa[i - 1][j]) %= mod;
			dpa[i][j] = cnt;
		}
		cnt = 0;
		for(int j = n; j >= 1; j--) {
			(cnt += dpb[i - 1][j]) %= mod;
			dpb[i][j] = cnt;
		}
	}
	int Ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			(Ans += 1ll * dpa[m][j] * dpb[m][i] % mod) %= mod;
		}
	}
	printf("%d\n", Ans);
	return 0;
}