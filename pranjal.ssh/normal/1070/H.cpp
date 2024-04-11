#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ff first
#define ss second
const char nl = '\n';
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */
#include <bits/extc++.h>
namespace pbds =  __gnu_pbds;
template <typename key, typename val=pbds::null_type, typename comp=less<key> >
using ostree = pbds::tree<key, val, comp, pbds::rb_tree_tag,
                          pbds::tree_order_statistics_node_update>;
using vi = vector< int >; using vll = vector< ll >;
#define allOf(x) std::begin(x), std::end(x)
template <typename...Args>
ostream&operator<<(ostream&os, pair<Args...> const &p)
{return os<<'('<<p.first<<", "<<p.second<<')';}
template <typename...Args>
ostream&operator<<(ostream&os, vector<Args...> const &v)
{os<<'[';for(const auto&el:v)os<<' '<<el;return(os<<" ]");}
template <typename...Args> ostream&operator<<(ostream&os, map<Args...>const&v)
{os<<'[';for(auto const&el:v)os<<' '<<el;return(os<<" ]");}
template <typename...Args> ostream&operator<<(ostream&os, set<Args...>const&v)
{os<<'[';for(auto const&el:v)os<<' '<<el;return(os<<" ]");}
template <typename...Args>
ostream&operator<<(ostream&os, unordered_map<Args...>const&v)
{os<<'[';for(auto const&el:v)os<<' '<<el;return(os<<" ]");}
template<typename T> void trace_rec(stringstream&sst, const T&t)
{ string arg; getline(sst, arg, ','); cerr << arg << " : " << t << " }"; }
template<typename T, typename... Args>
void trace_rec(stringstream&sst, const T&t, const Args... args)
{ string arg; getline(sst, arg, ','); cerr << arg << " : " << t << ", ";
  trace_rec(sst, args...); }
template<typename... Args> void trace(const string&s, Args... args)
{stringstream sst(s); cerr << "{ "; trace_rec(sst, args...); cerr << endl;}
#define dbg(...) trace(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void dbr(const T lb, const T ub)
{cerr<<'{';for(auto it=lb; it!=ub; it++)cerr<<' '<<(*it);cerr<<" }"<<endl;}
template<typename T, typename Comp=less<T> >
bool setMin(T &mem, const T&v, Comp comp = Comp())
{ return comp(v, mem) ? mem = v, true : false; }
template<typename T, typename Comp=less<T> >
bool setMax(T &mem, const T&v, Comp comp = Comp())
{ return comp(mem, v) ? mem = v, true : false; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */

int n, q;
unordered_map<string, int> cnt;
unordered_map<string, string> name;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    string s; cin >> s;
    set< string > subs;
    for(int i=0; i<(int)s.length(); i++) {
      for(int j=1; j<=(int)s.length()-i; j++) {
        // cerr << s.substr(i, j) << endl;
        subs.emplace(s.substr(i, j));
      }
    }
    for(auto &sub: subs) cnt[sub]++;
    for(auto &sub: subs) name[sub] = s;
  }
  cin >> q;
  for(int i=1; i<=q; i++) {
    string s; cin >> s;
    if( cnt.find(s) == cnt.end() ) {
      cout << "0 -" << nl;
    } else {
      cout << cnt[s] << ' ' << name[s] << endl;
    }
  }

  return 0;
}

/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */