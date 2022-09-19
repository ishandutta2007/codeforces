


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

struct empty_t {};



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

struct qu {
  char ty;
  int x;
  void read(){
    cin>>ty>>x;
  }
};

int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  int n,nq; cin>>n>>nq;
  vi A(n);
  vi ans(n);
  for(li i = 0; i < (li)(n); ++i) cin>>A[i];
  vector<qu> Q(nq);
  for(li i = 0; i < (li)(nq); ++i) Q[i].read();
  reverse(begin(Q), end(Q));

  vi I(n); iota(begin(I), end(I),0); sort(begin(I), end(I),[&](int i, int j) { return A[i]<A[j]; });
  int i0 = 0, i1 = n-1;
  int sgn = 1;
  for(auto const& q : Q) {
    if(q.ty == '<') {
      if(q.x >= 0) {
        while(i0 <= i1 && abs(A[I[i0]]) >= q.x) {
          ans[I[i0]] = sgn * abs(A[I[i0]]);
          i0++;
        }
        while(i0 <= i1 && abs(A[I[i1]]) >= q.x) {
          ans[I[i1]] = sgn * abs(A[I[i1]]);
          i1--;
        }
        sgn = -sgn;
      }else{
        while(i0 <= i1 && abs(A[I[i0]]) >= -q.x+1) {
          ans[I[i0]] = sgn * abs(A[I[i0]]);
          i0++;
        }
        while(i0 <= i1 && abs(A[I[i1]]) >= -q.x+1) {
          ans[I[i1]] = sgn * abs(A[I[i1]]);
          i1--;
        }
      }
    }else{
      if(q.x <= 0) {
        while(i0 <= i1 && abs(A[I[i0]]) >= -q.x) {
          ans[I[i0]] = - sgn * abs(A[I[i0]]);
          i0++;
        }
        while(i0 <= i1 && abs(A[I[i1]]) >= -q.x) {
          ans[I[i1]] = - sgn * abs(A[I[i1]]);
          i1--;
        }
        sgn = -sgn;
      }else{
         while(i0 <= i1 && abs(A[I[i0]]) >= q.x+1) {
          ans[I[i0]] = - sgn * abs(A[I[i0]]);
          i0++;
        }
        while(i0 <= i1 && abs(A[I[i1]]) >= q.x+1) {
          ans[I[i1]] = - sgn * abs(A[I[i1]]);
          i1--;
        }
      }
    }
  }
  while(i0<=i1) {
    ans[I[i0]] = sgn * A[I[i0]];
    i0++;
  }
  for(li i = 0; i < (li)(n); ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}