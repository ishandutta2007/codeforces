#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, k;
char s[N];

int gcd(int x, int y) {
  while (y) {
    int t = x;
    x = y;
    y = t % y;
  }
  return x;
}

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  vector<int> cnt(26, 0);
  for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];

  for (int i = n; i > 0; --i) {
    int use = i / gcd(i, k);
    int need = i / use;

    int sum = 0;
    for (int k = 0; k < 26; ++k) {
      sum += cnt[k] / use;
    }

    // cerr << use << " " << need << " " << sum << endl;

    if (sum >= need) return 0 * printf("%d\n", i);
  }

  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}