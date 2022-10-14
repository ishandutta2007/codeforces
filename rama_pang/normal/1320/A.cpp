#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  map<int, long long> mp;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    mp[b - i] += b;
  }
  long long ans = 0;
  for (auto &i : mp) {
    ans = max(ans, i.second);
  }
  
  cout << ans << "\n";
  return 0;
}