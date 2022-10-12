#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int ans[N];

int solve() {
  int n;
  scanf("%d", &n);

  bool all = true;
  bool lst = true;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];

    if (a[i] != i) {
      if (lst) {
        ++cnt;
        lst = false;
      }
      all = false;
    } else {
      if (lst == false) {
        ++cnt;
        lst = true;
      }
    }
  }

  if (all) printf("%d\n", 0);
  else if (cnt <= 2) printf("1\n");
  else printf("2\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}