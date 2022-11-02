#include <bits/stdc++.h>
using namespace std;

long long dp[505][505];
int n;
int b[505];
int i,j;

long long MOD = 1000000007;

long long hitung(int l, int r) {
	long long &ret = dp[l][r];
	if (ret >= 0) return ret;
	if (l > r) return 1;
	ret = 0;
	for (int i = l; i <= r; i++) {
		if (i == r || b[l] < b[i + 1]) {
			ret = (ret + hitung(l + 1, i) * hitung(i + 1, r)) % MOD;  
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}	
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", hitung(1, n-1));
}