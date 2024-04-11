#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi; const int inf = 1e9 + 7;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n, k; cin >> n >> k;
   vector<ii> a(n);
   map<int, vi> mp;
   for (int i = 0; i < n; ++i) cin >> a[i].F >> a[i].S, mp[a[i].F].push_back(i);

   ordered_set s;
   
   int ans = 0;
   for (auto& it : mp) {
      while (!s.empty() and s.begin()->F < it.F) s.erase(s.begin());
      for (int id : it.S) {
         s.insert({a[id].S, id});
      }
      int sz = s.size();
      if (sz < k) continue;
      auto itt = s.find_by_order(sz - k);
      ans = max(ans, itt->F - it.F + 1);
   }
   cout << ans << "\n";
   if (ans == 0) {
      for (int i = 1; i <= k; ++i) cout << i << " ";
      return 0;
   }
   s.clear();
   for (auto& it : mp) {
      while (!s.empty() and s.begin()->F < it.F) s.erase(s.begin());
      for (int id : it.S) {
         s.insert({a[id].S, id});
      }
      int sz = s.size();
      if (sz < k) continue;
      auto itt = s.find_by_order(sz - k);
      if (ans == itt->F - it.F + 1) {
         while (k--) {
            cout << itt->S + 1 << " ";
            ++itt;
         }
         cout << "\n";
         return 0;
      }
   }

   return 0;
}