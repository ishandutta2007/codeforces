#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<lint> a(n + 1), b(n + 1), deg(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = max(b[i], 0ll);
    deg[b[i]]++;
  }
  
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.emplace(i);
    }
  }
  lint ans = 0;
  vector<int> pos, neg;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == 0) {
      break;
    }
    ans += a[u];
    deg[b[u]]--;
    if (a[u] <= 0) {
      neg.emplace_back(u);
    } else {
      pos.emplace_back(u);
      a[b[u]] += a[u];
    }
    if (deg[b[u]] == 0) {
      q.emplace(b[u]);
    }
  }

  cout << ans << "\n";
  reverse(begin(neg), end(neg));
  for (auto i : pos) {
    cout << i << " ";
  }
  for (auto i : neg) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}