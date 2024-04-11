#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  set<pair<int, int>> trains;
  trains.insert({0, a[0]});
  for (int i = 1; i < n; ++i) {
    if (a[i] < trains.rbegin()->second) {
      trains.insert({i, a[i]});
    }
  }

  for (int i = 0; i < m; ++i) {
    int k, d;
    scanf("%d %d", &k, &d);
    a[--k] -= d;

    auto it = trains.upper_bound({k, 2e9});
    --it;

    if (a[k] < it->second || it->first == k) {
      // cerr << "Insert ";
      if (it->first == k) {
        trains.erase(it);
      }
      auto it = trains.insert({k, a[k]}).first;

      do {
        auto nit = it;
        ++nit;
        if (nit == trains.end()) break;
        if (nit->second >= a[k]) {
          // cerr << "Erased (" << nit->first << ", " << nit->second << ") ";
          trains.erase(nit);
        } else {
          break;
        }
      } while (true);
    }

    // for (auto it : trains) {
    //   cerr << "(" << it.first << ", " << it.second << ") ";
    // }
    // cerr << endl;

    printf("%d ", (int) trains.size());
  }

  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}