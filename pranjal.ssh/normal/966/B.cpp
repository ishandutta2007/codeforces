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

vi solve(vector<ii> c, int x1, int x2) {
   int n = sz(c);
   int j = 0;
   vi ans(n);
   NFOR (i, n, 1) {
      while (j < n and c[j].F*1LL*i < x1) ++j;
      if (j == n) break;
      if (j + i < n and c[j+i].F * 1LL * (n-j-i) >= x2) {
         FOR (it, j, j+i-1) ans[c[it].S] = 1;
         FOR (it, j+i, n-1) ans[c[it].S] = 2;
         return ans;
      }
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n, x1, x2; cin >> n >> x1 >> x2;
   vector<ii> c(n);
   FOR (i, 0, n - 1) cin >> c[i].F, c[i].S = i;

   sort(all(c));
   vi ans = solve(c, x1, x2);
   if (*max_element(all(ans)) == 0) {
      ans = solve(c, x2, x1);
      for (int &i : ans) if (i) i ^= 3;
   }
   if (*max_element(all(ans)) == 0) {
      cout << "No\n";
   } else {
      cout << "Yes\n";
      cout << count(all(ans), 1) << " " << count(all(ans), 2) << "\n";
      FOR (i, 0, n - 1) if (ans[i] == 1) cout << i+1 << " "; cout << "\n";
      FOR (i, 0, n - 1) if (ans[i] == 2) cout << i+1 << " "; cout << "\n";
   }


   return 0;
}