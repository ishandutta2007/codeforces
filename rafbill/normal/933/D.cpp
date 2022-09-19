// #ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
// #endif
// #ifdef ONLINE_JUDGE
// #define NDEBUG 1
// #endif
// #include <stdio.h>
// #include <bits/stdc++.h>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <map>
#include <iostream>
#include <cassert>

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

#define lli long long int

// template<size_t... I>
// struct my_index_sequence {
//   using type = my_index_sequence;
//   static constexpr array<size_t, sizeof...(I)> value = { {I...} };
// };

// namespace my_index_sequence_detail {
//   template<typename I, typename J> struct concat;
//   template<size_t... I, size_t... J>
//   struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
//     my_index_sequence<I..., (sizeof...(I)+J)...> { };
//   template<size_t N> struct make_index_sequence :
//     concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
//   template <> struct make_index_sequence<0> : my_index_sequence<>{};
//   template <> struct make_index_sequence<1> : my_index_sequence<0>{};
// }

// template<class... A>
// using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

// template<class T, size_t... I>
// void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
//   using swallow = int[];
//   (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
// }

// template<class T>
// ostream& print_collection(ostream& s, T const& a);
// template<class... A>
// ostream& operator<<(ostream& s, tpl<A...> const& a);
// template<class... A>
// ostream& operator<<(ostream& s, tuple<A...> const& a);
// template<class A, class B>
// ostream& operator<<(ostream& s, pair<A, B> const& a);

// template<class T, size_t I>
// ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
// template<class T>
// ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
// template<class T, class U>
// ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
// template<class T>
// ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
// template<class T, class U>
// ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
// template<class T>
// ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

// template<class T>
// ostream& print_collection(ostream& s, T const& a){
//   s << '[';
//   for(auto it = begin(a); it != end(a); ++it){
//     s << *it;
//     if(it != prev(end(a))) s << " ";
//   }
//   return s << ']';
// }

// template<class... A>
// ostream& operator<<(ostream& s, tpl<A...> const& a){
//   s << '(';
//   print_tuple(s, a, my_index_sequence_for<A...>{});
//   return s << ')';
// }

// template<class... A>
// ostream& operator<<(ostream& s, tuple<A...> const& a){
//   s << '(';
//   print_tuple(s, a, my_index_sequence_for<A...>{});
//   return s << ')';
// }

// template<class A, class B>
// ostream& operator<<(ostream& s, pair<A, B> const& a){
//   return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
// }

//------------------------------------------------------------------------------

const lli MOD = 1e9+7;


const lli inv2 = 500000004;
const lli inv3 = 333333336;
const lli inv6 = 166666668;
const lli inv12 = 83333334;

lli nmod(lli x) { return (x%MOD+MOD)%MOD; }

struct Zn {
  lli x;
  Zn(lli x_) : x(x_) {
    x %= MOD;
    if(x<0) x = (x+MOD)%MOD;
  }

  Zn operator+(Zn const& o) const { return Zn(x+o.x); }
  Zn operator-(Zn const& o) const { return Zn(x-o.x); }
  Zn operator*(Zn const& o) const { return Zn(x*o.x); }

  Zn& operator+=(Zn const& o) { return *this = *this+o; }
  Zn& operator-=(Zn const& o) { return *this = *this-o; }
  Zn& operator*=(Zn const& o) { return *this = *this*o; }
};

Zn f2(Zn x) { return x*(x+1)*Zn(inv2); }
Zn f3(Zn x) { return x*(x+1)*(Zn(2)*x+1)*Zn(inv6); }
Zn f4(Zn x) { return x*x*(x+1)*(x+1)*Zn(inv2)*Zn(inv2); }

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli m; cin>>m;
  Zn ans = 0;

  {
    lli fr = 0;
    while(4*fr+1 <= m) {
      lli b0 = m/(4*fr+1);
      Zn b(b0);
      lli to = (m/b0-1)/4;
      // while(4*to+1>m) to--;
      Zn zfr = Zn(fr);
      Zn zto = Zn(to);
      Zn len = Zn(to-fr+1);
      { ans += (Zn(m+1)*f2(m)-f3(m))*b*len;
        ans += (Zn(m+1)*3+1)*b*(b+1)*inv12 * (Zn(0)-zfr*zfr*2+zfr+zto*zto*2+zto*3+1);
        ans += (Zn(m+1)*(b*2+1)+b*2+1)*b*(b+1)*inv12*inv3 * ((zfr-zto-1)*(zfr*zfr*16+zfr*(zto*4+1)*4+zto*zto*16+zto*20+3));
        ans += Zn(b)*(b+1)*b*(b+1)*inv12 * (zto-zfr+1)*(zfr*2+zto*2+1)*(zfr*zfr*8-zfr*4+zto*zto*8+zto*12+1);
      }
      fr = to+1;
    }
  }

  { lli fr = 0;
    while(4*fr+3 <= m) {
      lli b0 = m/(4*fr+3);
      Zn b(b0);
      lli to = (m/b0-3)/4;
      // while(4*to+3>m) to--;
      Zn zfr = Zn(fr);
      Zn zto = Zn(to);
      Zn len = Zn(to-fr+1);
      { ans -= (Zn(m+1)*f2(m)-f3(m))*b*len;
        ans -= (Zn(m+1)*3+1)*b*(b+1)*inv12 * (zto-zfr+1)*(zfr*2+zto*2+3);
        ans += (Zn(m+1)*(b*2+1) + b + (b+1))*b*(b+1)*inv12*(Zn(-16)*zfr*zfr*zfr - Zn(12) * zfr*zfr + zfr + Zn(16)*zto*zto*zto + Zn(60)*zto*zto + Zn(71)*zto + 27) * inv3;
        ans -= Zn(b)*(b+1)*b*(b+1)*inv12 * (zto-zfr+1)*(zfr*2+zto*2+3)*(zfr*zfr*8 + zfr*4 + zto*zto*8 + zto*20 + 9);
      }
      fr = to+1;
    }
  }

  cout << (Zn(m+1) * f2(m) - f3(m) + Zn(4)*ans).x%MOD << endl;

  return 0;
}

//