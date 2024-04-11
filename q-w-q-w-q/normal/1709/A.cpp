#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, a[4] = {0};
    cin >> x >> a[1] >> a[2] >> a[3];
    bool ok = 0;
    for (int i = 1; i <= 3; i++)
      if (a[a[i]] == i)
        ok = 1;
    if (ok)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}