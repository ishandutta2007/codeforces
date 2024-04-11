#include <cstdio>
#include <iostream>

using namespace std;

const int N = 300005;
int a[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++) {
    bool ok = 0;
    for (int j = 2; j <= i + 1; j++)
      if (a[i] % j) {
        ok = 1;
        break;
      }
    if (!ok) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}