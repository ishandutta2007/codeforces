#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int cnt0 = 0, cnt1 = 0;
  for (auto i : a) if (i == 0) cnt0 += 1;
  int ans = 1e9;
  for (auto i : a) {
    ans = min(ans, max(cnt0, cnt1));
    cnt0 -= i == 0;
    cnt1 += i == 1;
    ans = min(ans, max(cnt0, cnt1));
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
}