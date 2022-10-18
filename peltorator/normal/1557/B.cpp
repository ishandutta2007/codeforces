#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& val : a) {
    cin >> val;
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  int changes = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (lower_bound(b.begin(), b.end(), a[i]) + 1 != 
        lower_bound(b.begin(), b.end(), a[i + 1])) {
      changes++;      
    }
  }
  cout << (changes <= k - 1 ? "Yes\n" : "No\n");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}