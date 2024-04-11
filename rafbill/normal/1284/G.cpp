


 #include <stdio.h>
 #include <bits/stdc++.h>






using namespace std;




template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
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
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}







using li = long long int;
using lu = long long unsigned;
using ld = long double;


using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct empty_t {};

namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }


template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}

struct union_find {
  vi A;

  union_find(li n = 0) : A(n) {
    iota(begin(A), end(A), 0);
  }

  li addNode() {
    A.push_back(A.size());
    return A.size()-1;
  }

  li find(li a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(li a, li b) {
    a = find(a); b = find(b);
    A[a] = b;
  }
};

struct GraphMatroid {
  int n;

  vii es;
  int nv;

  vector<bool> free(vector<bool> const& S) {
    assert((int)S.size() == n);

    union_find uf(nv);
    for(li i = 0; i < (li)(n); ++i) if(S[i]) uf.unite(es[i]^xx, es[i]^yy);

    vector<bool> F(n);
    for(li i = 0; i < (li)(n); ++i) if(!S[i] && uf.find(es[i]^xx) != uf.find(es[i]^yy)) F[i]=1;
    return F;
  }

  void exchanges(vector<bool> const& S, function<void(int,int)> f) {
    assert((int)S.size() == n);

    for(li u = 0; u < (li)(n); ++u) if(S[u]) {
      union_find uf(nv);
      for(li i = 0; i < (li)(n); ++i) if(S[i] && i != u) uf.unite(es[i]^xx,es[i]^yy);
      for(li v = 0; v < (li)(n); ++v) if(!S[v] && uf.find(es[v]^xx) != uf.find(es[v]^yy)) f(u,v);
    }
  }
};

struct DegreeMatroid {
  int n;

  vii es;
  int nv;
  vi max_deg;

  vector<bool> free(vector<bool> const& S) {
    assert((int)S.size() == n);

    vector<int> deg(nv, 0);
    for(li i = 0; i < (li)(n); ++i) if(S[i]) deg[es[i]^xx]++, deg[es[i]^yy]++;
    vector<bool> F(n);

    for(li i = 0; i < (li)(n); ++i) if(!S[i] && deg[es[i]^xx]+1 <= max_deg[es[i]^xx] && deg[es[i]^yy]+1 <= max_deg[es[i]^yy]) F[i] = 1;

    return F;
  }

  void exchanges(vector<bool> const& S, function<void(int,int)> f) {
    assert((int)S.size() == n);

    vector<int> deg(nv, 0);
    for(li i = 0; i < (li)(n); ++i) if(S[i]) deg[es[i]^xx]++, deg[es[i]^yy]++;

    for(li u = 0; u < (li)(n); ++u) if(S[u]) {
      deg[es[u]^xx]--, deg[es[u]^yy]--;
      for(li v = 0; v < (li)(n); ++v) if(!S[v]) {
        if(deg[es[v]^xx]+1 <= max_deg[es[v]^xx] && deg[es[v]^yy]+1 <= max_deg[es[v]^yy]) f(u,v);
      }
      deg[es[u]^xx]++, deg[es[u]^yy]++;
    }
  }
};

template<class M1, class M2>
vector<bool> matroid_inter(M1& m1, M2& m2) {
  assert(m1.n == m2.n);
  int n = m1.n;
  vector<bool> S(n, false);
  int niter=0;
  l_start:;
  { auto F1 = m1.free(S), F2 = m2.free(S);
    for(li i = 0; i < (li)(n); ++i) if(F1[i]&&F2[i]) {
      S[i]=1; goto l_start;
    }

    vvi G(n), H(n);
    m1.exchanges(S, [&](int u, int v){ G[u].push_back(v); });
    m2.exchanges(S, [&](int u, int v){ H[v].push_back(u); });

    vi from(n,-1);
    vi L,R;
    for(li i = 0; i < (li)(n); ++i) if(F1[i]) { R.push_back(i); from[i] = -2; }
    while(1) {
      if(R.empty()) return S;
      for(int i : R) {
        if(F2[i]) {
          int a = i;
          assert(!S[a]);
          S[a] = 1;
          while(from[a] != -2) {
            a = from[a];
            assert(S[a]);
            S[a] = 0;
            a = from[a];
            assert(!S[a]);
            S[a] = 1;
          }
          goto l_start;
        }
        for(int j : H[i]) {
          if(from[j] == -1) { from[j] = i; L.push_back(j); }
        }
      }
      R.clear();
      for(int i : L) {
        for(int j : G[i]) {
          if(from[j] == -1) { from[j] = i; R.push_back(j); }
        }
      }
      L.clear();
    }
  }
  return S;
}

bool A[20][20];
char ans[42][42];

void solve() {
  int n,m; cin>>n>>m;
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) {
    char c; cin>>c; A[i][j] = c != 'X';
  }
  vii es;
  vii pos;
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if(A[i][j]) {
    if(i+1<n && A[i+1][j]) { es.emplace_back(i*m+j, (i+1)*m+j); pos.emplace_back(2*i+1, 2*j); }
    if(j+1<m && A[i][j+1]) { es.emplace_back(i*m+j, i*m+(j+1)); pos.emplace_back(2*i, 2*j+1); }
  }
  GraphMatroid m1;
  m1.n = es.size(); m1.es = es; m1.nv = n*m;
  DegreeMatroid m2;
  m2.n = es.size(); m2.es = es; m2.nv = n*m;
  m2.max_deg.assign(n*m,4); for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if((i+j)%2 == 0) m2.max_deg[i*m+j] = 2;
  m2.max_deg[0] = 0;
  auto S = matroid_inter(m1,m2);
  int cnt = accumulate(begin(S), end(S),0);
  int exp = -2;
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if(A[i][j] && (i+j)%2 == 0) exp += 2;
  if(cnt != exp) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  union_find uf(n*m);
  for(li i = 0; i < (li)(es.size()); ++i) if(S[i]) {
    uf.unite(es[i]^xx, es[i]^yy);
  }
  for(li i = 0; i < (li)(es.size()); ++i) if(uf.find(es[i]^xx) != uf.find(es[i]^yy)) {
    S[i] = 1;
    uf.unite(es[i]^xx, es[i]^yy);
  }

  for(li i = 0; i < (li)(2*n-1); ++i) for(li j = 0; j < (li)(2*m-1); ++j) ans[i][j] = ' ';
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) ans[2*i][2*j] = A[i][j] ? 'O' : 'X';

  for(li i = 0; i < (li)(es.size()); ++i) if(S[i]) {
    ans[pos[i]^xx][pos[i]^yy] = 'O';
  }

  for(li i = 0; i < (li)(2*n-1); ++i) {
    for(li j = 0; j < (li)(2*m-1); ++j) cout << ans[i][j];
    cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t; for(li i = 0; i < (li)(t); ++i) solve();
  return 0;
}