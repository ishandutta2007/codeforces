#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  const int MAX = 3e6 + 5;
  vector<int> last(MAX, -1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    last[a[i]] = a[i];
  }
  for (int i = 1; i < MAX; i++) {
    if (last[i] == -1) {
      last[i] = last[i - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i < MAX; i++) {
    if (last[i] == i) {
      for (int j = i; j < MAX; j += i) {
        if (last[j] != -1) {
          ans = max(ans, last[j] % i);
        }
        if (j > i && last[j - 1] != -1) {
          ans = max(ans, last[j - 1] % i);
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}