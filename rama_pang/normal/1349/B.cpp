#include <bits/stdc++.h>
using namespace std;
using lint = long long;


bool Solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int can = 0;
  vector<int> same;
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n; i++) {
    if (a[i] >= k) same.emplace_back(i);
    if (a[i] == k) can = 1;
  }

  if (!can) return 0;
  
  queue<int> q;
  vector<int> vis(n, 0);
  for (auto i : same) {
    vis[i] = 1;
    q.emplace(i);
  }

  vector<int> see;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int len = 2; len <= 6; len++) {
      for (int l = u - len + 1; l <= u; l++) {
        int r = l + len - 1;
        if (l < 0 || r >= n) continue;

        see.clear();
        for (int j = l; j <= r; j++) {
          if (vis[j]) {
            see.emplace_back(k);
          } else {
            see.emplace_back(a[j]);
          }
        }
        sort(begin(see), end(see));
        int pos = (len + 1) / 2; pos--;
        if (see[pos] >= k) {
          for (int j = l; j <= r; j++) {
            if (!vis[j]) {
              vis[j] = 1;
              q.emplace(j);
            }
          }
        }
      }
    }    
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    if (Solve()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }  

}