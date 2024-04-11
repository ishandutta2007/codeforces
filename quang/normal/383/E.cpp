#include <bits/stdc++.h>

using namespace std;

const int x = 24;

int a[1 << x];

int main() {
  char s[4];
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int mask = 0;
    for (int i = 0; i < 3; i++) {
      mask |= (1 << (s[i] - 'a'));
    }
    mask ^= ((1 << x) - 1);
    a[mask]++;
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < (1 << x); j++) {
      if (j & (1 << i)) {
        a[j ^ (1 << i)] += a[j];
      }
    }
  }
  int res = 0;
  for (int i = 0; i < (1 << x); i++) {
    res ^= (n - a[i]) * (n - a[i]);
  }
  cout << res << endl;
  return 0;
}