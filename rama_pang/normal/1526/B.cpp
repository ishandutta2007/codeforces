#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  const int MAX = 1e5;
  vector<int> can(MAX);

  for (int i = 11; i < MAX; i++) {
    for (int b = 0; 111 * b <= i; b++) {
      int rest = i - 111 * b;
      if (rest % 11 != 0) continue;
      int a = rest / 11;
      can[i] = 1;
      break;
    }
  }

  while (T--) {
    int N;
    cin >> N;
    cout << (N >= MAX || can[N] ? "YES" : "NO") << '\n';
  }
  return 0;
}