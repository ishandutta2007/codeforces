#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 333;
int T, n, s[N], dp[N][N << 1];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        L(i, 1, n) scanf("%d", &s[i]);
        sort(s + 1, s + n + 1);
        L(i, 0, n) fill(dp[i], dp[i] + 2 * n + 1, 1e9);
        dp[0][0] = 0;
        L(i, 1, n) {
            int minn = dp[i - 1][0];
            L(j, 1, n * 2) {
                dp[i][j] = minn + abs(s[i] - j);
                minn = min(minn, dp[i - 1][j]);
            }
        }
        int ans = 1e9;
        L(i, 1, n * 2) ans = min(ans, dp[n][i]);
        printf("%d\n", ans);
    }
	return 0;
}