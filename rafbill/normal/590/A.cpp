#include <algorithm>
#include <functional>
#include <utility>
#include <queue>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <complex>

#define FOR(i, n) for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)

#define mp make_pair
#define mt make_tuple
#define pb push_back

//------------------------------------------------------------------------------

using namespace std;
using lli = long long int;
using llu = long long unsigned;

using pii = tuple<lli, lli>;
using ppii = tuple<pii, pii>;
using piii = tuple<lli, lli, lli>;
using vi = vector<lli>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;
using pt = complex<lli>;

//------------------------------------------------------------------------------

template <typename T>
inline void hash_combine (size_t& seed, const T& val){
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <typename T, typename... Ts>
void hash_combine (size_t& seed, const T& val, const Ts&... args){
  hash_combine(seed,val);
  hash_combine(seed,args...);
}

void hash_combine (size_t&){}

template <typename... Ts>
size_t hash_val (const Ts&... args){
  size_t seed = 0;
  hash_combine (seed, args...);
  return seed;
}

//------------------------------------------------------------------------------

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B>
ostream& operator<<(ostream& s, tuple<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B, class C>
ostream& operator<<(ostream& s, tuple<A, B, C> const& a){
  return s << "(" << X(a) << "," << Y(a) << "," << Z(a) << ")";
}

template<class T>
ostream& operator<<(ostream& s, vector<T> const& a){
  FOR(i, a.size()){
    s << a[i];
    if(i != (lli)a.size()-1) s << " ";
  }
  return s;
}

//------------------------------------------------------------------------------

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n; cin >> n; vi A;
  lli z; cin >> z; A.pb(z); A.pb(z);
  FOR(i, n-1) { lli x; cin >> x; A.pb(x); }
  A.pb(A.back());
  vi B;
  lli i = 0;
  lli r = 0;
  n += 2;
  while(i+1 < n){
    while(i+1 < n && A[i+1] == A[i]) { B.pb(A[i]); i += 1; }
    lli j = i;
    while(j+1 < n && A[j+1] == 1-A[j]) { j += 1; }
    if(A[i] == A[j]){
      r = max(r, (j-i+1)/2);
      FOR(k, j-i+1) B.pb(A[i]);
      j += 1;
    }else{
      r = max(r, (j-i)/2);
      FOR(k, (j-i+1)/2) B.pb(A[i]);
      FOR(k, (j-i+1)/2) B.pb(A[j]);
      j += 1;
    }
    i = j;
  }
  cout << r << endl;
  FOR(i, n-2) cout << B[i+1] << " "; cout << endl;
  return 0;
}