#include <stdio.h>
#include <string.h>

const int N = 5010;
const int mod = 1000000007;

int dp[2][N];
char a[N], b[N];
int n, k;

int main() {
  scanf("%s%s", a, b);
  int ans = 0;
  int la = strlen(a), lb = strlen(b);
  for(int i = la-1;i >= 0;i--) {
    int idx = i % 2;
    for(int j = lb-1;j >= 0;j--) {
      dp[idx][j] = 0;
      if(j < lb-1) dp[idx][j] = (dp[idx][j] + dp[idx][j+1]) % mod;
      if(a[i] == b[j]) {
        dp[idx][j] = (dp[idx][j] + 1) % mod;
        if(i < la-1 and j < lb-1) {
          dp[idx][j] = (dp[idx][j] + dp[!idx][j+1]) % mod;
        }
      }
      if(j == 0) {
        ans = (ans + dp[idx][j]) % mod;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}