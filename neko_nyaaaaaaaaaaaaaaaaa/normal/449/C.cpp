#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> bucket;
      vector<pair<int, int>> ans;
      vector<int> taken(100002);
      for (int i = 3; i <= n/2; i += 2) {
            if (!taken[i]) {
                  vector<int> s;
                  for (int j = i; j <= n; j += i) {
                        if (taken[j]) continue;
                        taken[j] = 1;
                        s.push_back(j);
                  }
                  if (s.size() % 2) {
                        bucket.push_back(s[1]);
                        s.erase(s.begin() + 1);
                  }
                  for (int j = 1; j < s.size(); j += 2) {
                        ans.push_back({s[j], s[j-1]});
                  }
            }
      }
      for (int i = 2; i <= n; i += 2) {
            if (!taken[i]) bucket.push_back(i);
      }

      for (int i = 1; i < bucket.size(); i += 2) {
            ans.push_back({bucket[i], bucket[i-1]});
      }

      cout << ans.size() << '\n';
      for (auto u: ans) {
            cout << u.first << " " << u.second << '\n';
      }

      return 0;
}