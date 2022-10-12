#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);

  int cnt[3] = {0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') ++cnt[0];
    if (s[i] == 'P') ++cnt[1];
    if (s[i] == 'S') ++cnt[2];
  }

  char win;
  if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2]) {
    win = 'P';
  } else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2]) {
    win = 'S';
  } else {
    win = 'R';
  }

  for (int i = 0; i < n; ++i) printf("%c", win);
  printf("\n");
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