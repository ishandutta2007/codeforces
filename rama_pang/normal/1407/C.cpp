#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  auto Query = [&](int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << endl;
    int a;
    cin >> a;
    return a;
  };
  vector<int> ans(n, -1);
  vector<int> cand(n);
  iota(begin(cand), end(cand), 0);
  while (cand.size() > 1) {
    int u = cand.back();
    cand.pop_back();
    int v = cand.back();
    cand.pop_back();
    int uv = Query(u, v);
    int vu = Query(v, u);
    if (uv > vu) {
      ans[u] = max(uv, vu);
      cand.emplace_back(v);
    } else {
      ans[v] = max(uv, vu);
      cand.emplace_back(u);
    }
  }
  vector<int> in(n + 1);
  for (auto i : ans) {
    if (i != -1) {
      in[i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      for (int j = 1; j <= n; j++) {
        if (in[j] == 0) {
          ans[i] = j;
          break;
        }
      }
    }
  }
  cout << "! ";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}