#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
char s[N];
int cnt[26];
bool used[26];

int solve() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < 26; ++i) {
    cnt[i] = 0;
    used[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  for (int i = 0; i < 26; ++i) if (cnt[i] == 0) used[i] = true;

  int lst = 0;
  for (int it = 0; it < 26; ++it) {
    for (int c = 'z'; c >= 'a'; --c) {
      int idx = -1;
      if (used[c - 'a']) continue;
      vector<int> tcnt(26, 0);
      for (int i = lst; i < n; ++i) {
        if (s[i] == c) {
          idx = i;
          break;
        }
        ++tcnt[s[i] - 'a'];
      }

      bool can = true;
      for (int i = 0; i < 26; ++i) {
        if (used[i]) continue;
        if (i + 'a' == c) continue;
        if (tcnt[i] == cnt[i]) {
          can = false;
          break;
        }
      }

      if (can) {
        printf("%c", c);
        used[c - 'a'] = true;
        for (int i = 0; i < 26; ++i) cnt[i] -= tcnt[i];
        lst = idx + 1;
        break;
      }
    }
  }

  vector<char> v;
  for (int i = 0; i < n; ++i) {
    while (v.size() > 0 && s[i] >= v.back() && cnt[v.back() - 'a'] > 0) {
      v.pop_back();
    }
    v.push_back(s[i]);
    --cnt[s[i] - 'a'];
  }

  for (char c : v) {
    if (!used[c - 'a']) {
      printf("%c", c);
      used[c - 'a'] = true;
    }
  }
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