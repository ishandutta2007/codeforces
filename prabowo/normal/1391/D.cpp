#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m;
int s[N][3];

char t[N];

int solve() {
  scanf("%d %d", &n, &m);
  if (n >= 4) return 0 * printf("-1\n");
  if (n == 1) return 0 * printf("0\n");

  for (int i = 0; i < n; ++i) {
    scanf("%s", t);
    for (int j = 0; j < m; ++j) s[j][i] = t[j] - '0';
  }

  if (n == 2) {
    int cnt[2] = {m, m};
    for (int i = 0; i < m; ++i) {
      --cnt[s[i][0] ^ s[i][1] ^ i & 1];
    }
    printf("%d\n", min(cnt[0], cnt[1]));
  } else if (n == 3) {
    int cnt[2][2] = {{m, m}, {m, m}};
    for (int i = 0; i < m; ++i) {
      --cnt[s[i][0] ^ s[i][1] ^ i & 1][s[i][1] ^ s[i][2] ^ i & 1];
    }
    printf("%d\n", min(min(cnt[0][0], cnt[0][1]), min(cnt[1][0], cnt[1][1])));
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}