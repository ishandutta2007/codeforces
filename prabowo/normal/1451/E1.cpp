#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n;
int a[N];

int askand(int i, int j) {
  printf("AND %d %d\n", i + 1, j + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int askor(int i, int j) {
  printf("OR %d %d\n", i + 1, j + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int askxor(int i, int j) {
  printf("XOR %d %d\n", i + 1, j + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

void answer(vector<int> ans) {
  printf("!");
  for (int u: ans) printf(" %d", u);
  printf("\n");
  fflush(stdout);
  exit(0);
}

int pxor[N];
vector<int> x[N];

int solve() {
  scanf("%d", &n);

  vector<int> ans(n);
  for (int i = 1; i < n; ++i) {
    pxor[i] = askxor(0, i);
    x[pxor[i]].emplace_back(i);
  }

  if (x[0].size() > 0) {
    ans[0] = askand(0, x[0][0]);
    for (int i = 1; i < n; ++i) {
      ans[i] = (pxor[i] ^ ans[0]);
    }
    answer(ans);
  }

  for (int i = 1; i < n; ++i) {
    if (x[i].size() > 1) {
      int j = x[i][0], k = x[i][1];

      ans[0] = (pxor[j] ^ askand(j, k));
      for (int i = 1; i < n; ++i) {
        ans[i] = (pxor[i] ^ ans[0]);
      }
      answer(ans);
    }
  }

  ans[0] = askand(0, x[1][0]) | askand(0, x[2][0]);
  for (int i = 1; i < n; ++i) {
    ans[i] = (pxor[i] ^ ans[0]);
  }
  answer(ans);


  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}