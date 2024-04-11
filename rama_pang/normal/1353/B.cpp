#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    priority_queue<int, vector<int>, greater<int>> in;
    priority_queue<int> out;
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (int i = 0; i < n; i++) {
      in.emplace(a[i]);
      out.emplace(b[i]);
    }

    while (k > 0) {
      k--;
      int u = in.top();
      int v = out.top();
      in.pop();
      out.pop();
      if (u < v) {
        in.emplace(v);
        out.emplace(u);
      } else {
        in.emplace(u);
        out.emplace(v);
        break;
      }
    }
    int sum = 0;
    while (!in.empty()) {
      sum += in.top();
      in.pop();
    }
    cout << sum << "\n";
  }
}