#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  const auto Check = [&](int t) -> bool {
    vector<int> p(N);
    iota(begin(p), end(p), 0);
    function<int(int)> Find = [&](int x) {
      return p[x] == x ? x : p[x] = Find(p[x]);
    };

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if ((A[i].first == A[j].first || A[i].second == A[j].second) && 
            abs(A[i].first - A[j].first) + abs(A[i].second - A[j].second) <= t) {
          p[Find(i)] = Find(j);
        }
      }
    }

    int cc = 0;
    for (int i = 0; i < N; i++) {
      if (Find(i) == i) {
        cc++;
      }
    }

    vector<vector<int>> part(N);
    for (int i = 0; i < N; i++) {
      part[Find(i)].emplace_back(i);
    }

    if (cc == 1) {
      return true;
    } else if (cc == 2) {
      for (int i = 0; i < N; i++) if (Find(i) == i) {
        for (int j = i + 1; j < N; j++) if (Find(j) == j) {
          for (auto a : part[i]) {
            for (auto b : part[j]) {
              if (abs(A[a].first - A[b].first) <= t && abs(A[a].second - A[b].second) <= t) {
                return true;
              }
              if (abs(A[a].first - A[b].first) == 0 && abs(A[a].second - A[b].second) <= 2 * t) {
                return true;
              }
            }
          }
          return false;
        }
      }
      return false;
    } else if (cc == 3) {
      vector<int> coords;
      for (int i = 0; i < N; i++) {
        coords.emplace_back(A[i].first);
      }
      sort(begin(coords), end(coords));
      coords.resize(unique(begin(coords), end(coords)) - begin(coords));
      vector<vector<pair<int, int>>> ls(coords.size());
      for (int i = 0; i < N; i++) {
        int pos = lower_bound(begin(coords), end(coords), A[i].first) - begin(coords);
        ls[pos].emplace_back(A[i].second, Find(i));
      }
      for (int i = 0; i < (int) ls.size(); i++) {
        sort(begin(ls[i]), end(ls[i]));
        for (int j = 0; j + 1 < (int) ls[i].size(); j++) {
          if (ls[i][j].second != ls[i][j + 1].second) {
            for (int k = 0; k < N; k++) {
              if (Find(k) == k && Find(k) != ls[i][j].second && Find(k) != ls[i][j + 1].second) {
                for (auto v : part[k]) {
                  if (abs(A[v].first - coords[i]) <= t && 
                      abs(A[v].second - ls[i][j].first) <= t && 
                      abs(A[v].second - ls[i][j + 1].first) <= t) {
                    return true;
                  }
                }
              }
            }
          }
        }
      }
      return false;
    } else if (cc == 4) {
      vector<int> coordX, coordY;
      for (int i = 0; i < N; i++) {
        coordX.emplace_back(A[i].first);
        coordY.emplace_back(A[i].second);
      }
      sort(begin(coordX), end(coordX));
      sort(begin(coordY), end(coordY));
      coordX.resize(unique(begin(coordX), end(coordX)) - begin(coordX));
      coordY.resize(unique(begin(coordY), end(coordY)) - begin(coordY));
      
      vector<vector<pair<int, int>>> lsX(coordX.size());
      vector<vector<pair<int, int>>> lsY(coordY.size());
      
      for (int i = 0; i < N; i++) {
        int pos = lower_bound(begin(coordX), end(coordX), A[i].first) - begin(coordX);
        lsX[pos].emplace_back(A[i].second, Find(i));

        pos = lower_bound(begin(coordY), end(coordY), A[i].second) - begin(coordY);
        lsY[pos].emplace_back(A[i].first, Find(i));
      }

      for (int i = 0; i < (int) lsY.size(); i++) {
        sort(begin(lsY[i]), end(lsY[i]));
      }

      for (int i1 = 0; i1 < (int) lsX.size(); i1++) {
        sort(begin(lsX[i1]), end(lsX[i1]));
        for (int j1 = 0; j1 + 1 < (int) lsX[i1].size(); j1++) {
          if (lsX[i1][j1].second != lsX[i1][j1 + 1].second) {
            for (int i2 = 0; i2 < (int) lsY.size(); i2++) {
              for (int j2 = 0; j2 + 1 < (int) lsY[i2].size(); j2++) {
                if (lsY[i2][j2].second != lsY[i2][j2 + 1].second &&
                    lsY[i2][j2].second != lsX[i1][j1].second && 
                    lsY[i2][j2].second != lsX[i1][j1 + 1].second &&
                    lsY[i2][j2 + 1].second != lsX[i1][j1].second && 
                    lsY[i2][j2 + 1].second != lsX[i1][j1 + 1].second) {
                  int x = coordX[i1];
                  int y = coordY[i2];
                  if (abs(y - lsX[i1][j1].first) <= t && abs(y - lsX[i1][j1 + 1].first) <= t &&
                      abs(x - lsY[i2][j2].first) <= t && abs(x - lsY[i2][j2 + 1].first) <= t) {
                    return true;      
                  }
                }   
              }
            }
          }
        }
      }
      return false;
    } else {
      return false;
    }
  };
 
  const auto Can = [&](int t) -> bool {
    bool res = false;
    res |= Check(t);
    for (int i = 0; i < N; i++) {
      swap(A[i].first, A[i].second);
    }
    res |= Check(t);
    for (int i = 0; i < N; i++) {
      swap(A[i].first, A[i].second);
    }
    return res;
  };

  int lo = 0, hi = 2e9;
  if (!Can(hi)) {
    cout << -1 << "\n";
    return 0; 
  }
  while (lo < hi) {
    int md = (1ll * lo + hi) / 2;
    if (Can(md)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }

  cout << lo << "\n";
  return 0;
}