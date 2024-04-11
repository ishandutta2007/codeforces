#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

#define all(x) begin(x),end(x)

#define mp make_pair
#define mt make_tuple
#define pb push_back

//------------------------------------------------------------------------------

using namespace std;
using lli = long long int;
using llu = long long unsigned;

using pii   = tuple<lli, lli>;
using ppii  = tuple<pii, pii>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

//------------------------------------------------------------------------------

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B>
ostream& operator<<(ostream& s, tuple<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B, class C>
ostream& operator<<(ostream& s, tuple<A, B, C> const& a){
  return s << "(" << X(a) << "," << Y(a) << "," << Z(a) << ")";
}

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

//------------------------------------------------------------------------------

lli n, m;

bitset<1000> mask;

struct node {
  node() : bs() { }
  bitset<1000> bs;
  lli rotation = 0;
};

struct tree {
  lli n;
  vector<node> A;
  tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void print_tree_(lli i, lli a, lli b, lli in){
    push(i, a, b);
    lli c = (a+b)/2;
    if(i<n) print_tree_(2*i, a, c, in+1);
    FOR(i, in) cout << "  ";
    cout << "| " << i << " ";
    FOR(j, 20) cout << (A[i].bs[j]?1:0);
    cout << endl;
    if(i<n) print_tree_(2*i+1, c+1, b, in+1);
  }

  void print_tree(){
    print_tree_(1, 0, n-1, 0);
  }

  void push(lli i, lli a, lli b){
    if(i < n){
      lli c = (a+b)/2;
      if(A[i].rotation){
        rotate__(2*i  , a  , c, A[i].rotation);
        rotate__(2*i+1, c+1, b, A[i].rotation);
        A[i].rotation = 0;
      }
    }
  }

  void build(){
    FORD(i, n-1, 0) update(i);
  }

  void update(lli i){
    A[i].bs = A[2*i].bs | A[2*i+1].bs;
  }

  void rotate__(lli i, lli a, lli b, lli v){
    v = ((v%m)+m)%m;
    A[i].bs = ((A[i].bs<<v)|(A[i].bs>>(m-v)))&mask;
    (A[i].rotation += v) %= m;
  }

  void rotate_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      rotate__(i, a, b, v);
      return;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    rotate_(2*i  , a  , c, l, r, v);
    rotate_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void rotate(lli l, lli r, lli v){
    rotate_(1, 0, n-1, l, r, v);
  }

  bitset<1000> query_(lli i, lli a, lli b, lli l, lli r){
    if(l > b) return bitset<1000>();
    if(r < a) return bitset<1000>();
    push(i, a, b);
    if(l <= a && b <= r){
      return A[i].bs;
    }
    lli c = (a+b)/2;
    return query_(2*i  , a  , c, l, r) |
      query_(2*i+1, c+1, b, l, r);
  }

  bitset<1000> query(lli l, lli r){
    return query_(1, 0, n-1, l, r);
  }
};

vi primes;
lli SIEVE[1002];

int main(int, char**){
  FORU(i, 2, 1000) SIEVE[i] = 1;

  ios::sync_with_stdio(false);
  cin >> n >> m;
  FORU(i, 2, m-1) if(SIEVE[i]){
    primes.pb(i);
    lli k = 2;
    while(k*i<=m) {
      SIEVE[k*i] = 0;
      k += 1;
    }
  }

  FOR(i,m) mask[i] = 1;
  vi AS(n); FOR(i, n) cin >> AS[i];
  vvi A(n);
  FOR(i, n-1) {
    lli x, y; cin >> x >> y;
    x -= 1; y -= 1;
    A[x].pb(y);
    A[y].pb(x);
  }
  vi FROM(n), TO(n);
  lli t = 0;
  function<void(lli, lli)> dfs = [&](lli i, lli p){
    FROM[i] = t;
    t += 1;
    for(auto j : A[i]) if(j != p) {
        dfs(j, i);
      }
    TO[i] = t-1;
  };
  dfs(0, -1);
  tree tr(t);
  FOR(i, n) {
    tr.A[tr.n+FROM[i]].bs[AS[i]%m] = 1;
  }
  tr.build();
  lli q; cin >> q;
  FOR(i, q) {
    lli t, v; cin >> t >> v; v-=1;
    if(t == 1) {
      lli x; cin >> x;
      tr.rotate(FROM[v], TO[v], x%m);
    }else{
      auto b = tr.query(FROM[v], TO[v]);
      lli r = 0;
      for(auto p : primes) if(b[p]) r += 1;
      cout << r << endl;
    }
  }
  return 0;
}