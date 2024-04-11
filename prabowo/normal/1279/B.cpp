#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, s;
int a[N];

int solve() {  
  scanf("%d %d", &n, &s);

  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  pair<int, int> maks = {0, 0};
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    maks = max(maks, {a[i], i+1});

    if (cur > s) {
      return 0 * printf("%d\n", maks.second);
    }
  }

  printf("0\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}