#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> q(n);
  iota(begin(p), end(p), 0);
  iota(begin(q), end(q), 0);
  shuffle(begin(p), end(p), rnd);

  int sh = 0;
  const auto Query = [&](int x) {
    cout << "? " << x + 1 << endl;
    int f = q[x] + 1;
    cin >> f;
    // {
    //   vector<int> r(n);
    //   for (int i = 0; i < n; i++) {
    //     r[i] = q[p[i]];
    //   }
    //   q = r;
    // }
    sh += 1;
    return f - 1;
  };
  vector<int> vis(n);
  vector<deque<int>> cyc;
  for (int i = 0; i < n; i++) {
    int s = Query(i);    
    if (vis[s]) continue;
    cyc.emplace_back();
    while (!vis[s]) {
      cyc.back().emplace_back(s);
      vis[s] = 1;
      s = Query(i);
    }
  }  

  assert(sh == n + n);

  cout << "! ";
  vector<int> ans(n, -1);
  for (auto x : cyc) {
    for (int i = 0; i < int(x.size()); i++) {
      ans[x[(i + x.size() - 1) % x.size()]] = x[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
  cout << flush;
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