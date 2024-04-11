#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];
bool found[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  bool ok = true;
  bool inc = true;
  for (int i = n-2; i >= 0; --i) {
    if (inc) {
      if (a[i] < a[i+1]) {
        inc = false;
      }
    } else {
      if (a[i] > a[i+1]) {
        ok = false;
        printf("%d\n", i+1);
        break;
      }
    }
  }

  if (ok) printf("0\n");
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