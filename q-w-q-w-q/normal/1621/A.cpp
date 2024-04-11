#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j && i % 2 == 1 && k)
          cout << 'R', k--;
        else
          cout << '.';
      }
      cout << '\n';
    }
  }
}