#include <bits/stdc++.h>

using namespace std;
const int INF = 1e5;

array<bool, INF> is_comp;

void Solve(int test) {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
    sum += u;
  }
  if (is_comp[sum]) {
    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << i + 1 << ' ';
    cout << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      if (is_comp[sum - a[i]]) {
        cout << n - 1 << '\n';
        for (int j = 0; j < n; j++) {
          if (j != i) cout << j + 1 << ' ';
        }
        cout << '\n';
        return;
      }
    }
    exit(1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  for (int i = 2; i < INF; i++) {
    if (is_comp[i]) continue;
    for (int j = i + i; j < INF; j += i) {
      is_comp[j] = 1;
    }
  }

  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}