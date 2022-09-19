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

char A[8][8];

int main(int, char**){
  ios::sync_with_stdio(false);
  FOR(i, 8) FOR(j, 8) cin >> A[i][j];
  lli cw = 10, cb = 10;
  FOR(i, 8) FOR(j, 8){
    if(A[i][j] == 'W'){
      FOR(k, i) if(A[k][j] != '.') goto a;
      cw = min(cw, i);
    }
  a:
    if(A[i][j] == 'B'){
      FORU(k, i+1, 7) if(A[k][j] != '.') goto b;
      cb = min(cb, 8-1-i);
    }
  b:;
  }
  if(cw <= cb){
    cout << "A" << endl;
  }else{
    cout << "B" << endl;
  }
  return 0;
}