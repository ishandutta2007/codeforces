#include "bits/stdc++.h"
using namespace std;

vector<int> divisors[200005];

int solve(vector<int> &colors) {
  int n = colors.size();
  for (auto &div : divisors[n]) {
    for (int start = 0; start < div; start++) {
      bool ok = true;
      for (int i = start; i < n; i += div) {
        if (colors[i] != colors[start]) {
          ok = false;
        }
      }
      if (ok) {
        return div;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> c(n);
  for (auto &i : p) {
    cin >> i;
    i--;
  }
  for (auto &i : c) {
    cin >> i;
    i--;
  }
  
  int ans = n + n;
  vector<int> vis(n, 0);

  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      int now = p[i];
      vector<int> colors;
      do {
        vis[now] = 1;
        colors.emplace_back(c[now]);
        now = p[now];
      } while (now != p[i]);
      ans = min(ans, solve(colors));
    }
  }

  cout << ans << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  for (int i = 1; i < 200005; i++) {
    for (int j = i; j < 200005; j += i) {
      divisors[j].emplace_back(i);
    }
  }

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}