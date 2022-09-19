#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define DESTRUCT2(p, a, b)                      \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);

#define DESTRUCT3(p, a, b, c)                   \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);

#define DESTRUCT4(p, a, b, c, d)                \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);                           \
  auto d = get<3>(p);

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

//------------------------------------------------------------------------------
array<int,10> a;
int ans=0;
int L[19];
int R[19];
bool ok() {
    auto b = a;
    int i=19;
    while(L[i-1]==R[i-1]) {i-=1; if(L[i]) b[L[i]] -= 1;}
    i-=1;
    FOR(i,10) if(b[i]<0) return 0;
    int sm=0; FOR(i,10) sm+=b[i];
    FORU(x,L[i]+(i?1:0),R[i]-(i?1:0)) {
      if(b[x]>0 && i+1>=sm) return 1;
      if(x==0 && i>=sm) return 1;
    }
    { auto bl=b;
      int il=i;
      int sl=sm;
      while(il) {
        if(L[il]) {bl[L[il]]-=1; if(bl[L[il]]<0) goto l1; sl-=1;}
        il-=1;
        FORU(x,L[il]+(il?1:0),9){
          if(bl[x]>0 && il+1>=sl) return 1;
          if(x==0 && il>=sl) return 1;
        }
      }
    }
  l1:;
    { auto br=b;
      int ir=i;
      int sr=sm;
      while(ir) {
        if(R[ir]) {br[R[ir]]-=1; if(br[R[ir]]<0) return 0; sr-=1;}
        ir-=1;
        FORU(x,0,R[ir]-(ir?1:0)){
          if(br[x]>0 && ir+1>=sr) return 1;
          if(x==0 && ir>=sr) return 1;
        }
      }
    }
    return 0;
  };
void bt(int i, int r){
    if(i==10) {
      if(ok()) ans++;
      return;
    }
    FOR(j,r+1) {
      a[i]=j; bt(i+1,r-j);
      a[i]=0;
    }
  };

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  unsigned long long l,r; cin>>l>>r;
  if(l==r) {
    cout << 1 << endl;
    return 0;
  }
  FOR(i,19) {
    L[i]=l%10; l/=10;
  }
  FOR(i,19) {
    R[i]=r%10; r/=10;
  }
  a[0]=0;
  bt(1,18);
  cout << ans << endl;
  return 0;
}