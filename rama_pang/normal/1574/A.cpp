#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int rep = 1; rep <= N; rep++) {
      for (int i = 1; i <= N + N; i++) {
        if (i <= rep) {
          cout << "(";
        } else if (i <= rep + rep) {
          cout << ")";
        } else {
          if (i & 1) {
            cout << "(";
          } else {
            cout << ")";
          }
        }
      }
      cout << '\n';
    }
  }
  return 0;
}