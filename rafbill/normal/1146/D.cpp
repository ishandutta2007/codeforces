


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

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

li f2(li n) { return n*(n+1)/2; }

int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  li m,a,b; cin>>m>>a>>b;
  vi okfrom(a,-1);







  set<int> seen;
  li x = 0;
  li xx = 0;
  for(li y = 1; !seen.count(y*b%a); ++y) {
    seen.insert(y*b%a);
    okfrom[x] = xx;
    li r = (b-x+a-1)/a;
    r = max(r,0ll);
    r = x+r*a;

    x = (a-y*b%a)%a;
    xx = max(xx, r);
  }

  li ans = 0;
  for(li i = 0; i < (li)(a); ++i) if(okfrom[i] != -1 && okfrom[i] <= m) {
    li cur = 0;
    li lhi = (m-i)/a;
    li lo = 0, hi = (m-i)/a;
    cur += (m+1)*(hi+1);
    if(okfrom[i] == 0) {
      cur -= (lhi+1)*i;
      cur -= a * f2(lhi);
    } else {
      while(lo != hi) {
        li mi = (lo+hi+1)/2;
        if(okfrom[i] > i+mi*a) {
          lo=mi;
        }else{
          hi=mi-1;
        }
      }
      cur -= (lo+1) * okfrom[i];
      cur -= (lhi-lo) * i;
      cur -= a * (f2(lhi) - f2(lo));
    }

    ans += cur;
  }
  cout << ans << endl;
  return 0;
}