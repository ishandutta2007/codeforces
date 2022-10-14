#include <bits/stdc++.h>
using namespace std;
using lint = long long;

pair<int, int> Query(int l, int r) {
  cout << "? " << l + 1 << " " << r + 1 << endl;
  int x, f;
  cin >> x >> f;
  return {x, f};
}

void Solve(int l, int r, vector<int> &ans) {
  if (l > r) return;
  int x, f;
  tie(x, f) = Query(l, r);
  int k = 0;
  while ((1 << (k + 1)) <= f) {
    k++;
  }
  vector<int> js;
  for (int i = l; i <= r; i++) {
    if (i % (1 << k) == 0 && ans[i] == -1) {
      ans[i] = Query(i, i).first;
    }
    if (ans[i] == x) {
      js.emplace_back(i);
    }
  }
  if (js.size() == 1) {
    int x1, f1, x2, f2;
    tie(x1, f1) = Query(max(0, js[0] - (1 << k) + 1), js[0]);
    tie(x2, f2) = Query(js[0], min(js[0] + (1 << k) - 1, r));
    if (x1 == x) {
      for (int i = js[0] - f1 + 1; i <= js[0] - f1 + f; i++) {
        ans[i] = x;
      }
      Solve(l, js[0] - f1, ans);
      Solve(js[0] - f1 + f + 1, r, ans);
    } else {
      for (int i = js[0] + f2 - f; i <= js[0] + f2 - 1; i++) {
        ans[i] = x;
      }
      Solve(l, js[0] + f2 - f - 1, ans);
      Solve(js[0] + f2, r, ans);
    }
  } else {
    assert(js.size() == 2);
    int x1, f1;
    tie(x1, f1) = Query(max(0, js[0] - (1 << k) + 1), js[1]);
    assert(x1 == x);
    for (int i = js[1] - f1 + 1; i <= js[1] - f1 + f; i++) {
      ans[i] = x;
    }
    Solve(l, js[1] - f1, ans);
    Solve(js[1] - f1 + f + 1, r, ans);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> ans(n, -1);
  Solve(0, n - 1, ans);
  cout << "!";
  for (auto i : ans) {
    cout << " " << i;
  }
  cout << endl;
  return 0;
}