#include <cstdio>

const int MOD = 1000000007;

void add(int & a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}


int dp[42], next[42];


int main() {
  int c = getchar();
  while (c <= 32) c = getchar();
  dp[0] = 1;
  dp[1] = 1;
  while (c > 32) {
    for (int j = 0; j < 4; j++) next[j] = 0;
    if (c == '*') {
      add(next[3], dp[1]);
      add(next[3], dp[3]);
    } else if (c == '0') {
      add(next[0], dp[0]);
    } else if (c == '1') {
      add(next[1], dp[0]);
      add(next[0], dp[3]);
    } else if (c == '2') {
      add(next[1], dp[3]);
    } else if (c == '?') {
      add(next[3], dp[1]);
      add(next[3], dp[3]);
      add(next[0], dp[0]);
      add(next[1], dp[0]);
      add(next[0], dp[3]);
      add(next[1], dp[3]);
    }
    for (int j = 0; j < 4; j++) dp[j] = next[j];
    c = getchar();
  }
  int ans = 0;
  add(ans, dp[0]);
  add(ans, dp[3]);
  printf("%d\n", ans);
}