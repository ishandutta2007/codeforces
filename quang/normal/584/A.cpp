#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, t;

int main() {
  cin >> n >> t;
  if (n == 1 && t == 10) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 1) {
    cout << t << endl;
    return 0;
  }
  int add = 0;
  for (int i = 1; i < n; i++) {
    cout << 1;
    add = (add * 10 + 1) % t;
  }
  add *= 10;
  add %= t;
  cout << (t - add) % t;
}