#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n;
  cin >> n;
  vector<int> a;
  map<int, int> m[2];
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    a.push_back(u);
    m[i % 2][u]++;
  }
  
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    int u = a[i];
    if (m[i % 2][u] == 0) {
      cout << "NO\n";
      return;
    }
    m[i % 2][u]--;
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}