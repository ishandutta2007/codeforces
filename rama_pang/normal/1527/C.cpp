#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> occ;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    occ[a[i]].emplace_back(i);
  }
  long long ans = 0;
  for (auto &[elem, vec] : occ) {
    long long sum = 0;
    // [i, j] += (i + 1) * (n - j)
    for (auto i : vec) {
      ans += sum * (n - i);
      sum += i + 1;
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