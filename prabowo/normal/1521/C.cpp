#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;

int askdebug(int t, int i, int j, int x) {
  ++x;
  vector<int> p = {2,5,3,4,1};
  if (t == 1) {
    return max(min(x, p[i]), min(x + 1, p[j])) - 1;
  }
  return min(max(x, p[i]), max(x + 1, p[j])) - 1;
}

int ask(int t, int i, int j, int x) {
  // return askdebug(t, i, j, x);
  printf("? %d %d %d %d\n", t, i + 1, j + 1, x + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret - 1;
}

int findSmallest() {
  vector<int> pot;
  for (int i = 0; i < n; i += 2) {
    if (i + 1 >= n) {
      pot.push_back(i);
    } else {
      int res = ask(2, i, i + 1, 0);
      if (res == 0) return i;
      if (res == 1) {
        pot.push_back(i);
        pot.push_back(i + 1);
      }
    }
  }

  assert(pot.size() <= 5);

  if (pot.size() == 1) return pot[0];

  for (int i = 0; i < pot.size(); ++i) {
    for (int j = 0; j < pot.size(); ++j) {
      if (i == j) continue;
      if (ask(2, pot[i], pot[j], 0) == 0) return pot[i];
    }
  }

  assert(0);
  return -1;
}

int solve() {
  scanf("%d", &n);

  int smallest = findSmallest();
  vector<int> ans(n);
  ans[smallest] = 0;

  for (int i = 0; i < n; ++i) {
    if (i == smallest) continue;
    ans[i] = ask(1, smallest, i, n - 2);
  }

  printf("!");
  for (int i = 0; i < n; ++i) printf(" %d", ans[i] + 1);
  printf("\n");
  fflush(stdout);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}