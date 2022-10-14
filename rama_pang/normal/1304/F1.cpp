/**
 * Let dp(i, j) = maximum answer, using first i rows and the last rectangle is at j-th column.
 * 
 * To transition from dp(i - 1) to dp(i), we need:
 * for k = 1 to M
 *   if (k + K - 1 < j) dp(i, k) max= dp(i - 1, j) + cost
 *   if (k - K + 1 > j) dp(i, k) max= dp(i - 1, j) + cost
 *   else dp(i, k) max= dp(i - 1, j) + cost - intersection
 * 
 * Save these in a segment tree, and we can query for them easily.
 * 
**/


#include <bits/stdc++.h>
using namespace std;

const int ROW = 55;
const int MAX = 20005;

int N, M, K;
int A[ROW][MAX]; // animal
int P[ROW][MAX]; // prefix sum
int DP[ROW][MAX]; // DP[i][j] = in the i-th day, place tha camera to observe (i, i + 1)(j, j + K - 1)

int tree[MAX * 4], lazy[MAX * 4]; // RMQ with range sum update

void push(int n) {
  tree[n * 2] += lazy[n];
  tree[n * 2 + 1] += lazy[n];
  lazy[n * 2] += lazy[n];
  lazy[n * 2 + 1] += lazy[n];
  lazy[n] = 0;
}

void pull(int n) {
  tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

void update(int n, int tl, int tr, int l, int r, int x) {
  if (r < tl || tr < l || tl > tr) {
    return;
  }
  if (l <= tl && tr <= r) {
    tree[n] += x;
    lazy[n] += x;
    return;
  }
  push(n);
  int mid = (tl + tr) / 2;
  update(n * 2, tl, mid, l, r, x);
  update(n * 2 + 1, mid + 1, tr, l, r, x);
  pull(n);
}

int query() {
  return tree[1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 1; i <= N + 1; i++) {
    for (int j = 1; j <= M; j++) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + A[i][j];
    }
  }

  auto sum = [&](int i1, int j1, int i2, int j2) {
    return P[i2][j2] - P[i2][j1 - 1] - P[i1 - 1][j2] + P[i1 - 1][j1 - 1];
  };

  for (int j = 1; j <= M - K + 1; j++) {
    DP[1][j] = sum(1, j, 2, j + K - 1);
  }
  
  for (int i = 2; i <= N; i++) {
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    for (int j = 1; j <= M - K + 1; j++) {
      update(1, 1, M - K + 1, j, j, DP[i - 1][j]);
    }
    for (int j = 1; j <= K; j++) {
      update(1, 1, M - K + 1, 1, j, - A[i][j]);
    }
    for (int j = 1; j <= M - K + 1; j++) {
      DP[i][j] = query() + sum(i, j, i + 1, j + K - 1);
      if (j < M - K + 1) {
        update(1, 1, M - K + 1, max(1, j - K + 1), j, A[i][j]);
        update(1, 1, M - K + 1, j + 1, j + K, - A[i][j + K]);
      }
    }
  }

  int ans = 0;
  for (int j = 1; j <= M - K + 1; j++) {
    ans = max(ans, DP[N][j]);
  }

  cout << ans << "\n";
  return 0;
}