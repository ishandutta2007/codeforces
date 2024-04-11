#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) { return d[i] > d[j]; });
  vector<int> used(n);
  vector<int> par(n, -1);
  function<int(int)> Find = [&](int x) {
    return par[x] < 0 ? x : par[x] = Find(par[x]);
  };
  for (auto i : ord) {
    if (used[i]) continue;
    used[i] = 1;
    for (int x = 0; x < d[i]; x++) {
      cout << "? " << i + 1 << endl;
      int f;
      cin >> f;
      f--;
      assert(Find(i) != Find(f));
      par[Find(i)] = Find(f);
      if (used[f]) {
        break;
      } else {
        used[f] = 1;
      }
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << Find(i) + 1 << " \n"[i + 1 == n];
  }
  cout << flush;
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