#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint N, C;
  cin >> N >> C;
  lint ans = 1e9;

  vector<lint> A(N), B(N);
  for (lint i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (lint i = 0; i < N - 1; i++) {
    cin >> B[i];
  }

  lint cur = 0;
  lint days = 0;
  for (lint i = 0; i < N; i++) {
    ans = min(ans, days + (C - cur + A[i] - 1) / A[i]);
    if (cur < B[i]) {
      lint need = B[i] - cur;
      lint wait = (need + A[i] - 1) / A[i];
      days += wait;
      cur += wait * A[i];
      cur -= B[i];
      days += 1;
    } else {
      cur -= B[i];
      days += 1;
    }
  }

  cout << ans << '\n';
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