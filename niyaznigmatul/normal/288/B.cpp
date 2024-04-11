#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

const int md = 1000000007;

int ans2, n, k;
int p[10];
int was[10];
int got[10];

bool dfs(int v) {
  if (v == 0) return true;
  was[v] = true;
  if (was[p[v]]) {
    got[v] = got[p[v]];
  } else {
    got[v] = dfs(p[v]);
  }
  return got[v];
}

void go(int v) {
  if (v == k) {
    bool ok = true;
    for (int i = 0; i < k; i++) got[i] = was[i] = 0;
    for (int i = 0; i < k; i++) {
      int gt = was[i] ? got[i] : dfs(i);
      if (!gt) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++ans2;
    }
    return;
  }
  for (int i = 0; i < k; i++) {
    if (v != 0 && i == v) {
      continue;
    }
    p[v] = i;
    go(v + 1);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  long long ans1 = 1;
  for (int i = 1; i <= n - k; i++) {
    ans1 = ans1 * (n - k) % md;
  }
  ans2 = 0;
  go(0);
  printf("%d\n", (int) (ans1 * ans2 % md));
}