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


vi fail(const string &s) {
   int n = sz(s);
   vi f(n);
   FOR (i, 1, n - 1) {
      f[i] = f[i - 1];
      while (s[f[i]] != s[i]) {
         if (f[i] == 0) break;
         f[i] = f[f[i] - 1];
      }
      if (s[f[i]] == s[i]) f[i]++;
   }
   return f;
}
string s;
vi F;

int DP[41][2];
int getNext(int now, int ch) {
   int &ans = DP[now][ch-'0'];
   if (~ans) return ans;
   int x = now;
   if (now == sz(s)) now = F[now - 1];
   while (s[now] != ch) {
      if (now == 0) return ans=0;
      now = F[now - 1];
   }
   return ans=now + 1;
}

vi prv[41][2];
ll dp[2][41][41];

ll f(int n, int cur) {
   if (n == 0) return cur == sz(s);

   ll &ans = dp[0][n][cur];
   if (~ans) return ans;
   ans = 0;
   FOR (i, '0', '1') {
      int nxt = getNext(cur, i);
      if (n - 1 > 0 and nxt == sz(s)) continue;
      ans += f(n - 1, nxt);
   }
   return ans;
}

ll g(int n, int cur) {
   if (n == 0) return cur == sz(s);

   ll &ans = dp[1][n][cur];
   if (~ans) return ans;
   ans = 0;
   FOR (i, 0, 1) {
      for (int nxt : prv[cur][i])
         ans += g(n - 1, nxt);
   }
   return ans;
}
int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n; cin >> n;
   cin >> s;
   F = fail(s);


   memset(dp, -1, sizeof dp);
   memset(DP, -1, sizeof DP);
   FOR (i, 0, sz(s)) FOR (j, 0, 1) prv[getNext(i, j+'0')][j].push_back(i);

   ll ans = 0;
   FOR (i, 0, sz(s)) {
      FOR (pos, 0, n - 1) {
         ans += f(pos+1, i) * g(n-(pos+1), i);
      }
   }
   
   cout << ans;

   return 0;
}