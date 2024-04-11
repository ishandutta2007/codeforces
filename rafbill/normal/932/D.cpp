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

const lli N = 5e5;
const lli LN = 20;

int parent[LN][N];
int parent2[LN][N];
lli mx[LN][N];
lli sm[LN][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli q; cin>>q;
  lli cnt = 1;
  lli last = 0;
  auto add = [&](lli i, lli p, lli w) {
    parent[0][i] = p;
    mx[0][i] = w;
    FOR(j,LN-1) {
      parent[j+1][i] = -1;
      mx[j+1][i] = -1;
      if(parent[j][i] != -1 && mx[j][parent[j][i]] != -1) {
        parent[j+1][i] = parent[j][parent[j][i]];
        mx[j+1][i] = max(mx[j][i],mx[j][parent[j][i]]);
      }
    }
  };
  auto add2 = [&](lli i, lli p, lli w) {
    parent2[0][i] = p;
    sm[0][i] = w;
    FOR(j,LN-1) {
      parent2[j+1][i] = -1;
      sm[j+1][i] = -1;
      if(parent2[j][i] != -1 && sm[j][parent2[j][i]] != -1) {
        parent2[j+1][i] = parent2[j][parent2[j][i]];
        sm[j+1][i] = sm[j][i] + sm[j][parent2[j][i]];
      }
    }
  };
  auto getp = [&](lli i, lli w) -> lli {
    if(i == -1) return -1;
    FORD(k,LN-1,0) if(parent[k][i] != -1 && mx[k][i] < w) {
      i = parent[k][i];
    }
    if(mx[0][i] >= w) return i;
    // FORU(k,1,LN-1) {
    //   if(mx[k][i] != -1 && mx[k][i] >= w) {
    //     i = parent[k-1][i];
    //     FORD(k2,k-2,0) if(mx[k2][i] < w) {
    //       i = parent[k2][i];
    //     }
    //     return i;
    //   }
    //   // if(parent[k-1][i] != -1) i = parent[k-1][i];
    // }
    return -1;
  };
  auto solve = [&](lli i, lli x) {
    lli ans = 0;
    lli cur = 0;
    FORD(k,LN-1,0) if(sm[k][i] != -1 && cur+sm[k][i] <= x) {
      ans += (1ll<<k);
      cur += sm[k][i];
      i = parent2[k][i];
      if(i==-1) break;
    }
    return ans;
  };
// auto solve_ = [&](lli i, lli x) {
//   cout << "solve_ " << i << " " << x << endl;
//   lli ans = 0;
//   lli cur = 0;
//   cout << parent2[0][i] << endl;
//   FORD(k,LN-1,0) if(sm[k][i] != -1) cout << k << " " << sm[k][i] << endl;
//     FORD(k,LN-1,0) if(sm[k][i] != -1 && cur+sm[k][i] <= x) {
//     ans += (1ll<<k);
//     cur += sm[k][i];
//     i = parent2[k][i];
//     if(i==-1) break;
//   }
//   return ans;
// };

add(0,-1,0);
add2(0,-1,0);
FOR(q_,q) {
  lli ty,p,q;
#ifdef LOCAL
  ty = 1+rand()%2;
  p = rand()%cnt;
  q = rand()%(100000*(ty==1?1:10));
#else
  cin>>ty>>p>>q;
  p ^= last; q ^= last;
  p -= 1;
#endif
  if(ty == 1) {
    add(cnt,p,q);
    lli r = getp(p,q);
    add2(cnt,r,q);

    // if(cnt == 278) {
    //   cout << p << " " << mx[0][p] << " " << q << " " << r << endl;
    // }
    cnt += 1;
  }else{
    // lli ans2 = 0;
    // { lli r = p;
    //   lli w = mx[0][r];
    //   lli cur = 0;
    //   while(r != -1) {
    //     if(mx[0][r] >= w) {
    //       if(cur+mx[0][r] > q) break;
    //       cur += mx[0][r];
    //       ans2 += 1;
    //       w = mx[0][r];
    //     }
    //     r = parent[0][r];
    //   }
    // }
    // lli ans = solve(p,q);
    // if(ans != ans2) {
    //   cout << "===" << endl;
    //   solve_(p,q);
    //   ans2=0;
    //   { lli r = p;
    //     lli w = mx[0][r];
    //     lli cur = 0;
    //     while(r != -1) {
    //       if(mx[0][r] >= w) {
    //         if(cur+mx[0][r] > q) break;
    //         cout << r << endl;
    //         cur += mx[0][r];
    //         ans2 += 1;
    //         w = mx[0][r];
    //       }
    //       r = parent[0][r];
    //     }
    //   }
    //   cout << ans << " " << ans2 << endl;
    //   assert(0);
    // }
    // assert(ans == ans2);
    lli ans = solve(p,q);
    cout << ans << endl;
    last=ans;
  }
}
return 0;
}