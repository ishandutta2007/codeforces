#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

#define mp make_pair
#define mt make_tuple
#define pb push_back

#ifdef DEBUG
#define DB(x) x
#else
#define DB(x)
#endif

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
  s << '[';
  FOR(i, a.size()){
    s << a[i];
    if(i != (lli)a.size()-1) s << " ";
  }
  return s << ']';
}

//------------------------------------------------------------------------------

pii op(pii a, char c){
  if(c == 'U') return mt(X(a)+1, Y(a));
  if(c == 'D') return mt(X(a)-1, Y(a));
  if(c == 'L') return mt(X(a), Y(a)+1);
  if(c == 'R') return mt(X(a), Y(a)-1);
}

int main(int, char**){
  ios::sync_with_stdio(false);

  lli n; cin >> n;
  string t; cin >> t;
  lli r = 0;
  FOR(i, n) FORU(j, i, n-1) {
    pii s(0, 0);
    FORU(k, i, j) s = op(s, t[k]);
    if(s == mt(0, 0)) r += 1;
  }
  cout << r << endl;

  return 0;
}