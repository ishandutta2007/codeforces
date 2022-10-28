#include <bits/stdc++.h>
using namespace std;

typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi;
#define dbg(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> void debug(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a) cerr << ", ";cerr << *i;}cerr << "]\n";}

string s;
int dp[160][160][160];
int DP[160];
int a[160];

int f(int l, int r, int len) {
   if(l > r) return a[len];
   int& ans = dp[l][r][len];
   if (~ans) return ans;

   ans = -1e9;
   if (len and a[len] >= 0) 
      ans = max(ans, a[len] + f(l, r, 0));
   if (s[l - 1] == s[r - 1])
      ans = max(ans, f(l + 1, r - 1, len + 2 - (l == r)));

   for (int i = l; i < r; ++i) {
      ans = max(ans, f(l, i, len) + f(i + 1, r, 0));
      ans = max(ans, f(l, i, 0) + f(i + 1, r, len));
   }

   return ans;
}

int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n; cin >> n;

   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == -1)
         a[i] = -1e9;
   }

   cin >> s;
   memset(dp, ~0, sizeof dp);

   for (int i = 1; i <= n; ++i) {
      DP[i] = DP[i - 1];
      for (int j = 0; j < i; ++j) {
         DP[i] = max(DP[i], DP[j] + f(j + 1, i, 0));
      }
   }
   cout << DP[n] << "\n";


   return 0;
}