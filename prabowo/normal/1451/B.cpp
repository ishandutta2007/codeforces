#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, q;
char s[N];

int solve() {
  scanf("%d %d", &n, &q);
  scanf("%s", s);

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    bool okay = false;
    for (int i = l-1; i >= 0; --i) if (s[i] == s[l]) okay = true;
    for (int i = r+1; i < n; ++i) if (s[i] == s[r]) okay = true;

    if (okay) printf("YES\n"); else printf("NO\n");
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}