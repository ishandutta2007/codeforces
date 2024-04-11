#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n, m; cin >> n >> m;
   int ss, es; cin >> ss >> es;
   int v; cin >> v;
   vi s(ss), e(es);
   FOR (i, 0, ss-1) cin >> s[i];
   FOR (i, 0, es-1) cin >> e[i];

   sort(all(s)), sort(all(e));

   int q; cin >> q;
   while (q--) {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      int ans = inf;
      if (x1 == x2) {
         cout << abs(y1-y2) << "\n";
         continue;
      }
      if (!s.empty()) {
         auto it = upper_bound(all(s), y1);
         if (it != s.end()) {
            ans = min(ans, abs(y1-*it) + abs(y2-*it) + abs(x1-x2));
         }
         if (it != s.begin()) {
            --it;
            ans = min(ans, abs(y1-*it) + abs(y2-*it) + abs(x1-x2));  
         }
      }
      if (!e.empty()) {
         auto it = upper_bound(all(e), y1);
         if (it != e.end()) {
            ans = min(ans, abs(y1-*it) + abs(y2-*it) + (abs(x1-x2)+v-1)/v);
         }
         if (it != e.begin()) {
            --it;
            ans = min(ans, abs(y1-*it) + abs(y2-*it) + (abs(x1-x2)+v-1)/v);
         }  
      }
      cout << ans << "\n";
   }

   return 0;
}