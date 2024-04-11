#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  for (int i = 0; i < N; i++) {

  }
  while (M--) {
    bool change = false;
    string T(N, '0');
    for (int i = 0; i < N; i++) {
      if (S[i] == '1') {
        T[i] = '1';
      } else {
        int lft = (i > 0 && S[i - 1] == '1');
        int rgt = (i + 1 < N && S[i + 1] == '1');
        if (lft + rgt == 1) {
          T[i] = '1';
        }
      }
    }
    if (S == T) {
      break;
    }
    S = T;
  }

  cout << S << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}