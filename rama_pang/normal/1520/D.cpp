#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // i < j: a[j] - a[i] = j - i
  // a[j] - j = a[i] - i
  map<int, int> cnt;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[a[i] - i];
    cnt[a[i] - i] += 1;
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