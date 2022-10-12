#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

pair<int, int> ord[N];

int solve() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ord[i] = {a[i], i};
  }

  sort(ord, ord + n);

  int maxi = 1;

  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (ord[i-1].second < ord[i].second) {
      ++cnt;
    } else {
      cnt = 1;
    }
    maxi = max(maxi, cnt);
  }

  printf("%d\n", n - maxi);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}