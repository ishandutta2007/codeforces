#include <bits/stdc++.h>
using namespace std;

void Main() {
  int x, y;
  cin >> x >> y;
  int d = x + y;
  if (d & 1) {
    cout << "-1 -1\n";
  } else {
    cout << x / 2 << ' ' << (y + 1) / 2 << '\n';
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
}