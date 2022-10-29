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

   int n; cin >> n;
   vector<ll> a(n);
   FOR (i, 0, n - 1) cin >> a[i];
   vector<ll> cur;
   NFOR (b, 60, 0) {
      int cnt = 0;
      FOR (i, 0, sz(a) - 1) if (a[i] & (1LL << b)) {
         ++cnt;
      }
      vector<ll> yo, B;
      int j = 0, fuck = 0;
      FOR (i, 0, sz(a) - 1) {
         if (a[i] & (1LL << b)) {
            while (j < sz(cur) and fuck) yo.push_back(cur[j]), fuck ^= !!(cur[j] & (1LL << b)), j++;
            if (fuck) {
               cout << "No\n";
               return 0;
            }
            yo.push_back(a[i]);
            fuck ^= 1;
         } else {
            B.push_back(a[i]);
         }
      }
      while (j < sz(cur)) yo.push_back(cur[j++]);
      cur = yo;
      a = B;
   }  
   cout << "Yes\n";
   for (ll x : cur) cout << x << " ";
   FOR (i, 1, sz(cur) - 1) cur[i] ^= cur[i-1], assert(cur[i] > cur[i-1]);

   return 0;
}