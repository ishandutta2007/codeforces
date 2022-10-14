#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int L, R;
  cin >> L >> R;
  for (int i = L; i <= R; i++) {
    int tmp = i;
    int done[10] = {};
    while (tmp > 0) {
      done[tmp % 10]++;
      tmp /= 10;
    }
    int can = 1;
    for (int j = 0; j < 10; j++) {
      if (done[j] > 1) {
        can = 0;
        break;
      } 
    }
    if (can) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}