#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  int N;
  cin >> N;
  int R = -1, K = -1;
  for (int i = 1; i <= N; i++) {
    int mx = N - i - ((N + i - 1) / i) + 1;
    if (mx > R) {
      R = mx;
      K = i;
    }
  }

  int cur = 0;
  vector<int> state(N);
  vector<int> target(N, 1);
  for (int i = 0; i < N; i += K) {
    target[i] = 0;
  }
  auto Query = [&]() {
    int cnt = K;
    cout << K;
    for (int i = 0; i < N; i++) if (cnt > 0) {
      if (target[i] == 1 && state[i] == 0) {
        cout << " " << i + 1;
        cnt--;
        state[i] = 1;
      }
    }
    if (cnt > 0) {
      for (int i = 0; i < N; i++) if (cnt > 0) {
        if (target[i] == 0) {
          cout << " " <<  i + 1;
          cnt--;
          state[i] = 1;
        }
      }
    }
    cout << endl;
    int x;
    cin >> x;
    x--;
    int t = K;
    while (t--) {
      state[x] = 0;
      x++;
      x %= N;
    }

    cur = 0;
    for (int i = 0; i < N; i++) {
      if (state[i]) {
        cur++;
      }
    }
  };
  while (cur < R) {
    Query();
  }
  cout << 0 << endl;
  return 0;
}