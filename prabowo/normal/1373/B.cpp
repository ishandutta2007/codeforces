#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int MOD = 998244353;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);

  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - '0'];
  }

  if (min(cnt[0], cnt[1]) & 1) printf("DA\n");
  else printf("NET\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}