#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      vector<string> k = {"A", "B", "C", "AB", "BC", "AC", "ABC"};
      map<string, int> m;
      for (int i = 0; i < k.size(); i++) {
            m[k[i]] = 1000000;
      }
      int n; cin >> n;
      while (n--) {
            int x; string s;
            cin >> x >> s;
            sort(s.begin(), s.end());
            m[s] = min(m[s], x);
      }

      m["A"] = min(m["A"], min(m["AB"], m["AC"]));
      m["B"] = min(m["B"], min(m["AB"], m["BC"]));
      m["C"] = min(m["C"], min(m["AC"], m["BC"]));

      int ans = m["A"] + m["B"] + m["C"];
      ans = min(ans, m["ABC"]);
      ans = min(ans, m["A"] + m["BC"]);
      ans = min(ans, m["B"] + m["AC"]);
      ans = min(ans, m["C"] + m["AB"]);

      if (ans >= 1000000) {cout << -1; return 0;}
      cout << ans;

      return 0;
}