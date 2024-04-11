#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,mmx")
#include <bits/stdc++.h>
using namespace std;

const int SZ = 4005;

int N, K;
int grid[SZ][SZ];

int cost[SZ][SZ];
int DP[2][SZ];

void dnc(int cur, int l, int r, int optL, int optR) {
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  int best = 1e9;
  int id = -1;
  for (int i = optL; i <= mid && i <= optR; i++) {
    int val = DP[cur ^ 1][i - 1] + cost[i][mid];
    if (val < best) {
      best = val;
      id = i;
    }
  }
  DP[cur][mid] = best;
  dnc(cur, l, mid - 1, optL, id);
  dnc(cur, mid + 1, r, id, optR);
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &grid[i][j]);
      grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      cost[i][j] = grid[j][j] - grid[j][i - 1] - grid[i - 1][j] + grid[i - 1][i - 1];
    }
  }
  
  for (int i = 1; i <= N; i++) {
    DP[0][i] = 1e9;
  }

  for (int k = 1; k <= K; k++) {
    dnc(k & 1, 1, N, 1, N);
  }

  printf("%d\n", (DP[K & 1][N] / 2));
  return 0;
}