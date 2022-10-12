#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k;
char s[N], t[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  scanf("%s", t);

  vector<int> cntS(26), cntT(26);
  for (int i = 0; i < n; ++i) {
    ++cntS[s[i] - 'a'];
    ++cntT[t[i] - 'a'];
  }

  for (int i = 0; i < 26; ++i) {
    if (cntS[i] < cntT[i]) return 0 * printf("No\n");

    if (cntS[i] % k != cntT[i] % k) return 0 * printf("No\n");

    int t = (cntS[i] - cntT[i]) / k;
    if (i < 25) cntS[i + 1] += k * t;
  }

  printf("Yes\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}