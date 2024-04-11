#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

const int N = 100005;
int n, a, b, c;
int st[N];
char s[N];

void solve() {
  cin >> n >> a >> b >> c;
  cin >> (s + 1);

  i64 ans = 0;
  int s0 = 0, s1 = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] == '0' && s[i - 1] == '0')
      s0++;
    if (s[i] == '1' && s[i - 1] == '1')
      s1++;
  }
  if (s0 == s1) {
    ans = 1ll * s0 * (a + b);
    if (b > c) {
      int t = 1;
      for (int i = 2; i <= n; i++)
        if (s[i] != s[i - 1])
          t++;
      if (t > 2) {
        if (s[1] == '0')
          t--;
        if (s[n] == '0')
          t--;
        ans += 1ll * t / 2 * (b - c);
      }
    }
  } else if (s1 > s0) {
    ans = 1ll * s0 * a + 1ll * (s0 + 1) * b;
    s1 -= s0 + 1;
    if (b > c) {
      int t = 1;
      for (int i = 2; i <= n; i++)
        if (s[i] != s[i - 1])
          t++;
      if (t > 2) {
        if (s[1] == '0')
          t--;
        if (s[n] == '0')
          t--;
        ans += 1ll * t / 2 * (b - c);
        if (s[1] == '0' && s1)
          ans += b - c, s1--;
        if (s[n] == '0' && s1)
          ans += b - c, s1--;
      } else if (t == 2 && s1)
        ans += b - c;
    }
  } else {
    if (b <= c)
      ans = 1ll * s1 * b + 1ll * (s1 + 1) * a;
    else {
      ans = 1ll * s1 * (a + b);
      bool b1 = 0;
      for (int i = 1; i <= n; i++)
        if (s[i] == '1')
          b1 = 1;
      if (b1) {
        int res = 0;
        if (s[1] == '0')
          for (int i = 2; s[i] != '1'; i++)
            res++;
        if (s[n] == '0')
          for (int i = n - 1; s[i] != '1'; i--)
            res++;
        if (s0 <= res + s1) {
          int t = 0;
          for (int i = 2; i <= n; i++)
            if (s[i] != s[i - 1])
              t++;
          if (t > 2) {
            if (s[1] == '0')
              t--;
            if (s[n] == '0')
              t--;
            ans += 1ll * t / 2 * (b - c);
          }
          ans += a;
        } else {
          int top = 0;
          int l = 0, r = 0;
          for (int i = 1;; i++)
            if (s[i] == '1') {
              l = i;
              break;
            }
          for (int i = n; i; i--)
            if (s[i] == '1') {
              r = i;
              break;
            }
          for (int i = l, j; i <= r; i = j) {
            if (s[i] == '1') {
              j = i + 1;
              continue;
            }
            for (j = i; s[j] == '0'; j++)
              ;
            st[++top] = j - i - 1;
          }
          sort(st + 1, st + top + 1);
          int tot = 0;
          for (int i = 1; i <= n; i++)
            if (s1 < st[i])
              break;
            else
              s1 -= st[i], tot++;
          ans += 1ll * tot * (b - c) + a;
        }
      } else
        ans += a;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}