#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define cerr cout

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {
    cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(string str, T t, S... s) {
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << " | ";
    dbs(str.substr(idx + 1), s...);
}
#undef cerr

#define inc_stack_limit const rlim_t kStackSize = 128 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {if ((a += b) >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {if ((a -= b) < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}
struct dis_set
{
   vi p, r;
   dis_set(int n):p(n),r(n){FOR(i, 0, n - 1)p[i] = i;}

   int get(int i)
   {
      if (p[i] != i)p[i] = get(p[i]);
      return p[i];
   }
   int connect(int i, int j)
   {
      int x = get(i), y = get(j);
      if (x == y) return 0;
      if (r[x] < r[y])p[x] = y;
      else {p[y] = x; if (r[x] == r[y])++r[x];}
      return 1;
   }
};

int main() 
{
   ios_base::sync_with_stdio(false);   cin.tie(NULL);

   int n, m, k; cin >> n >> m >> k;
   dis_set a(n);
   FOR (i, 0, n - 1) {
      int j = i + k - 1;
      if (j >= n) continue;
      int yo = j;
      FOR (it, i, j) {
         if (it >= yo) break;
         a.connect(it, yo);
         --yo;
      }
   }
   int ans = 1;
   FOR (i, 0, n - 1) if (a.get(i) == i) {
      ans = mul(ans, m);
   }
   cout << ans;
   
   return 0;   
}