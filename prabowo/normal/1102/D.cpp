#include <bits/stdc++.h>
using namespace std;


const int N = 300005;

int n;
char s[N];

char ans[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  int cnt[3] = {0, 0, 0};
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - '0'];
  }

  for (int i = 0; i < 3; ++i) {
    int need = n/3 - cnt[i];
    int c = 0;
    for (int j = 0; j < n; ++j) {
      if (c == n/3) break;
      if (ans[j]) continue;
      if (s[j] == i + '0') {
        ans[j] = i + '0';
        ++c;
      } else if (need > 0 && cnt[s[j] - '0'] > n/3) {
        --cnt[s[j] - '0'];
        ans[j] = i + '0';
        ++c;
        --need;
      }
    }
  }

  printf("%s\n", ans);
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