#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200005;
int n;
char a[N], b[N];

bool check(int n) {
  for (int i = 1, s = 0; i <= n; i++) {
    if (b[i] == '(')
      s++;
    else
      s--;
    if (s < 0)
      return 0;
  }
  return 1;
}

void solve() {
  cin >> (a + 1), n = strlen(a + 1);
  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }

  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == '(')
      s1++;
    else if (a[i] == ')')
      s2++;
  if (s1 > n / 2 || s2 > n / 2) {
    cout << "NO\n";
    return;
  }

  int res = n / 2 - s1;
  int p1 = 0, p2 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != '?')
      b[i] = a[i];
    else if (res)
      res--, b[i] = '(', p1 = i;
    else
      b[i] = ')', p2 = p2 ? p2 : i;

  if (!check(n)) {
    cout << "NO\n";
    return;
  }
  if (p1 && p2) {
    swap(b[p1], b[p2]);
    if (check(n)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}