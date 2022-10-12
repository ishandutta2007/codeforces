#include <bits/stdc++.h>
using namespace std;

const int N = 555;

int n, m;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  bool has[2] = {false, false};
  for (int i = 0; i < n; ++i) {
    int b;
    scanf("%d", &b);
    has[b] = true;
  }

  if (has[0] && has[1]) return 0 * printf("Yes\n");

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) return 0 * printf("No\n");
  }

  printf("Yes\n");
  return 0;
}


int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}