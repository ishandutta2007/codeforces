#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int bit = 30; bit >= 0; bit--) {
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
      if ((A[i] >> bit) & 1) one++;
      else zero++;
    }
    if (one % 2 == 0) {
      continue;
    }
    if (one % 4 == 1) {
      cout << "WIN\n";
      return;
    }
    if (zero % 2 == 0) {
      cout << "LOSE\n";
      return;
    } else {
      cout << "WIN\n";
      return;
    }
  }
  cout << "DRAW\n";
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