#include <bits/stdc++.h>
using namespace std;

int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      
      int n, m;
      cin >> n;
      map<int, int> a;
      while (n--) {
            cin >> m;
            a[m]++;
      }
      int ans = 0;
      pair<int, int> answ;
      cin >> m;
      vector<pair<int, int>> b(m);
      for (int i = 0; i < m; i++) {
            cin >> b[i].first;
            b[i].first = a[b[i].first];
      }
      for (int i = 0; i < m; i++) {
            cin >> b[i].second;
            b[i].second = a[b[i].second];
      }
      for (int i = 0; i < m; i++) {
            if (b[i].first > answ.first) {
                  ans = i;
                  answ = b[i];
                  continue;
            } else if (b[i].first == answ.first && b[i].second > answ.second) {
                  ans = i;
                  answ = b[i];
                  continue;
            }
      }
      cout << ans+1;
      
      return 0;
}