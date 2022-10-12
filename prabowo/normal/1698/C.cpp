#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  vector<int> pos, neg;
  int zeroes = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > 0) pos.push_back(a[i]);
    if (a[i] < 0) neg.push_back(a[i]);
    if (a[i] == 0) ++zeroes;
  }

  if (pos.size() >= 3 || neg.size() >= 3) return 0 * printf("NO\n");

  while (neg.size()) {
    pos.push_back(neg.back());
    neg.pop_back();
  }

  zeroes = min(zeroes, 3);
  while (zeroes > 0) {
    pos.push_back(0);
    --zeroes;
  }

  set<int> s(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); ++i) {
    for (int j = i + 1; j < pos.size(); ++j) {
      for (int k = j + 1; k < pos.size(); ++k) {
        if (s.find(pos[i] + pos[j] + pos[k]) == s.end()) {
          return 0 * printf("NO\n");
        }
      }
    }
  }

  printf("YES\n");
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