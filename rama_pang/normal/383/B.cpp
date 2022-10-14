#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  
  vector<int> xcoord = {1, N};
  vector<int> X(M), Y(M);
  for (int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    xcoord.emplace_back(X[i]);
    xcoord.emplace_back(max(1, X[i] - 1));
    xcoord.emplace_back(min(N, X[i] + 1));
  }

  sort(begin(xcoord), end(xcoord));
  xcoord.resize(unique(begin(xcoord), end(xcoord)) - begin(xcoord));

  vector<vector<int>> pts(xcoord.size());
  for (int i = 0; i < M; i++) {
    int x = lower_bound(begin(xcoord), end(xcoord), X[i]) - begin(xcoord);
    pts[x].emplace_back(Y[i]);
  }

  vector<pair<int, int>> good;
  good.emplace_back(1, 1);
  for (int xid = 0; xid < xcoord.size(); xid++) {
    pts[xid].emplace_back(0);
    pts[xid].emplace_back(N + 1);
    sort(begin(pts[xid]), end(pts[xid]));
    pts[xid].resize(unique(begin(pts[xid]), end(pts[xid])) - begin(pts[xid]));

    sort(begin(good), end(good));
    vector<pair<int, int>> intervals;
    for (int i = 0; i + 1 < int(pts[xid].size()); i++) {
      int L = pts[xid][i] + 1;
      int R = pts[xid][i + 1] - 1;
      if (L <= R) {
        // Check if there is good interval which intersects with [L, R]
        // minimum y coord that can reach [L, R] = lowerbound on L
        int minY = N + 1;
        auto it = lower_bound(begin(good), end(good), pair(L, -1));
        if (it != end(good)) {
          minY = min(minY, it->first);
        }
        if (it != begin(good) && L <= prev(it)->second) {
          assert(prev(it)->first <= L);
          minY = L;
        }
        if (minY <= R) {
          intervals.emplace_back(minY, R);
        }
      }
    }
    good = intervals;
  }

  int can = 0;
  for (auto [l, r] : good) {
    if (r == N) {
      can = 1;
    }
  }

  if (!can) {
    cout << -1 << '\n';
  } else {
    cout << 2 * (N - 1) << '\n';
  }
  return 0;
}