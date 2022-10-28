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

const int N = 10+(int)1e6;

template<typename T> struct Fenwick {
  vector<T> tree;
  Fenwick(const size_t &n=0, const T&val=T()) { tree.resize(n, val); }
  T get(int pos) {
    T ret = 0;
    for(; pos>=0; pos=(pos&(pos+1))-1) ret += tree[pos];
    return ret;
  }
  void put(int pos, const T&val) {
    for(; pos<(int)tree.size(); pos|=(pos+1)) tree[pos]+=val;
  }
  int upper_bound(T acc) {
    int idx = 0, x = (1<<30);
    for(; x>0; x>>=1) {
      if(idx+x-1>=(int)tree.size()) continue;
      if(acc >= tree[idx+x-1]) acc -= tree[idx+x-1], idx+=x;
    }
    return idx;
  }
};
Fenwick<ll> nbit(N), cbit(N);

int n, k, m;
vector< pair<int,int> > add[N], rem[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k >> m;
  for(int i=1; i<=m; i++) {
    int l, r, c, p;
    cin >> l >> r >> c >> p;
    add[l].emplace_back(c, p);
    rem[r].emplace_back(c, p);
  }

  ll ans = 0;
  for(int i=1; i<=n; i++) {
    for(auto ev: add[i]) {
      nbit.put(ev.ss, ev.ff);
      cbit.put(ev.ss, ev.ss*1ll*ev.ff);
    }
    int idx = nbit.upper_bound(k-1);
    if( idx == N ) {
      ans += cbit.get(N-1);
    } else {
      /*
      for(int j=1; j<=10; j++) cerr << nbit.get(j)-nbit.get(j-1) << ' '; cerr << endl;
      for(int j=1; j<=10; j++) cerr << cbit.get(j)-cbit.get(j-1) << ' '; cerr << endl;
      for(int j=1; j<=10; j++) cerr << nbit.get(j) << ' '; cerr << endl;
      for(int j=1; j<=10; j++) cerr << cbit.get(j) << ' '; cerr << endl;
      */
      ll cores = k - (idx>0?nbit.get(idx-1):0);
      ll base = (idx>0?cbit.get(idx-1):0);
      // dbg(i, idx, base, cores, base+cores*idx);
      ans += base + cores * idx;
    }
    for(auto ev: rem[i]) {
      nbit.put(ev.ss, -ev.ff);
      cbit.put(ev.ss, -ev.ss*1ll*ev.ff);
    }
  }
  cout << ans << endl;

  return 0;
}

/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */