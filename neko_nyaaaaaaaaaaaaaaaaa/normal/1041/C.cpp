#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, m, d;
      cin >> n >> m >> d;
      vector<ll> a(n);
      set<ll> s;
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
      }
      map<ll, ll> ans;
      ll ind = 0;
      while (s.size()) {
            ind++;
            ll prev = *s.begin();
            ans[prev] = ind;
            s.erase(s.begin());
            while (s.upper_bound(prev + d) != s.end()) {
                  auto it = s.upper_bound(prev + d);
                  ans[*it] = ind;
                  prev = *it;
                  s.erase(it);
            }
      }
      cout << ind << '\n';
      for (int i = 0; i < n; i++) {
            cout << ans[a[i]] << " ";
      }

      return 0;
}