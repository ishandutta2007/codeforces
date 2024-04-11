#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    string ans;
    for (int i = 0; i < n; i++) {
      ans.push_back((i % b) + 'a');
    }
    cout << ans << "\n";
  }

}