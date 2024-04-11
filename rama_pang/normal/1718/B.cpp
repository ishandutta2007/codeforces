#include <bits/stdc++.h>
using namespace std;

using lint = long long;

const lint MOD = 1e9 + 7;
const lint INF = 1e18;

void Main() {
  const lint MAX = 1e11;
  vector<lint> fib = {1, 1};
  while (fib.back() < MAX) {
    fib.emplace_back(end(fib)[-2] + end(fib)[-1]);
  }
  reverse(begin(fib), end(fib));
  fib.pop_back();

  int k;
  cin >> k;
  vector<lint> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  const auto Solve = [&]() {
    vector<int> mark(fib.size(), -1);
    for (int _ = 0; _ < k; _++) {
      lint x = a[_];
      for (int i = 0; i < int(fib.size()); i++) {
        if (fib[i] <= x) {
          x -= fib[i];
          if (mark[i] != -1) return -1;
          mark[i] = _;
        }
      }
    }
    reverse(begin(mark), end(mark));
    while (!mark.empty() && mark.back() == -1) mark.pop_back();
    for (int i = int(mark.size()) - 1; i >= 0; i--) {
      if (mark[i] == -1) {
        return -1;
      }
    }
    if (mark.empty()) {
      return -2;
    }
    return mark[0];
  };

  for (int i = 0; i < k; i++) {
    a[i]--;
    int j = Solve();
    if (i != j && j != -1) {
      cout << "YES\n";
      return;
    }
    a[i]++;
  }
  cout << "NO\n";
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