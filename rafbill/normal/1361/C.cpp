


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
template<class T>
ostream& operator<<(ostream& s, deque<T> const& a) { return print_collection(s, a); }
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

const li N = 20;
const li PN = 1ll<<N;
const li M = 600'000;

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

  bool unite(li a, li b) {
    a = find(a); b = find(b);
    A[a] = b;
    return a != b;
  }
};

li V[2*M];
li to[2*M];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  li n; cin>>n;

  union_find uf(2*n);
  for(li i = 0; i < (li)(n); ++i) {
    cin >> V[2*i] >> V[2*i+1];
    to[2*i] = to[2*i+1] = -1;
    uf.unite(2*i, 2*i+1);
  }

  li nmerged = 0;

  for(li k = (N); k >= (li)(0); --k) {
    li mask = (1ll<<k)-1;
    vector<int> A(1ll<<k, -1);
    for(li i = 0; i < (li)(2*n); ++i) if(to[i] == -1) {
      li v = V[i]&mask;
      if(A[v] == -1) {
        A[v] = i;
      }else{
        int j = A[v];
        A[v] = -1;
        to[i] = j; to[j] = i;
        if(uf.unite(i, j)) nmerged++;
      }
    }
    bool cycles = true;
    for(li i = 0; i < (li)(2*n); ++i) if(to[i] == -1) { cycles = false; break; }
    if(cycles) {
      for(li i = 0; i < (li)(2*n); ++i) {
        li v = V[i]&mask;
        if(A[v] == -1) {
          A[v] = i;
        }else{
          int j = A[v];
          if(uf.find(i) != uf.find(j)) {
            if(uf.unite(i, j)) nmerged++;
            int i2 = to[i];
            int j2 = to[j];
            to[i] = j2; to[j2] = i;
            to[j] = i2; to[i2] = j;
          }
        }
      }
      if(nmerged == n-1) {
        cout << k << endl;
        int i = 0;
        for(li k = 0; k < (li)(n); ++k) {
          cout << (i+1) << ' ' << ((i^1)+1) << ' ';
          i = to[i^1];
        }
        cout << endl;
        return 0;
      }
    }
  }

  return 0;
}