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
    cin  >> n >> k;
    string s;
    cin >> s;
    sort(begin(s), end(s));
    vector<string> a(k), a2(k);
    for (int i = 0, all_in = 0; i < n; i++) {
      a[i % k].push_back(s[i]);
      if (i < k) {
        a2[i % k].push_back(s[i]);
      } else {
        a2[0].push_back(s[i]);
      }
    }

    sort(begin(a), end(a));
    sort(begin(a2), end(a2));
    cout << min(a.back(), a2.back()) << "\n";
  }

}