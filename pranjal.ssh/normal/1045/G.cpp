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

const int N = 100100;
int n, k;
using Tree = ostree< pair<int, int> >;
unordered_map< int, Tree > sw;
tuple<int,int,int> v[N];

const int L = 0, M = 1, R = 2;
struct Event {
  int pos, type, idx;
};

bool operator<(const Event&ev1, const Event&ev2) {
  if(ev1.pos != ev2.pos )
    return ev1.pos < ev2.pos;
  return ev1.type < ev2.type;
}

vector< Event > ev;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    int x, r, q; cin >> x >> r >> q;
    v[i] = tie(x, r, q);
    // ev.emplace_back(Event({x-r, L, i}));
    ev.emplace_back(Event({x, L, i}));
    ev.emplace_back(Event({x+r, R, i}));
  }

  sort(allOf(ev));

  ll ans = 0;
  for(auto&event: ev) {
    int pos = event.pos, type = event.type, idx = event.idx;
    int x, r, q; tie(x, r, q) = v[ idx ];
    // dbg(pos, x, r, q);
    if( type == L ) {
      for(int qq = q-k; qq<=q+k; qq++) {
	if( sw.find(qq) == sw.end() ) continue;
	auto &tree = sw[qq];
	ll nums = tree.size() - tree.order_of_key({x-r, 0});
	// ll nums = tree.size() - tree.order_of_key(*it);
	// dbg(qq, nums);
	ans += nums;
      }
      sw[q].insert({x, idx});
    } else {
      sw[q].erase({x, idx});
    }
  }

  cout << ans << nl;

  return 0;
}

/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */