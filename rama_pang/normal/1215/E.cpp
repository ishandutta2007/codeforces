#include <bits/stdc++.h>
using namespace std;

const int maxn = 400005;
const int color = 20;

long long minSwap[color][color]; // minSwap[i][j] = swaps so color i appears before color j
long long dp[1 << color];
int freq[color];
int a[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  { // compute minSwap[i][j]
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < color; j++) if (j != a[i]) {
        minSwap[a[i]][j] += freq[j];
      }
      freq[a[i]]++;
    }
  }

  fill(dp, dp + (1 << color), 1e18);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << color); mask++) {
    for (int i = 0; i < color; i++) {
      if (mask & (1 << i)) {
        continue;
      }
      long long cost = 0;
      for (int j = 0; j < color; j++) {
        if (mask & (1 << j)) {
          cost += minSwap[i][j];
        }
      }
      int nxtMask = mask | (1 << i);
      dp[nxtMask] = min(dp[nxtMask], dp[mask] + cost);
    }
  }
  
  cout << dp[(1 << color) - 1] << "\n";
  return 0;
}