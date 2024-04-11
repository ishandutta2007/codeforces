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

template<int... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<int, sizeof...(I)> value = { I... };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<int... I, int... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<int N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, int... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
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

template<class T, int I>
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

struct SA {
  vector<char> &S;
	int N;
  vi sa, isa, pos, tmp, lcp;

  SA(vector<char> &S_) : S(S_), N(S_.size()), sa(N), pos(N+1), tmp(N+1), lcp(N) {
		FOR(i, N) sa[i] = i, pos[i] = S[i];
		for (int gap = 1;; gap *= 2) {
      auto sufCmp = [&](int i, int j) {
        if (pos[i] != pos[j]) return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
      };
      sort(all(sa), sufCmp);
      FOR(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
      FOR(i, N) pos[sa[i]] = tmp[i];
      if (tmp[N - 1] == N - 1) break;
    }
    isa.resize(N);
    FOR(i, N) isa[sa[i]] = i;

		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1) {
        for (int j = sa[pos[i] + 1]; i+k<(int)S.size()&&j+k<(int)S.size() && S[i + k] == S[j + k];)
          k += 1;
        lcp[pos[i]] = k;
        if (k)--k;
      }
  }
};

// --- END SNIPPET SUFFIX ARRAY ---
// --- BEGIN SNIPPET RMQ ---

template<typename T = int, typename O = less<T>>
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

    int query(int a, int b){
      int d  = b-a+1;
      int ld = ilog2(d);
      if(O()(getA(a, ld), getA(b+1-(1<<ld), ld))){
        return getB(a, ld);
      }else{
        return getB(b+1-(1<<ld), ld);
      }
    }

    int query2(int a, int x) {
      int lo = a, hi = query(a, n-1);
      if(IN[hi] >= x) { return n; }
      while(lo != hi) {
        int mi = (lo+hi)/2;
        if(IN[query(lo, mi)] < x) hi = mi;
        else lo = mi+1;
      }
      return lo;
    }

    int query3(int a, int x) {
      int lo = 0, hi = a-1;
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

struct segment_tree {
  lli n;
  vector<pii> A;
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n, mt(99999999, 9999999)) { }

  void update(lli i){
    A[i] = min(A[2*i], A[2*i+1]);
  }

  void set_(lli i, lli a, lli b, lli l, lli r, pii v){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      A[i] = v;
      return;
    }
    lli c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void set(lli l, lli r, pii v){
    set_(1, 0, n-1, l, r, v);
  }

  pii query_(lli i, lli a, lli b, lli l, lli r){
    if(l > b || r < a) return mt(99999999, 9999999);
    if(l <= a && b <= r){
      return A[i];
    }
    lli c = (a+b)/2;
    return min(query_(2*i  , a  , c, l, r),
               query_(2*i+1, c+1, b, l, r));
  }

  pii query(lli l, lli r){
    return query_(1, 0, n-1, l, r);
  }
};

// --- END SNIPPET SEGMENT TREE ---



void readstring(string& s) {
  int c = 0; while((c<'a'||c>'z')) c = fgetc(stdin);
  for(;c>='a'&&c<='z';c=fgetc(stdin)) s.pb(c);
}

int readint(FILE* file = stdin) {
  int c = 0;
  while((c<'0' || c>'9') && c != '-') c = fgetc(file);
  int x = 0;
  bool neg = 0;
  if(c == '-') {
    neg = true;
    c = fgetc(file);
  }
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  if(neg) x = -x;
  return x;
}

int readposint(FILE* file = stdin) {
  int c = 0;
  while(c<'0' || c>'9') c = fgetc(file);
  int x = 0;
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  return x;
}

