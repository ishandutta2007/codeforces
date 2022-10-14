#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int rep = 0; rep < 2; rep++) {
    for (int i = 0; i + 1 < int(S.size()); i++) {
      if (S[i] == 'A' && S[i + 1] == 'B') {
        for (int j = i + 2; j + 1 < int(S.size()); j++) {
          if (S[j] == 'B' && S[j + 1] == 'A') {
            cout << "YES\n";
            return 0;
          }
        }
        break;
      }
    }
    for (auto &i : S) {
      if (i == 'A') {
        i = 'B';
      } else if (i == 'B') {
        i = 'A';
      }
    }
  }
  cout << "NO\n";
  return 0;
}