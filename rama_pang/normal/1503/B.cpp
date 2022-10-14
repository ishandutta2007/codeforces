#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<pair<int, int>> odd, even;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if ((i + j) % 2 == 0) {
        even.emplace_back(i, j);
      } else {
        odd.emplace_back(i, j);
      }
    }
  }
  for (int rep = 0; rep < N * N; rep++) {
    int a;
    cin >> a;
    const auto Put = [&](int b, int i, int j) {
      assert(a != b);
      cout << b << ' ' << i << ' ' << j << endl;
    };
    if (a == 1) {
      if (!even.empty()) {
        Put(2, even.back().first, even.back().second);
        even.pop_back();
      } else {
        Put(3, odd.back().first, odd.back().second);
        odd.pop_back();
      }
    } else if (a == 2) {
      if (!odd.empty()) {
        Put(1, odd.back().first, odd.back().second);
        odd.pop_back();
      } else {
        Put(3, even.back().first, even.back().second);
        even.pop_back();
      }
    } else if (a == 3) {
      if (!even.empty()) {
        Put(2, even.back().first, even.back().second);
        even.pop_back();
      } else {
        Put(1, odd.back().first, odd.back().second);
        odd.pop_back();
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}