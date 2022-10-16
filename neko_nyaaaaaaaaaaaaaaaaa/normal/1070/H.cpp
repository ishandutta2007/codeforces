#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      map<string, set<int>> m;
      vector<string> s(n);
      while (n--) {
            cin >> s[n];
            int k = s[n].size();
            for (int i = 0; i < k; i++) {
                  string tmp;
                  for (int j = i; j < k; j++) {
                        tmp += s[n][j];
                        m[tmp].insert(n);
                  }
            }
      }

      int q; cin >> q;
      while (q--) {
            string x; cin >> x;
            if (m.find(x) == m.end()) {cout << "0 -\n";}
            else {
                  cout << m[x].size() << " " << s[*m[x].begin()] << '\n';
            }
      }

      return 0;
}