#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int inf = 1e9+1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      map<int, int> mp;
      set<pair<int, int>> s;
      for (int i = 0; i < k-1; i++) {
            mp[a[i]]++;
      }
      for (auto u: mp) {
            s.insert({u.second, u.first});
      }

      for (int i = k-1; i < n; i++) {
            auto it = s.find({mp[a[i]], a[i]});
            if (it != s.end()) s.erase(it);
            mp[a[i]]++;
            s.insert({mp[a[i]], a[i]});

            auto u = *s.begin();
            if (u.first > 1) {
                  cout << "Nothing\n";
            } else {
                  auto it2 = s.lower_bound({2, -inf});
                  it2--;
                  cout << it2->second << '\n';
            }

            it = s.find({mp[a[i-k+1]], a[i-k+1]});
            if (it != s.end()) s.erase(it);
            mp[a[i-k+1]]--;
            if (mp[a[i-k+1]]) s.insert({mp[a[i-k+1]], a[i-k+1]});
      }

	return 0;
}