#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];
bool found[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n*2; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    found[i] = false;
  }

  for (int i = 0; i < n*2; ++i) {
    if (!found[a[i]]) {
      printf("%d ", a[i] + 1);
      found[a[i]] = true;
    }
  }

  printf("\n");
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