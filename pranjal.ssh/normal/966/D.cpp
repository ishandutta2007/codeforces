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
   vector<vi> g(n);
   FOR (i, 0, m - 1) {
      int x, y; cin >> x >> y;
      --x, --y;
      g[x].push_back(y), g[y].push_back(x);
   }
   queue<int> q;
   vi p(n, -1), d(n, -1);
   q.push(0); d[0] = 0;
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : g[x]) if (d[y] == -1) {
         q.push(y);
         p[y] = x;
         d[y] = d[x] + 1;
      }
   }
   int ans = inf;
   vi path;
   if (d[n-1] != -1) {
      ans = d[n - 1];
      path.push_back(n - 1);
      while (path.back() != 0) {
         path.push_back(p[path.back()]);
      }
      reverse(all(path));
   }

   FOR (i, 0, n - 1) if (d[i] == 2 and ans > 4) {
      ans = 4;
      path = {0, p[i], i, 0, n - 1};
   }
   set<int> st;
   FOR (i, 0, n - 1) if (d[i] == 1) {
      st.insert(i), g[i].erase(find(all(g[i]), 0));
   }
   
   p = vi(n, -1), d = vi(n, -1);
   for (int i : st) if (d[i] == -1) {
      q.push(i); d[i] = 0;
      set<int> now;
      while (!q.empty()) {
         int x = q.front();
         now.insert(x);
         q.pop();
         for (int y : g[x]) if (d[y] == -1) {
            q.push(y);
            p[y] = x;
            d[y] = d[x] + 1;
         }
      }
      for (int j : now) p[j] = -1, d[j] = -1;
      for (int j : now) if (sz(g[j]) < sz(now) - 1) {
         q.push(j); d[j] = 0;
         while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x]) if (d[y] == -1) {
               q.push(y);
               p[y] = x;
               d[y] = d[x] + 1;
            }
         }
         break;  
      }
   }
   FOR (i, 0, n - 1) if (d[i] == 2 and ans > 5) {
      ans = 5;
      path = {0, p[p[i]], p[i], i, p[p[i]], n-1};
   }
   if (ans == inf) cout << "-1\n";
   else {
      cout << ans << "\n";
      assert(ans == sz(path) - 1);
      for (int i : path) cout << i+1 << " ";
   }

   return 0;
}