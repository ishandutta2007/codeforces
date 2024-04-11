#include <bits/stdc++.h>
using namespace std;
 
const int N = 2000005;

int n, k;
char s[N];
char ans[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  for (int len = 1; len <= k; ++len) {
    int mask = 0;
    for (int i = k - len; i < k - 1; ++i) mask = (mask << 1) | (s[i] - '0');

    int cnt0 = 0;
    for (int i = 0; i < k - len; ++i) if (s[i] == '0') ++cnt0;

    vector<bool> masks(1 << len, false);
    for (int i = k - 1; i < n; ++i) {
      mask <<= 1;
      mask &= ~(1 << len);
      mask |= s[i] - '0';

      if (cnt0 == 0) masks[mask] = true;
      cnt0 -= (s[i - k + 1] == '0');
      cnt0 += (s[i - len + 1] == '0');
    }

    mask = -1;
    for (int i = (1 << len) - 1; i >= 0; --i) {
      if (!masks[i]) {
        mask = i;
        break;
      }
    }

    if (mask == -1) continue;

    for (int i = 0; i < k - len; ++i) ans[i] = '0';
    for (int i = len - 1; i >= 0; --i) {
      if (mask >> i & 1) {
        ans[k - i - 1] = '0';
      } else {
        ans[k - i - 1] = '1';
      }
    }
    ans[k] = 0;
    return 0 * printf("YES\n%s\n", ans);
  }

  return 0 * printf("NO\n");
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