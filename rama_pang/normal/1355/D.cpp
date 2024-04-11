#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, S;
  cin >> N >> S;
  if (S < 2 * N) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << S - (N - 1);
    for (int i = 1; i < N; i++) {
      cout << " 1";
    }
    cout << "\n";
    cout << (S - (N - 1)  - 1) << "\n";
  }

  return 0;
}