#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  sort(begin(a), end(a));
  a.resize(unique(begin(a), end(a)) - begin(a));
  // cnt[x] * x + cnt[y] * y + cnt[x] * y + cnt[y] * x
  // If we fix x, then we must get (constant + cnt[x] * y + x * cnt[y]) that is the best
  // Maximize cnt[x] * y + x * cnt[y]
  // Wait
  // Only SQRT values of cnt[.]
  // So we can iterate over cnt[x] = a, cnt[y] = b
  // Then we have to find a non-bad pair
  // O(N sqrt N) I think
  map<int, vector<int>> adj;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector<int> poscnt;
  for (auto [v, occ] : cnt) {
    poscnt.emplace_back(occ);
  }
  sort(begin(poscnt), end(poscnt));
  poscnt.resize(unique(begin(poscnt), end(poscnt)) - begin(poscnt));
  vector<vector<int>> ls(poscnt.size());
  for (auto [v, occ] : cnt) {
    int id = lower_bound(begin(poscnt), end(poscnt), occ) - begin(poscnt);
    int id2 = lower_bound(begin(a), end(a), v) - begin(a);
    ls[id].emplace_back(id2);    
  }

  for (int i = 0; i < int(ls.size()); i++) {
    sort(begin(ls[i]), end(ls[i]));
    reverse(begin(ls[i]), end(ls[i]));
  }

  lint ans = -1e18;
  vector<int> deleted(a.size());
  for (int aid = 0; aid < int(ls.size()); aid++) {
    // preprocess
    int cntx = poscnt[aid];
    for (auto xid : ls[aid]) {
      int x = a[xid];
      for (auto y : adj[x]) {
        // mark y as deleted
        int id2 = lower_bound(begin(a), end(a), y) - begin(a);
        deleted[id2] = 1;
      }
      for (int bid = 0; bid < int(ls.size()); bid++) {
        int cnty = poscnt[bid];
        for (auto yid : ls[bid]) {
          if (deleted[yid]) continue;
          if (x == a[yid]) continue;
          ans = max(ans, 1ll * (x + a[yid]) * (cntx + cnty));
          break;
        }
      }
      for (auto y : adj[x]) {
        int id2 = lower_bound(begin(a), end(a), y) - begin(a);
        deleted[id2] = 0;
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