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

// --- BEGIN SNIPPET BINARY INDEXED TREE ---

struct BIT {
  vi A;
  BIT(lli n) : A(n+1){ }

  lli get(lli i){
    i += 1;
    lli r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  lli getR(lli l, lli r) {
    lli ans = get(r);
    if(l) ans -= get(l-1);
    return ans;
  }

  void add(lli i, lli v){
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};

// --- END SNIPPET BINARY INDEXED TREE ---


lli calc(vii r, lli w) {
  sort(all(r), [&](pii const& a, pii const& b) {
      if(w < b.y() && w<a.y()) {
        return mt(a.x()*(b.y()-w),b) < mt(b.x()*(a.y()-w),a);
      }else {
        return mt(a.y(),a.x()) < mt(b.y(),b.x());
      }
    });
  lli ans=0;
  set<pii,function<bool(pii const&, pii const&)>> ALL(all(r), [&](pii const& a, pii const& b) {
      return mt(a.x()*(b.y()+w),a) > mt(b.x()*(a.y()+w),b);
    });
  lli cur = 0;
  map<pii, lli> M;
  for(auto p : ALL) {
    M[p] = cur;
    cur++;
  }
  BIT bit(cur+16);
  for(auto const& p : r) {
    lli ix = M[p];
    ans += bit.get(ix);
    bit.add(ix+1,1);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,w; cin>>n>>w;
  vii A;
  FOR(i,n) {
    lli x,v; cin>>x>>v;
    A.pb(mt(x,v));
  }


  auto norm = [&](pii& a){
    if(a.y()<0) {a.y() *= -1;a.x() *=-1;}
    if(a.x() == 0) return;
    lli g = abs(__gcd(a.x(),a.y()));
    a.x() /= g;
    a.y() /= g;
  };
  auto comp = [&](pii const& a, pii const& b) {
    lli x0 = a.x() * b.y();
    lli x1 = a.y() * b.x();
    return x0==x1?0 : (x0<x1?1:-1);
  };


  // if(w == 0) {
  //   FOR(i,n) norm(A[i]);
  //   map<pii,lli> M;
  //   FOR(i,n) M[A[i]]++;
  //   lli ans = 0;
  //   for(auto p : M) ans += (p.second*(p.second-1))/2;
  //   cout << ans << endl;
  //   return 0;
  // }

  lli ans = 0;

  { vii pos, neg;
    FOR(i,n) if(A[i].y() < 0) pos.pb(A[i]); else neg.pb(A[i]);
    for(auto& p : pos) p.y() *= -1;
    for(auto& p : neg) p.x() *= -1;
    ans += calc(pos,w);
    ans += calc(neg,w);
  }

  vector<tpl<pii,lli,lli>> evts;

  for(auto const& p : A) {
    lli x,v; tie(x,v) = p;
    pii fr, to;
    if(v>0 && v-w<0) {
      fr = mt(-(1ll<<30),1);
    }else{
      fr = mt(x,(v-w));
    }
    if(v<0 && v+w>0) {
      to = mt(1ll<<30,1);
    }else{
      to = mt(x,(v+w));
    }
    norm(fr); norm(to);
    if(comp(to,fr) == 1) swap(fr,to);
    if(v<0) {
      evts.pb(mt(fr,0,0));
      evts.pb(mt(to,1,0));
    }else{
      evts.pb(mt(fr,0,1));
      evts.pb(mt(to,1,1));
    }
  }

  vi nopen(2,0);
  sort(all(evts), [&](tpl<pii,lli,lli> const& a, tpl<pii,lli,lli> const& b) {
      if(comp(a.x(),b.x())==0) {
        return a.y()<b.y();
      }else{
        return comp(a.x(),b.x())==1;
      }
    });
  for(auto ev : evts) {
    lli ty, ki; tie(ignore,ty,ki) = ev;
    if(ty == 0) {
      ans += nopen[ki^1];
      nopen[ki]++;
    }else{
      nopen[ki]--;
    }
  }

  cout << ans << endl;

  return 0;
}