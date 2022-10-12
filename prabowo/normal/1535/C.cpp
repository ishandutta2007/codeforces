#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  int cnt[2][2] = {0, 0, 0, 0};

  long long ans = 0;
  int j = 0;
  // cerr << "TEST" << endl;
  for (int i = 0; i < n; ++i) {
    while (j < n) {
      if (s[j] == '?') {
        ++j;
        continue;
      }

      ++cnt[j & 1][s[j] - '0'];
      if (cnt[j & 1][0] > 0 && cnt[j & 1][1] > 0 || cnt[(j & 1) ^ 1][s[j] - '0']) {
        --cnt[j & 1][s[j] - '0'];
        break;
      }
      ++j;
    }

    ans += j - i;
    // cerr << i << " " << j << endl;
    if (s[i] != '?') --cnt[i & 1][s[i] - '0'];
  }

  printf("%lld\n", ans);
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