#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

lint ReadInt() {
  char c = getchar();
  while (!('0' <= c && c <= '9')) c = getchar();
  lint x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x;
}

void Main() {
  // 
  // 2 3 4 5 6 7
  // A[x] must be erasable by one of 2, 3,3 4, .., x+1
  // 
  int can = 1;
  lint N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    lint x;
    cin >> x;
    int ok = 0;
    for (lint g = 2; g <= i + 2; g++) {
      if (x % g == 0) continue;
      ok = 1;
      break;
    }
    if (!ok) can = 0;
  }
  if (can) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}