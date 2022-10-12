#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, k;
char s[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  if (n % k != 0) return 0 * printf("-1\n");

  vector<int> cnt(26, 0);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }

  bool divs = true;
  for (int c : cnt) if (c % k != 0) divs = false;
  if (divs) return 0 * printf("%s\n", s);

  for (int i = n - 1; i >= 0; --i) {
    --cnt[s[i] - 'a'];
    
    vector<int> rem = cnt;
    for (int i = 0; i < 26; ++i) {
      rem[i] = -rem[i] % k;
      if (rem[i] < 0) rem[i] += k;
    }

    int sumr = 0;
    for (int r : rem) sumr += r;

    for (int c = s[i] + 1; c <= 'z'; ++c) {
      int tsumr = sumr;
      if (rem[c - 'a'] > 0) {
        --tsumr;
      } else {
        tsumr += k - 1;
      }

      if (tsumr > n - i - 1) continue;
      if (((n - i - 1) - tsumr) % k != 0) continue;

      s[i] = c;
      --rem[c - 'a'];
      if (rem[c - 'a'] < 0) rem[c - 'a'] += k;

      int cur = n - 1;
      for (int j = 25; j >= 0; --j) {
        while (rem[j] > 0) {
          --rem[j];
          s[cur--] = j + 'a';
        }
      }
      while (cur > i) s[cur--] = 'a';

      printf("%s\n", s);
      return 0;
    }
  }

  printf("-1\n");
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