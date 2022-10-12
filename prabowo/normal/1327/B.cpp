#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
bool taken[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) taken[i] = false;

  int daughter = -1;
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    bool found = false;
    for (int j = 0; j < k; ++j) {
      int g;
      scanf("%d", &g);
      --g;
      if (!found && !taken[g]) {
        taken[g] = true;
        found = true;
      }
    }

    if (!found && daughter == -1) {
      daughter = i;
    }
  }

  if (daughter == -1) return 0 * printf("OPTIMAL\n");

  for (int i = 0; i < n; ++i) {
    if (!taken[i]) return 0 * printf("IMPROVE\n%d %d\n", daughter + 1, i + 1);
  }

  printf("OPTIMAL\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}