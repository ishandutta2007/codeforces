#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long N;
  cin >> N;

  long long cur = 0, L = 0, R = 0;
  auto Query = [&](long long x) {
    cur += x;
    cout << "? " << cur << endl;
    int y;
    cin >> y;
    return y;
  };

  long long lo = 1, hi = N, dir = 0;
  while (lo < hi) {
    long long md = (lo + hi) / 2;
    if ((hi - lo + 1) & 1) md--;
    if (dir == 0) {
      cur += md;
    } else {
      cur -= md;
    }
    lo = md + 1;
    L = min(L, cur);
    R = max(R, cur);
    dir ^= 1;
  }
  
  cur = 0;
  Query(-L + 1);
  lo = 1, hi = N, dir = 0;
  while (lo < hi) {
    long long md = (lo + hi) / 2;
    if ((hi - lo + 1) & 1) md--;
    if (Query((dir == 0 ? md : -md))) {
      hi = md;
    } else {
      lo = md + 1;
    }
    dir ^= 1;
  }
  cout << "= " << lo << endl;
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}