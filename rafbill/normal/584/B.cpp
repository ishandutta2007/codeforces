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

const lli MOD = 1e9+7;

lli fexp(lli a, lli b){
  if(b == 1) return a;
  lli c = fexp(a, b/2);
  lli d = (c*c)%MOD;
  if(b % 2 == 1) (d *= a)%=MOD;
  return d;
}

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n; cin >> n;
  cout << ((fexp(27, n)-fexp(7, n))%MOD+MOD)%MOD << endl;
}