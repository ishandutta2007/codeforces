#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
char s[N];
int m;
int b[N];

char ans[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }

  int cnt[26];
  for (int i = 0; i < 26; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }

  for (int i = 0; i <= m; ++i) ans[i] = 0;

  int c = 25;
  while (strlen(ans) != m) {
    vector<int> pos;
    for (int j = 0; j < m; ++j) {
      if (ans[j] == 0) {
        int sum = 0;
        for (int k = 0; k < m; ++k) {
          if (ans[k] != 0) {
            sum += abs(j - k);
          }
        }

        if (sum == b[j]) pos.push_back(j);
      }
    }

    while (cnt[c] < pos.size()) --c;

    for (int p: pos) ans[p] = c + 'a';
    --c;
  }

  printf("%s\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}