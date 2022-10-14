#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<array<int, 3>> inc, dec;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      dec.push_back({b, a, i});
    } else {
      inc.push_back({a, b, i});
    }
  }
  reverse(begin(dec), end(dec));

  auto SolveIncreasing = [&](vector<array<int, 3>> a) { // increasing
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    vector<int> res;
    for (int i = 0; i < (int) a.size(); i++) {
      res.emplace_back(a[i][2]);
    }
    return res;
  };

  auto SolveDecreasing = [&](vector<array<int, 3>> a) { // decreasing
    sort(begin(a), end(a));
    vector<int> res;
    for (int i = 0; i < (int) a.size(); i++) {
      res.emplace_back(a[i][2]);
    }
    return res;
  };
  

  vector<int> r1 = SolveIncreasing(inc);
  vector<int> r2 = SolveDecreasing(dec);

  if (r1.size() < r2.size()) {
    swap(r1, r2);
  }

  cout << r1.size() << "\n";
  for (auto i : r1) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}