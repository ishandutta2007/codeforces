#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  set<pair<int, int>> ans;
  for (int i = 1; i <= n + 1; i++) {
    ans.emplace(i, i);
    ans.emplace(i - 1, i);
    ans.emplace(i, i - 1);
    ans.emplace(i - 1, i - 1);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}