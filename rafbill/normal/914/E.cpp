#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

const int N = 2e5;
const int LN = 20;
int CC[N];
int parent[LN][N];
int depth[N];
int val[N];

lli tmp[1<<20];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vvi G(n);
  FOR(i,n-1) {
    int u,v; cin>>u>>v;
    --u; --v;
    G[u].pb(v);
    G[v].pb(u);
  }
  FOR(i,n) { char c; cin>>c; CC[i] = c-'a'; }

  function<void(int,int)> dfs0 = [&](int i, int p) {
    parent[0][i]=p;
    depth[i]=(p == -1)?0:1+depth[p];
    val[i]=val[p]; val[i] ^= (1<<CC[i]);
    for(int j : G[i]) if(j != p) dfs0(j,i);
  };
  dfs0(0,-1);

  FOR(i,LN-1) FOR(j,n) {
    if(parent[i][j] != -1) {
      parent[i+1][j] = parent[i][parent[i][j]];
    }
    else parent[i+1][j] = -1;
  }
  function<int(int,int)> lca = [&](int i, int j) {
    if(depth[i]<depth[j]) swap(i,j);
    FORD(k,LN-1,0) if(depth[i]-(1<<k) >= depth[j]) {
      i = parent[k][i];
    }
    if(i==j) return i;
    FORD(k,LN-1,0) if(depth[i]>=(1<<k)) {
      if(parent[k][i] != parent[k][j]) {
        i=parent[k][i];
        j=parent[k][j];
      }
    }
    return parent[0][i];
  };
  function<lli(int,int)> path = [&](int i, int j) {
    int l = lca(i,j);
    int r = val[i]^val[j];
    r ^= (1<<CC[l]);
    return r;
  };

  vector<lli> ans(n);
  vector<lli> ans2(n,1);
  auto addpath = [&](int i, int j, lli v) {
    int l = lca(i,j);
    ans[i] += v;
    ans[j] += v;
    ans[l] -= v;
    if(parent[0][l] != -1) ans[parent[0][l]] -= v;
  };

  // centroid decomposition
  // input : tree G
  vector<int>  A(n,0);
  vector<int>  CP(n,-1);
  int root;
  FOR(l,50){
    vector<int> E = A;
    vector<int> P(n);
    vector<int> S(n,1);
    function<void(vector<int>&, int,int)> dfs0 = [&](vector<int>& C, int i,int p){
      E[i]=1; P[i]=p; C.pb(i);
      for(int j : G[i]) if(!A[j] && j!=p) {
          dfs0(C,j,i);
          S[i]+=S[j];
        }
    };
    vector<int> C;
    FOR(i,n) if(!E[i]) {
      C.clear();
      dfs0(C, i, -1);
      auto f = [&](int j){
        int r=0;
        for(auto k : G[j]) if(!A[k] && k!=P[j]) r=max<int>(r,S[k]);
        r=max<int>(r,S[i]-S[j]);
        return r;
      };
      int centroid=i; int best=f(i);
      for(int j : C) {
        int v=f(j); if(v<best) { centroid=j; best=v; }
      }
      A[centroid]=1;
      // do a dfs on this centroid subtree here :

      vector<vector<tpl<int,int>>> B;
      function<void(int, int)> dfs1 = [&](int i, int p) {
        B.back().pb(mt(i,path(centroid,i)));
        for(int j : G[i]) if(!A[j] && j != p) {
            dfs1(j,i);
          }
      };
      B.emplace_back(); B.back().pb(mt(centroid,path(centroid,centroid)));
      for(int j : G[centroid]) if(!A[j]) { B.emplace_back(); dfs1(j,centroid); }
      for(auto const& v : B) for(auto const& iw : v) {
          int i,w; tie(i,w) = iw;
          tmp[w] += 1;
        }
      lli cntAll = 0;
      for(auto const& v : B) {
        for(auto const& iw : v) {
          int i,w; tie(i,w) = iw;
          tmp[w] -= 1;
        }
        for(auto const& iw : v) {
          int i,w; tie(i,w) = iw;
          w ^= (1<<CC[centroid]);
          lli cnt = tmp[w];
          FOR(j,20) {
            cnt += tmp[w^(1<<j)];
          }
          cntAll += cnt;
          if(cnt) addpath(i,centroid,cnt);
        }
        for(auto const& iw : v) {
          int i,w; tie(i,w) = iw;
          tmp[w] += 1;
        }
      }
      ans2[centroid] -= cntAll/2;
      for(auto const& v : B) for(auto const& iw : v) {
          int i,w; tie(i,w) = iw;
          tmp[w] = 0;
        }
      // dfs1(centroid, -1);

      // doDfs(centroid);
      if(CP[centroid]==-1) root=centroid;
      for(int j : C) if(j!=centroid) CP[j]=centroid;
    }
    FOR(i,n) if(!A[i]) goto l_beg;
    break;
  l_beg:;
  }

  vvi H(n); FOR(i,n) if(CP[i]!=-1) H[CP[i]].pb(i);
  // the tree (root,H) is now a centroid decomposition

  // cout << ans << endl;
  // cout << ans2 << endl;

  function<void(int,int)> dfs2 = [&](int i, int p) {
    for(int j : G[i]) if(j != p) {
        dfs2(j,i);
        ans[i] += ans[j];
      }
  };
  dfs2(0,-1);

  // cout << ans << endl;
  FOR(i,n) cout << ans[i]+ans2[i] << ' '; cout << endl;

  return 0;
}