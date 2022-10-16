#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<pair<int, int>> pos, neg, z;
      for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x > 0) pos.push_back({x, i});
            if (x < 0) neg.push_back({x, i});
            if (x == 0) z.push_back({x, i});
      }
      sort(neg.begin(), neg.end());
      int remov = 0;
      if (neg.size() % 2) {
            auto k = neg.back();
            if (z.size()) {
                  cout << 1 << " " << k.second << " " << z[0].second << '\n';
            } else {
                  cout << 2 << " " << k.second << '\n';
                  remov = 1;
            }
            neg.pop_back();
      }
      for (int i = 1; i < neg.size(); i++) {
            cout << 1 << ' ' << neg[i].second << ' ' << neg[0].second << '\n';
      }
      for (int i = 1; i < z.size(); i++) {
            cout << 1 << ' ' << z[i].second << ' ' << z[0].second << '\n';
      }
      for (int i = 1; i < pos.size(); i++) {
            cout << 1 << ' ' << pos[i].second << ' ' << pos[0].second << '\n';
      }

      if (!remov) {
            if (z.size() && (pos.size() || neg.size())) {cout << 2 << " " << z[0].second << '\n';}
            if (pos.size() && neg.size()) {
                  cout << 1 << " " << pos[0].second << " " << neg[0].second << '\n';
            }
      } else {
            vector<int> tmp;
            if (pos.size()) tmp.push_back(pos[0].second);
            if (neg.size()) tmp.push_back(neg[0].second);
            if (z.size()) tmp.push_back(z[0].second);

            for (int i = 1; i < tmp.size(); i++) {
                  cout << 1 << " " << tmp[i] << " " << tmp[0] << '\n';
            }
      }

      return 0;
}