#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef pair<int, int> ii;
#define F first
#define S second

struct event {
   char type;
   int pos;
   bool close;
   int id;
};

int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n; cin >> n;
	vector<ii> s(n); for (int i = 0; i < n; ++i) cin >> s[i].F >> s[i].S;
	int m; cin >> m;
	vector<pair<ii, int>> a(m);

	for(int i = 0; i < m; ++i) cin >> a[i].F.F >> a[i].F.S >> a[i].S;

   vector<event> e;

   for(int i = 0; i < n; ++i) {
      e.push_back({'s', s[i].F, 0, i});
      e.push_back({'s', s[i].S, 1, i});
   }

   for(int i = 0; i < m; ++i) {
      e.push_back({'a', a[i].F.F, 0, i});
      e.push_back({'a', a[i].F.S, 1, i});
   }

   sort(e.begin(), e.end(), [&](const event& x, const event& y) {
      if (x.pos == y.pos) {
         if (x.close == y.close) {
            if (x.type == y.type) return x.id < y.id;
            return x.type < y.type;
         }
         return x.close < y.close;
      }
      return x.pos < y.pos;
   });

   map<int, set<int>> mp;
   map<int, int> ans;
   for (event& it : e) {
      if (it.type == 'a') {
         if (it.close) {
            mp[it.pos].erase(it.id);
            if (mp[it.pos].empty()) mp.erase(it.pos);
         } else {
            mp[a[it.id].F.S].insert(it.id);
         }
      } else {
         if (not it.close) {
            if (mp.empty()) {
               cout << "NO\n";
               return 0;
            } else {
               auto itt = mp.lower_bound(s[it.id].S);
               if (itt == mp.end()) {
                  cout << "NO\n";
                  return 0;
               }
               int id = *(itt->S.begin());
               ans[it.id] = id;
               a[id].S--;
               if (a[id].S == 0) itt->S.erase(id);
               if (itt->S.empty()) mp.erase(itt);
            }
         }
      }
   }
   cout << "YES\n";
   for (ii it : ans) {
      cout << it.S + 1 << " ";
   }
   cout << "\n";

	return 0;	
}