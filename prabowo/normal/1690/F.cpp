#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N];
int p[N];

int minrot(const string &s) {
  for (int d = 1; d <= s.size(); ++d) {
    if (s.size() % d != 0) continue;
    bool okay = true;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != s[(i + d) % s.size()]) {
        okay = false;
        break;
      }
    }
    if (okay) return d;
  }
  return s.size();
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }

  long long ans = 1;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    string ss;
    for (int j = i; !vis[j]; j = p[j]) {
      vis[j] = true;
      ss += s[j];
    }
    ans = lcm(ans, 1LL * minrot(ss));
    // cerr << ss << " " << minrot << endl;
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}