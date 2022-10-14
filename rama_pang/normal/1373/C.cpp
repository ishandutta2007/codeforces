#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = s.size();
    int sum = 0;
    vector<int> pref(s.size());
    map<int, int> mp;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '+') {
        sum++;
      } else {
        sum--;
      }
      pref[i] = sum;
      if (i > 0) {
        pref[i] = min(pref[i], pref[i - 1]);
      }
    }
    for (int i = 0; i < (int) s.size(); i++) if (pref[i] < 0) {
      ans += 1ll * (i + 1) * abs(pref[i] - (i > 0 ? pref[i - 1] : 0));
    }

    
    cout << ans << "\n";
  }  
}