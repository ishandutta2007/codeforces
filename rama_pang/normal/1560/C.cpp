#include <bits/stdc++.h>
using namespace std;

void Main() {
  int k;
  cin >> k;
  int cur = 1;
  int layer = 1;
  while (k > layer) {
    k -= layer;
    layer += 2;
    cur += 1;
  }
  k--;
  if (k * 2 + 1 == layer) {
    cout << cur << ' ' << cur << '\n';
    return;
  }
  if (k * 2 <= layer) {
    cout << k + 1 << ' ' << cur << '\n';
    return;
  }
  k -= layer / 2;
  cout << cur << ' ' << (layer / 2 - k + 1) << '\n';
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