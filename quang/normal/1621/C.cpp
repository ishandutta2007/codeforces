#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> used(n);

  auto Ask = [&](int u) {
    cout << "? " << u + 1 << endl;
    int res;
    cin >> res;
    return res - 1;
  };

  vector<int> res(n);

  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    vector<int> ls;
    while (1) {
      auto u = Ask(i);
      ls.push_back(u);
      if (ls.size() > 1 && ls[0] == ls.back()) break;
    }
    for (int i = 0; i + 1 < ls.size(); i++) {
      res[ls[i]] = ls[i + 1];
      used[ls[i]] = true;
    }
  }  
  cout << "!";
  for (auto u : res) {
    cout << ' ' << u + 1;
  }
  cout << endl;
}

int32_t main() {
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}