#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 7555;

double dp[M][N];
bool vis[M][N];

int k;

double f(int n, int m) {
	if (k < m || m < 0) return dp[n][m] = 0;
	if (vis[n][m]) return dp[n][m];
	vis[n][m] = true;
	if (n == 0) {
		if (m == 0) return dp[n][m] = 1;
		else return dp[n][m] = 0;
	}
	
	return dp[n][m] = f(n - 1, m) * m / k + f(n - 1, m - 1) * (k - m + 1) / k;
}

int main() {
	int q;
	scanf("%d %d", &k, &q);
	
	while (q--) {
		int p;
		scanf("%d", &p);
		
		int ans = 7500;
		int l = 1, r = 7500;
		
		while (l < r) {
			int mid = l + r >> 1;
			
			if (f(mid, k) * 2000 > p)
				ans = mid, r = mid;
			else l = mid + 1;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}