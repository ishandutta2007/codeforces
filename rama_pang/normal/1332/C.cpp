#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> freq(k, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
      freq[i % k][s[i] - 'a']++;
    }
    int ans = 0;

    for (int l = 0, r = k - 1; l <= r; l++, r--) {
      int mx = 0;
      for (int i = 0; i < 26; i++) {
        mx = max(mx, (l == r ? freq[l][i] : freq[l][i] + freq[r][i]));
      }
      ans += (1 + (l != r)) * (n / k) - mx;
    }

    cout << ans << "\n";
  }

}