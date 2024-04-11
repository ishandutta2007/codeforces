#pragma GCC optimize ("-O3")
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define DESTRUCT2(t, x, y)                      \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);

#define DESTRUCT3(t, x, y, z)                   \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);                           \
  auto z = get<2>(t);

#define DESTRUCT4(t, x, y, z, w)                \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);                           \
  auto z = get<2>(t);                           \
  auto w = get<3>(t);

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define PE flush << "\033[2K\r"

using namespace std;
#warning lli
using lli   = int;
using llu   = long long unsigned;

using pii   = tuple<lli, lli>;
using piii  = tuple<lli, lli, lli>;
using piiii = tuple<lli, lli, lli, lli>;
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
  static constexpr array<size_t, sizeof...(I)> value = { I... };
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
  using swallow = size_t[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
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

namespace std {
  namespace {
    template <class T>
    inline void hash_combine(size_t& seed, T const& v) {
      seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
      struct HashValueImpl {
        static void apply(size_t& seed, Tuple const& tuple) {
          HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
          hash_combine(seed, get<Index>(tuple));
        }
      };
    template <class Tuple>
    struct HashValueImpl<Tuple, 0> {
      static void apply(size_t& seed, Tuple const& tuple) {
        hash_combine(seed, get<0>(tuple));
      }
    };
  }
  template <typename ... TT>
  struct hash<tuple<TT...>> {
    size_t operator()(tuple<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET SUFFIX ARRAY ---

template<typename T>
struct SA {
  T &S;
	int N;
  vi sa, isa, pos, tmp, lcp;

  SA(T &S_) : S(S_), N(S_.size()), sa(N), pos(N+1), tmp(N+1), lcp(N) {
		FOR(i, N) sa[i] = i, pos[i] = S[i];
		for(int gap = 1;; gap *= 2) {
      auto sufCmp = [&](int i, int j) {
        if(pos[i] != pos[j]) return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i<N && j<N) ? pos[i]<pos[j] : i>j;
      };
      sort(all(sa), sufCmp);
      FOR(i, N-1) tmp[i+1] = tmp[i] + sufCmp(sa[i], sa[i+1]);
      FOR(i, N) pos[sa[i]] = tmp[i];
      if(tmp[N-1] == N-1) break;
    }
    isa.resize(N);
    FOR(i, N) isa[sa[i]] = i;

		for (int i = 0, k = 0; i < N; ++i) if(pos[i] != N - 1) {
        for (int j = sa[pos[i] + 1]; i+k<(int)S.size()&&j+k<(int)S.size() && S[i+k] == S[j+k];) k += 1;
        lcp[pos[i]] = k;
        if(k) --k;
      }
  }
};

// --- END SNIPPET SUFFIX ARRAY ---

// --- BEGIN SNIPPET RMQ ---

template<typename T = int, typename O = less<T> >
struct rmq {
  static int ilog2(int x){ return 31 - __builtin_clz(x); }

  vector<T> const& IN;
  int n;
  int ln;
  vector<T> A;
  vi B;

  T& getA(int i, int j) { return A[ln*i+j]; }
  lli& getB(int i, int j) { return B[ln*i+j]; }

  rmq(vector<T> const& IN_) : IN(IN_) {
    n = IN.size();
    ln = ilog2(n)+1;
    A.resize(n*ln);
    B.resize(n*ln);
    FOR(i, n) getA(i, 0) = IN[i];
    FOR(i, n) getB(i, 0) = i;
    FOR(j, ln-1) FOR(i, n+1-(1<<(j+1))) {
      if(O()(getA(i, j), getA(i+(1<<j), j))){
        getA(i, j+1) = getA(i, j);
        getB(i, j+1) = getB(i, j);
      }else{
        getA(i, j+1) = getA(i+(1<<j), j);
        getB(i, j+1) = getB(i+(1<<j), j);
      }
    }
  }

  // O(1) : rmq between a and b (included)
  int query(int a, int b){
    int d  = b-a+1;
    int ld = ilog2(d);
    if(O()(getA(a, ld), getA(b+1-(1<<ld), ld))){
      return getB(a, ld);
    }else{
      return getB(b+1-(1<<ld), ld);
    }
  }

  // O(log n) : first elem with index >= a lower than x
  int queryLowR(int a, int x) {
    int lo = a, hi = query(a, n-1);
    if(IN[hi] >= x) { return n; }
    while(lo != hi) {
      int mi = (lo+hi)/2;
      if(IN[query(lo, mi)] < x) hi = mi;
      else lo = mi+1;
    }
    return lo;
  }

  // O(log n) : last elem with index <= a lower than x
  int queryLowL(int a, int x) {
    int lo = -1, hi = a-1;
    if(IN[hi] < x) return a;
    while(lo != hi) {
      int mi = (lo+hi+1)/2;
      if(IN[query(mi, hi)] < x) lo = mi;
      else hi = mi-1;
    }
    return lo+1;
  }

};

// --- END SNIPPET RMQ ---

// --- BEGIN SNIPPET SEGMENT TREE ---

struct segment_node {
  lli  value = 0;
  bool isset = 0;
};

struct segment_tree {
  lli n;
  vector<segment_node> A;
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void push(lli i){
    if(i < n){
      if(A[i].isset){
        set__(2*i  , A[i].value);
        set__(2*i+1, A[i].value);
        A[i].isset = 0;
      }
    }
  }

  void set__(lli i,lli v){
    A[i].value = v;
    A[i].isset = 1;
  }

  void set_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      set__(i, v);
      return;
    }
    push(i);
    lli c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v);
  }

  void set(lli l, lli r, lli v){
    set_(1, 0, n-1, l, r, v);
  }

  lli query_(lli i, lli a, lli b, lli x){
    if(a == b) return A[i].value;
    push(i);
    lli c = (a+b)/2;
    if(x <= c) return query_(2*i, a, c, x);
    else return query_(2*i+1, c+1, b, x);
  }

  lli query(lli x){
    return query_(1, 0, n-1, x);
  }
};

// --- END SNIPPET SEGMENT TREE ---

// --- BEGIN SNIPPET SEGMENT TREE ---

struct min_segment_node {
  lli sum  = numeric_limits<lli>::max();
  lli dsum = numeric_limits<lli>::max();
};

struct min_segment_tree {
  lli n;
  vector<min_segment_node> A;
  min_segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void push(lli i, lli a, lli b){
    if(i < n){
      lli c = (a+b)/2;
      if(A[i].dsum != numeric_limits<lli>::max()){
        add__(2*i  , a  , c, A[i].dsum);
        add__(2*i+1, c+1, b, A[i].dsum);
        A[i].dsum = numeric_limits<lli>::max();
      }
    }
  }

  void update(lli i){
    A[i].sum = min(A[2*i].sum, A[2*i+1].sum);
  }

  void add__(lli i, lli, lli, lli v){
    A[i].dsum = min(A[i].dsum, v);
    A[i].sum = min(A[i].sum, v);
  }

  void add_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      add__(i, a, b, v);
      return;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(lli l, lli r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  lli query_(lli i, lli a, lli b, lli l, lli r){
    if(l > b) return numeric_limits<lli>::max();
    if(r < a) return numeric_limits<lli>::max();
    if(l <= a && b <= r){
      return A[i].sum;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    return min(query_(2*i  , a  , c, l, r), query_(2*i+1, c+1, b, l, r));
  }

  lli query(lli l, lli r){
    return query_(1, 0, n-1, l, r);
  }
};

// --- END SNIPPET SEGMENT TREE ---



int depth[200000];
int size[200000];
int parent[200000];
int lfrom[200000], lcur[200000], lto[200000];
int root_cur = 0;

int main(int, char**){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  SA<string> sa(s);
  rmq<lli> R(sa.lcp);

  segment_tree t(n); t.set(0, n-1, -1);
  min_segment_tree last(n);

  lli res = 0;

  FORD(i, n-1, 0) {
    int j = sa.isa[i]; // position in sa array
    parent[i] = t.query(j);
    int p = parent[i];
    int *pcur;
    if(p != -1) {
      depth[i] = depth[p]+1;
      int lp = last.query(lfrom[p], lto[p]-1);
      // cout << lp << endl;
      size[i] = lp + size[p] - i;
      pcur = &lcur[p];
    }else{
      depth[i] = 0;
      size[i] = 1;
      pcur = &root_cur;
    }

    last.add(*pcur, *pcur, i);
    int from = R.queryLowL(j, size[i]);
    int to   = R.queryLowR(j, size[i]);
    lfrom[i] = *pcur; lcur[i] = lfrom[i]+1; lto[i] = lfrom[i] + to-from+1;
    *pcur = lto[i];

    t.set(from, to, i);
    res = max(res, depth[i]);

    // cout << i << " " << size[i] << " " << depth[i] << " " << lfrom[i] << " " << lto[i] << "\t";
    // FORU(k, i, i+size[i]-1) cout << s[k]; cout << "\t";
    // if(p != -1) {
    //   FORU(k, p, p+size[p]-1) cout << s[k]; cout << "\t";
    // }
    // cout << endl;
  }

  cout << 1+res << endl;

  return 0;
}