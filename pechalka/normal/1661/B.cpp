#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int K = 32768;
vector<int> G[K + 228];
int dist[K + 228];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  for (int x = 0; x < K; ++x) {
    G[(x + 1) % K].emplace_back(x);
    G[(2 * x) % K].emplace_back(x);
  }
  fill(dist, dist + K, K);
  dist[0] = 0;
  deque<int> Q;
  Q.emplace_back(0);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop_front();
    for (int u : G[v]) {
      if (dist[u] > dist[v] + 1) {
        dist[u] = dist[v] + 1;
        Q.emplace_back(u);
      }
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cout << dist[x] << ' ';
  }
  cout << '\n';
  return 0;
}