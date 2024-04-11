#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> f;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  int ans = -1;
  for (auto i : f) {
    if (i.second == 1) {
      if (ans == -1 || ans > i.first) {
        ans = i.first;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == ans) {
      ans = i;
      break;
    }
  }

  cout << ans + (ans != -1) << '\n';
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