#include <bits/stdc++.h>
using namespace std;

const int N = 105;

char s[N];

void solve() {
  scanf("%s", s);
  bool one = false;
  int ans = 0;
  int cnt = 0;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (one) ans += cnt;
      one = true;
      cnt = 0;
    } else if (s[i] == '0') {
      ++cnt;
    }
  }

  printf("%d\n", ans);
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}