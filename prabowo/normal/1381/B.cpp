#include <bits/stdc++.h>
using namespace std;

const int N = 4005;

int n;
int a[N*2];

int dp[N*2][N];

vector<int> v;
int f(int x, int sum) {
  if (sum == n) return 1;
  if (sum > n) return 0;
  if (x == v.size()) return 0;
  if (~dp[x][sum]) return dp[x][sum];
  return dp[x][sum] = max(f(x+1, sum), f(x+1, sum + v[x]));
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n*2; ++i) {
    scanf("%d", &a[i]);
  }
  v.clear();

  for (int i = n*2-1; i >= 0;) {
    int idx = i;
    for (int j = i-1; j >= 0; --j) {
      if (a[j] > a[idx]) idx = j;
    }

    v.push_back(i - idx + 1);
    i = idx - 1;
  }

  for (int i = 0; i <= n*2; ++i) for (int j = 0; j <= n; ++j) {
    dp[i][j] = -1;
  }

  if (f(0, 0)) printf("YES\n");
  else printf("NO\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}