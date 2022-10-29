#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N], ans;
set<int> S, T;
int solve(int l, int r, int pos) {
  sort(a + l, a + r);
  sort(b + l, b + r);
  reverse(b + l, b + r);
  int res = 1 << pos - 1;
  rep(i, l, r) {
    res &= a[i] ^ b[i];
  }
  if (res) {
    int mid = l - 1;
    rep(i, l, r) {
      if (a[i] & (1 << pos - 1))
        mid = i;
    }
    ++mid;
    T.insert(mid);
  }
  return res;
}
int main() {
  int TT;
  scanf("%d", &TT);
  while (TT--) {
    ans = (1 << 30) - 1;
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &a[i]);
    rep(i, 0, n) scanf("%d", &b[i]);
    S.clear();
    S.insert(n);
    for (int i = 30; i > 0; --i) {
      int last = 0;
      int res = 1 << i - 1;
      T.clear();
      for (auto cur : S) {
        res &= solve(last, cur, i);
        last = cur;
      }
      if (!res) {
        int val = (1 << 30) - 1;
        val ^= 1 << i - 1;
        ans &= val;
        rep(i, 0, n) {
          a[i] &= val;
          b[i] &= val;
        }
      } else {
        for (auto x : T)
          S.insert(x);
      }
    }
    printf("%d\n", ans);
  }
}