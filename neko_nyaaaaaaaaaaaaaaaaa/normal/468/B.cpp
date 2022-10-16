#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, x, y; cin >> n >> x >> y;
      int flip = 0;
      if (x < y) {
            swap(x, y);
            flip = 1;
      }
      set<int> s;
      vector<pair<int, int>> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            s.insert(a[i].first);
      }
      sort(a.begin(), a.end());

      map<int, int> ans;
      for (int i = 0; i < n; i++) {
            int k = a[i].first;
            if (ans[k]) continue;

            if (s.find(x - k) != s.end()) {
                  ans[k] = ans[x-k] = 'A';
                  s.erase(x - k);
                  if (s.find(k) != s.end()) s.erase(k);
            } else if (s.find(y - k) != s.end()) {
                  ans[k] = ans[y-k] = 'B';
                  s.erase(y - k);
                  if (s.find(k) != s.end()) s.erase(k);
            } else {
                  cout << "NO";
                  return 0;
            }
      }

      for (int i = 0; i < n; i++) {
            if (!ans[a[i].first]) {
                  cout << "NO";
                  return 0;
            }
      }

      vector<int> res(n);
      for (int i = 0; i < n; i++) {
            int ind = a[i].second;
            if (ans[a[i].first] == 'A') {
                  res[ind] = flip;
            } else {
                  res[ind] = !flip;
            }
      }

      cout << "YES\n";
      for (int i: res) cout << i << " ";

	return 0;
}