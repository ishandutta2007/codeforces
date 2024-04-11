#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(3 * n);
    for (int i = 0; i < m; ++i){
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      G[u].emplace_back(v, i);
      G[v].emplace_back(u, i);
    }
    vector<int> ans;
    vector<bool> used(3 * n, false);
    for (int i = 0; i < 3 * n; ++i){
      if (used[i])
        continue;
      for (auto [v, j] : G[i])
        if (!used[v]){
          used[i] = true;
          used[v] = true;
          ans.push_back(j);
          break;
        }
    }
    if (ans.size() >= n){
      cout << "Matching\n";
      for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << " ";
      cout << "\n";
    } else {
      cout << "IndSet\n";
      int cnt = 0;
      int i = 0;
      while (cnt < n){
        if (!used[i]){
          cout << i + 1 << " ";
          ++cnt;
        }
        ++i;
      }
      cout << "\n";
    }
  }
  return 0;
}