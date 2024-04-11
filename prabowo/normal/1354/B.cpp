#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  int ans = -1;
  int cnt[3] = {0, 0, 0};
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)) {
      ++cnt[s[j++] - '1'];
    }

    if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
      if (ans == -1 || ans > j - i) {
        ans = j - i;
      }
    }

    --cnt[s[i] - '1'];
  }

  if (ans == -1) printf("0\n");
  else printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();  
  return 0;
}