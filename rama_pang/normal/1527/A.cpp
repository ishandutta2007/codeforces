#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  // n = 1101010101
  // k = 0111111111
  for (int i = 30; i >= 0; i--) {
    if ((n >> i) & 1) {
      cout << (1 << i) - 1 << '\n';
      break;
    }
  }
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