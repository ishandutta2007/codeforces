#include <algorithm>
#include <fstream>
#include <iostream>
#include <cassert>
#include <iomanip>
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
#include <stack>
#include <array>

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

using pii   = tuple<lli, lli>;
using ppii  = tuple<pii, pii>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;
using vvvii = vector<vvii>;
using pt    = complex<lli>;

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

lli gcd(lli a, lli b){ return (a%b==0)?b:gcd(b, a%b); }

pii no(pii const& a){
  pii b = a;
  auto g = gcd(X(b), Y(b));
  X(b) /= g; Y(b) /= g;
  if(Y(b) < 0) { X(b) *= -1; Y(b) *= -1; }
  return b;
}

struct cmp{
  bool operator()(pii const& a, pii const& b) const{
    return X(a) * Y(b) > X(b) * Y(a);
  }
};

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n, c, d; cin >> n >> c >> d;
  map<pii, array<int, 2>, cmp> A;
  lli B[2] = {0, 0};
  FOR(i, n) {
    lli r, w; cin >> r >> w;
    r -= c; w -= d;
    if(w != 0) {
      auto a_ = no(mt(r, w));
      A[a_][w > 0] += 1;
    } else B[r > 0] += 1;
  }
  // ---
  lli R[2] = {0, 0};
  lli L[2] = {0, 0};
  lli r = 0;
  for(auto x : A) FOR(i, 2) R[i] += x.second[i];
  for(auto x : A){
    FOR(i, 2) R[i] -= x.second[i];
    FOR(i, 2) r += x.second[i] * L[1-i] * R[1-i];
    FOR(i, 2) r += x.second[i] * B[i] * L[1-i];
    FOR(i, 2) L[i] += x.second[i];
  }
  cout << r << endl;

  return 0;
}