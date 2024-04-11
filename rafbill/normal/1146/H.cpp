


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

struct pt {
  li x,y;
  void read(){
    cin>>x>>y;
  }

  bool operator<(pt const& o) const { return tie(x,y) < tie(o.x,o.y); }
  pt operator-(pt const& o) const { return pt{x-o.x,y-o.y}; }
};

ostream& operator<<(ostream& s, pt const& p) {
  return s << make_tuple(p.x,p.y);
}

li det(pt const& a, pt const& b) {
  return a.x*b.y-a.y*b.x;
}

const int N = 500;
li dp[N][N][3];

int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  li n; cin>>n;
  vector<pt> A(n);
  for(li i = 0; i < (li)(n); ++i) A[i].read();
  sort(begin(A), end(A));
  li ans = 0;
  for(li i = 0; i < (li)(n); ++i) {
    vector<pt> B;
    for(li j = (i+1); j <= (li)(n-1); ++j) {
      B.emplace_back(A[j]);
    }
    sort(begin(B), end(B), [&](pt const& p1, pt const& p2) {
      return det(p1-A[i], p2-A[i]) < 0;
    });
    li m = B.size();
    vector<vector<int>> C(m), D(m);
    for(li a = 0; a < (li)(m); ++a) {
      for(li b = 0; b < (li)(a); ++b) C[a].push_back(b);
      sort(begin(C[a]), end(C[a]), [&](int i, int j) {
        return det(B[j]-B[a],B[i]-B[a]) > 0;
      });
      for(li b = (a+1); b <= (li)(m-1); ++b) D[a].push_back(b);
      sort(begin(D[a]), end(D[a]), [&](int i, int j) { return det(B[i]-B[a],B[j]-B[a]) > 0; });
    }
    for(li a = 0; a < (li)(m+1); ++a) for(li b = 0; b < (li)(m+1); ++b) for(li k = 0; k < (li)(3); ++k) dp[a][b][k] = 0;
    for(li a = 0; a < (li)(m); ++a) for(li b = 0; b < (li)(a); ++b) dp[a][b][0] = 1;
    for(li a = 0; a < (li)(m); ++a) {
      for(li k = 0; k < (li)(2); ++k) {
        li tot = 0;
        for(li b = 0; b < (li)(a); ++b) tot += dp[a][C[a][b]][k];
        li b = a-1;
        for(li c = (a+1); c <= (li)(m-1); ++c) {
          while(b >= 0 && det(B[a]-B[C[a][b]],B[D[a][c-a-1]]-B[C[a][b]]) > 0) {
            tot -= dp[a][C[a][b]][k];
            b--;
          }
          dp[D[a][c-a-1]][a][k+1] += tot;
        }
      }
    }
    li cur = 0;
    for(li a = 0; a < (li)(m); ++a) for(li b = 0; b < (li)(a); ++b) {
      cur += dp[a][b][2];
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}