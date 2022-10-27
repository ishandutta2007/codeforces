#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[100005];
char ans[100005];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = n, x = 0; i; i--) {
    if (a[i] <= x)
      ans[i] = '1';
    else if (x + 1 <= m)
      ans[i] = '1', x++;
    else
      ans[i] = '0';
  }

  for (int i = 1; i <= n; i++)
    putchar(ans[i]);
  putchar('\n');
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}