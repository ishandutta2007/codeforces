#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

char s[N];

int cnt[26];
long long cnt2[26][26];

int solve() {
  scanf("%s", s);

  int n = strlen(s);

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      cnt2[j][c] += cnt[j];
    }

    ++cnt[c];
  }

  for (int i = 0; i < 26; ++i) {
    ans = max(ans, 1LL * cnt[i]);
    for (int j = 0; j < 26; ++j) ans = max(ans, cnt2[i][j]);
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}