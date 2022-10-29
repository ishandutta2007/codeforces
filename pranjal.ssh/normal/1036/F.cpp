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


int p[101];
int mu[101];

ll expo(ll n, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * n);
        }
        n = (n * n);
        p >>= 1;
    }
    return ans;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0);
   FOR (i, 1, 100) p[i] = i;
   FOR (i, 2, 10) if (p[i] == i) for (int j = i*i; j <= 100; j += i) p[j] = i;
   mu[1] = 1;
   FOR (i, 2, 100) {
      if ((i / p[i]) % p[i]) {
         mu[i] = -mu[i/p[i]];
      }
   }

   int t; cin >> t; while (t--) {
      ll n; cin >> n;
      ll ans = n-1;
      FOR (i, 2, 60) if (mu[i]) {
         ll x = floor(pow(n, 1.0L/i));
         if (pow(x+1, i) <= 1e18 and expo(x+1, i) <= n) ++x;
         ans += mu[i] * (x - 1);
      }
      cout << ans << "\n";
   }  

   return 0;
}