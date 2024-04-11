#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 107;
const int O = N * N * 2;
int T, n, m, a[N], b[N];
int dp[2][N][N * N * 4];
void Max(int &x, int y) {
	if(x < y) x = y;
}
void Main() {
	scanf("%d", &n);
	memset(dp, -10, sizeof(dp));
	int sum = 0;
	dp[0][0][O] = 0;
	L(i, 1, n) {
		int now = (i & 1);
		memset(dp[now], -10, sizeof(dp[now]));
		scanf("%d%d", &b[i], &a[i]);
		L(j, 0, i - 1) {
			L(k, -20000, 20000) {
				Max(dp[now][j + 1][O + k - 2 * (b[i] - a[i])], dp[now ^ 1][j][O + k] + a[i] * 2);
				//  
				
				Max(dp[now][j][O + k + a[i]], dp[now ^ 1][j][O + k] + a[i]);
				//  
			}
		}
		sum += a[i];
	}
	L(i, 1, n) {
		db maxn = 0;
		L(j, -20000, 20000) maxn = max(maxn, 1. * (dp[n & 1][i][O + j] - max(j, 0)) / 2); 
		printf("%.10lf ", maxn);
	}
}
int main() {
	Main();
	return 0;
}