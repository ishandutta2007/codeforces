#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, a;
int t[1000];

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  cin >> n >> a;
  a--;
  for (int i = 0; i < n; i++) cin >> t[i];
  
  int ans = t[a];
  
  for (int d = 1; d <= n; d++) {
    int l = a - d;
    int r = a + d;
    if (l >= 0 && r >= n) {
      ans += t[l];
    } else if (l < 0 && r < n) {
      ans += t[r];
    } else if (0 <= l && r < n) {
      if (t[l] + t[r] == 2) ans += 2;
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}