#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)

const int MAXN = 1e5 + 10;

int a[MAXN];
int n;
vector<pair<int, int>> res;
int sum[2][MAXN];

int get_sum(int l, int r, int c) {
  return sum[c][r + 1] - sum[c][l];
}

void go(int i, int* win, int t) {
  int l = i - 1;
  int r = n;
  while (l != r - 1) {
    int m = (l + r) >> 1;
  
    if  (max(get_sum(i, m, 0), get_sum(i, m, 1)) < t)
      l = m;
    else 
      r = m;
  }

  if  (r == n) return;

  forn(c, 2) {
    if  (get_sum(i, r, c) == t) {
      ++win[c];
      if  (r < n - 1) {
        go(r + 1, win, t);
      } else {
        if  (win[c] > win[c ^ 1]) res.push_back(make_pair(win[c], t));
      }
      break;
    }
  }
}
 
int main() {
  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
    --a[i];
  }

  forn(c, 2) {
    sum[c][0] = 0;
    forn(i, n) {
      sum[c][i + 1] = sum[c][i] + (a[i] == c);
    }
  }

  for (int t = 1; t <= n; ++t) {
    int* win = new int[2];
    win[0] = win[1] = 0;
    go(0, win, t);
  }

  sort(res.begin(), res.end());
  printf("%d\n", res.size());
  forn(i, res.size()) {
    printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}