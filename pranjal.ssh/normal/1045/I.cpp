#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ff first
#define ss second
#define nl '\n'
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */

#include <bits/extc++.h>
namespace pbds =  __gnu_pbds;
template <typename key, typename val=pbds::null_type,
	  typename comp=less<key> >
using ostree = pbds::tree<key, val, comp, pbds::rb_tree_tag,
			  pbds::tree_order_statistics_node_update>;
template <typename val=pbds::null_type>
using prefix_trie = pbds::trie<
  string, val, pbds::trie_string_access_traits<>,
  pbds::pat_trie_tag, pbds::trie_prefix_search_node_update>;

using vi = vector< int >;
using vll = vector< ll >;

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
template <typename T, typename... Args> void dbgrec(T t) {cerr<<t;}
template <typename T, typename... Args> void dbgrec(T t, Args... args)
{cerr<<t<<", "; dbgrec(args...);}
template <typename T, typename... Args> void dbg(T t, Args... args)
{cerr<<"{ "; dbgrec(t, args...);cerr<<" }"<<endl;}
template <typename T> void dbr(const T &lb, const T &ub)
{cerr<<'{';for(auto it=lb; it!=ub; it++)cerr<<' '<<(*it);cerr<<" }"<<endl;}
template< typename T, typename Comp=less<T> >
bool setMin(T &mem, const T&v, Comp comp = Comp())
{ return comp(v, mem) ? mem = v, true : false; }
template< typename T, typename Comp=less<T> >
bool setMax(T &mem, const T&v, Comp comp = Comp())
{ return comp(mem, v) ? mem = v, true : false; }

mt19937_64 rng(time(nullptr));

/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  unordered_map<int,int> mp;

  ll ans = 0;
  for(int i=1; i<=n; i++) {
    string s; cin >> s;
    int x = 0;
    for(auto&c: s) {
      int a = c-'a';
      x ^= (1<<a);
    }
    ll temp = 0;
    temp += mp[ x ];
    for(int j=0; j<26; j++)
      temp += mp[ x ^ (1<<j) ];
    ans += temp;
    mp[x]++;
  }
  cout << ans << endl;

  return 0;
}

/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */