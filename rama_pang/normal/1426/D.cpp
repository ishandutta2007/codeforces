#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  set<long long> s = {0};
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (s.count(sum)) {
      ans++;
      sum = a[i];
      s = {0};
    }
    s.emplace(sum);
  }
  
  cout << ans << "\n";
  return 0;
}