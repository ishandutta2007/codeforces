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

lli n;
lli A[100];

vvi mmult(vvi const& a, vvi const& b){
  vvi c(n, vi(n, 0));
  FOR(i, n) FOR(j, n) FOR(k, n) if(a[i][k] > 0 && b[k][j] > 0) c[i][j] = max(c[i][j], a[i][k]+b[k][j]);
  return c;
}

vvi mexp(vvi const& a, lli t){
  if(t == 1) return a;
  vvi b = mexp(a, t/2);
  vvi c = mmult(b, b);
  return (t%2==0)?c:mmult(a, c);
}

int main(int, char**){
  ios::sync_with_stdio(false);
  lli t;
  cin >> n >> t;
  FOR(i, n) cin >> A[i];
  // ---
  vvi DP(n, vi(n, 0));
  FOR(x, n) FOR(y, n) {
    lli k = 0;
    lli B[100];
    vi indice(n);
    FOR(i, n) if(A[i] >= A[x] && A[i] <= A[y]){
      lli j = upper_bound(B, B + k, A[i]) - B;
      if(j == k) {
        B[k] = A[i];
        indice[k] = i;
        ++k;
      } else if(A[i] < B[j]) {
        B[j] = A[i];
        indice[j] = i;
      }
    }
    DP[x][y] = k;
  }
  vvi R = mexp(DP, t);
  lli m = 0;
  FOR(i, n){
    FOR(j, n) m = max(m, R[j][i]);
  }
  cout << m << endl;
  return 0;
}