int main(int, char**){
  string s;
  vector<string> A;;
#ifdef LOCAL
  ofstream input("input");
  FOR(i, 500000) s.pb('a'+rand()%10);
  input << s << endl;
  int n = 5000;
  input << n << endl;
  A.resize(n);
  FOR(i, n) {
    FOR(j, 10) A[i].pb('a'+rand()%10);
  }
  FOR(i, n) input << A[i] << endl;
#else
  readstring(s);
  int n = readposint();
  A.resize(n);
  FOR(i, n) readstring(A[i]);
#endif

  vector<char> S;
  vi I;
  vi O;
  int ii = 0;
  FOR(i, n) {
    for(char c : A[i]) { S.pb(c); I.pb(ii); O.pb(i); ii += 1; }
    S.pb('$'); ii += 1; O.pb(-1);
  }
  vi T;
  for(char c : s) { S.pb(c); T.pb(ii); ii += 1; }

  SA sa(S);
  FOR(i, 10000) sa.lcp.pb(0);
  rmq<lli> RMQ(sa.lcp);

  vi II(I.size());
  FOR(i, I.size()) II[i] = sa.isa[I[i]];
  sort(all(II));
  vi NEXT(S.size(), -1);
  { int j = 0; FOR(i, I.size()) {
      while(II[i] >= j) { NEXT[j] = i; j += 1; }
    }
  }
  vi PREV(S.size(), -1);{
    int j = S.size()-1;
    FORD(i, I.size()-1, 0) {
      while(II[i] <= j) { PREV[j] = i; j -= 1; }
    }
  }

  int q;
#ifdef LOCAL
  q = 500000;
  input << q << endl;
#else
  q = readposint();
#endif

  vii QLS;
  vii QS;

  FOR(i, q) {
    int l, r, a, b;
#ifdef LOCAL
    l = rand()%n;
    r = l+min(n-1, l+rand()%5);
    a = rand()%s.size();
    b = a+rand()%(s.size()-a);
    input << l+1 << " " << r+1 << " " << a+1 << " " << b+1 << endl;
#else
    l = readposint()-1;
    r = readposint()-1;
    a = readposint()-1;
    b = readposint()-1;
#endif
    int saFrom = sa.isa[T[a]];
    int saTo   = RMQ.query2(saFrom, b-a+1);
    saFrom = RMQ.query3(saFrom, b-a+1);
    if(saTo >= (int)S.size()) saTo = S.size()-1;
    QLS.pb(mt(l, r));
    QS.pb(mt(NEXT[saFrom], PREV[saTo]));
  }

  vi J(q); iota(all(J), 0);
  sort(all(J), [&](int i, int j) {
      DESTRUCT2(QS[i], li, ri);
      DESTRUCT2(QS[j], lj, rj);
      return mt((int)sqrt(li), ri) < mt((int)sqrt(lj), rj);
    });

  segment_tree t(n);
  FOR(x, n) t.set(x,x,mt(0,x));
  vi M(n, 0);
  auto mo_add = [&](lli x) {
    M[x] += 1;
    t.set(x, x, mt(-M[x], x));
  };
  auto mo_remove = [&](lli x){
    M[x] -= 1;
    t.set(x, x, mt(-M[x], x));
  };


  vii ANS(q);
  lli cl = 0, cr = -1;
  for(int i : J) {
    DESTRUCT2(QS[i], l, r);
    DESTRUCT2(QLS[i], al, ar);
    if(l == -1 || r == -1) {
      ANS[i] = mt(0, al);
    }else{
      while(cr < r) { cr += 1; mo_add(O[sa.sa[II[cr]]]); }
      while(cl > l) { cl -= 1; mo_add(O[sa.sa[II[cl]]]); }
      while(cr > r) { mo_remove(O[sa.sa[II[cr]]]); cr -= 1; }
      while(cl < l) { mo_remove(O[sa.sa[II[cl]]]); cl += 1; }
      ANS[i] = t.query(al, ar);
    }
  }

  FOR(i, q) {
    DESTRUCT2(QLS[i], al, ar);
    printf("%d %d\n", get<1>(ANS[i])+1, -get<0>(ANS[i]));
  }

  return 0;
}