#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  vector<lint> cnt(25);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    lint a;
    cin >> a;
    for (int j = 0; j < 25; j++) {
      if (a & (1 << j)) {
        cnt[j]++;
      }
    }
  }  
  lint ans = 0;
  while (true) {
    lint cur = 0;
    for (int i = 0; i < 25; i++) {
      if (cnt[i] > 0) {
        cur |= 1 << i;
        cnt[i]--;
      }
    }
    if (cur == 0) break;
    ans += cur * cur;
  }
  cout << ans << "\n";
  return 0;
}