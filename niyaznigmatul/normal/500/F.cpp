#include <bits/stdc++.h>

int const M = 4002;
int const sh = 1 << 13;

int ans[sh][M];
std::vector<int> add[2 * sh];
int start[sh], end[sh], cost[sh], hap[sh], tms[sh];

void put(int v, int left, int right, int l, int r, int id) {
  if (right <= l || r <= left) {
    return;
  }
  if (l <= left && right <= r) {
    add[v].push_back(id);
    return;
  }
  int mid = (left + right) >> 1;
  put(v * 2, left, mid, l, r, id);
  put(v * 2 + 1, mid, right, l, r, id);
}

void go(int v, int left, int right, int dp[M]) {
  int next[M];
  for (int i = 0; i < M; i++) next[i] = dp[i];
  for (int id : add[v]) {
    for (int i = M - 1; i >= cost[id]; i--) {
      if (next[i] < next[i - cost[id]] + hap[id]) {
        next[i] = next[i - cost[id]] + hap[id];
      }
    }
  }
  if (left + 1 == right) {
    for (int i = 0; i < M; i++) ans[left][i] = next[i];
    return;
  }
  int mid = (left + right) >> 1;
  go(v * 2, left, mid, next);
  go(v * 2 + 1, mid, right, next);
}

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  int cn = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", cost + i, hap + i, start + i);
    tms[cn++] = start[i];
    tms[cn++] = start[i] + p;
  }
  std::sort(tms, tms + cn);
  cn = std::unique(tms, tms + cn) - tms;
  for (int i = 0; i < n; i++) {
    end[i] = std::lower_bound(tms, tms + cn, start[i] + p) - tms;
    start[i] = std::lower_bound(tms, tms + cn, start[i]) - tms;
  }
  for (int i = 0; i < n; i++) {
    put(1, 0, sh, start[i], end[i], i);
  }
  int dp[M];
  for (int i = 0; i < M; i++) dp[i] = 0;
  go(1, 0, sh, dp);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int ct, money;
    scanf("%d%d", &ct, &money);
    int where = std::upper_bound(tms, tms + cn, ct) - tms;
    if (where == 0 || where >= cn) {
      puts("0");
      continue;
    }
    --where;
    printf("%d\n", ans[where][money]);
  }
}