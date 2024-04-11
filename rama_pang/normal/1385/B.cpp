#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto &i : a) {
      cin >> i;
      i--;
    }
    vector<int> ans;
    vector<int> done(n, 0);
    for (auto i : a) {
      if (!done[i]) {
        done[i] = 1;
        ans.emplace_back(i);
      }
    }
    for (auto &i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }  
  return 0;
}