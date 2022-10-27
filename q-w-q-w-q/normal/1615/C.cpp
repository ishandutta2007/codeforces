#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100005;
int n;
char s1[N], s2[N];

int query(int n, int a, int b, int c, int d) {
  bool op = 0;
  int cnt = 0;
  while ((b || c) && cnt <= 2 * n) {
    cnt++;
    if (!op) {
      if (!c)
        return 1 << 30;
      swap(a, c), swap(b, d);
      a--, c++;
    } else {
      if (!d)
        return 1 << 30;
      swap(a, c), swap(b, d);
      b--, d++;
    }
    op ^= 1;
  }

  return b == 0 && c == 0 ? cnt : 1 << 30;
}

void solve() {
  cin >> n >> (s1 + 1) >> (s2 + 1);
  int a = 0, b = 0, c = 0, d = 0;

  for (int i = 1; i <= n; i++) {
    if (s1[i] == '0' && s2[i] == '0')
      a++;
    if (s1[i] == '0' && s2[i] == '1')
      b++;
    if (s1[i] == '1' && s2[i] == '0')
      c++;
    if (s1[i] == '1' && s2[i] == '1')
      d++;
  }

  int ans = query(n, a, b, c, d);
  if (d) {
    d--, b++;
    swap(b, d), swap(a, c);
    ans = min(ans, 1 + query(n, a, b, c, d));
  }

  if (ans <= 2 * n)
    cout << ans << '\n';
  else
    cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}