#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> p(m);
    vector<long long> pref(n), ans(26);
    for (int i = 0; i < m; i++) {
      cin >> p[i];
      p[i]--;
      pref[p[i]]++;
    }
    pref[n - 1]++;
    for (int i = n - 2; i >= 0; i--) {
      pref[i] += pref[i + 1];
    }
    for (int i = 0; i < n; i++) {
      ans[s[i] - 'a'] += pref[i];
    }
    for (int i = 0; i < 26; i++) {
      cout << ans[i] << " \n"[i == 25];
    }
  }
}