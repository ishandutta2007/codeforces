#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    f[a[i]] = b[i];
  }
  vector<int> cyc(n + 1);
  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;;
    }
    int len = 0;
    int s = i;
    while (!vis[s]) {
      len += 1;
      vis[s] = 1;
      s = f[s];
    }
    cyc[len] += 1;
  }
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    dq.emplace_back(i);
  }
  lint ans = 0;
  for (int i = 1; i <= n; i++) {
    while (cyc[i] > 0) {
      cyc[i] -= 1;
      for (int j = 0; j < i / 2; j++) {
        ans += 2 * dq.back();
        dq.pop_back();
        ans -= 2 * dq.front();
        dq.pop_front();
      }
    }
  }
  cout << ans << '\n';
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