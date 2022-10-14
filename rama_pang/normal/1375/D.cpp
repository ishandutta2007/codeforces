#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }  
  auto Mex = [&]() {
    static set<int> s;
    s.clear();
    for (auto i : a) {
      s.emplace(i);
    }
    for (int i = 0; i <= n; i++) {
      if (s.count(i) == 0) {
        return i;
      }
    }
    return -1;
  };

  vector<int> ans;
  while (!is_sorted(begin(a), end(a))) {
    int mex = Mex();
    if (mex == n) {
      for (int i = 0; i < n; i++) {
        if (a[i] != i) {
          a[i] = mex;
          ans.emplace_back(i);
          break;
        }
      }
    } else {
      ans.emplace_back(mex);
      a[mex] = mex;
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}