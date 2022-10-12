#include <bits/stdc++.h>
using namespace std;

const int N = 505;

char s[N];
char ans[N];

bool used[30];

int solve() {
  scanf("%s", s);

  for (int i = 0; i < 26; ++i) used[i] = false;

  int n = strlen(s);

  int l = N/2, r = N/2;
  ans[l] = s[0];
  int cur = l;
  used[s[0] - 'a'] = true;

  for (int i = 1; i < n; ++i) {
    if (cur-1 >= l && ans[cur-1] == s[i]) {
      --cur;
    } else if (cur+1 <= r && ans[cur+1] == s[i]) {
      ++cur;
    } else if (cur+1 > r) {
      ++r; ++cur;
      ans[cur] = s[i];

      if (used[s[i] - 'a']) return 0 * printf("NO\n");
      used[s[i] - 'a'] = true;
    } else if (cur-1 < l) {
      --l; --cur;
      ans[cur] = s[i];

      if (used[s[i] - 'a']) return 0 * printf("NO\n");
      used[s[i] - 'a'] = true;
    } else {
      printf("NO\n");
      return 0;
    }
  }

  for (int i = 0; i < 26; ++i) if (!used[i]) {
    ans[++r] = ('a' + i);
  }

  printf("YES\n");
  for (int i = l; i <= r; ++i) printf("%c", ans[i]);
  printf("\n");
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