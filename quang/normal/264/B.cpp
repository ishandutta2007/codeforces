#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int p[N];
int res = 1;
int dp[N];
int st[20], top;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  p[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      for (int j = i; j < N; j += i) {
        p[j] = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    top = 0;
    int u = a[i];
    while (u > 1) {
      int x = p[u];
      st[top++] = x;
      while (u % x == 0) {
        u /= x;
      }
    }
    int f = 0;
    for (int j = 0; j < top; j++) {
      f = max(f, dp[st[j]] + 1);
    }
    res = max(res, f);
    for (int j = 0; j < top; j++) {
      dp[st[j]] = max(dp[st[j]], f);
    }
  }
  cout << res << endl;
  return 0;
}