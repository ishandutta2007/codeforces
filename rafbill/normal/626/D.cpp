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

lli A[2000];
lli D1[5000];
lli D2[5000];
lli S[5001];

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n; cin >> n;
  FOR(i, n) cin >> A[i];
  double w1 = 0, w2 = 0;
  FOR(i, n) FOR(j, n) {
    if(A[i] > A[j])      { D1[A[i]-A[j]] += 1; w1 += 1; }
    else if(A[j] > A[i]) { D2[A[j]-A[i]] += 1; w2 += 1; }
  }
  FOR(i, 5000) S[i+1] = S[i]+D1[i];
  lli r = 0;
  FOR(d2, 5000) FOR(d1, d2) {
    r += S[d2-d1] * D1[d1] * D2[d2];
  }
  cout << setprecision(15) << (double)r/(double)(w1*w1*w2) << endl;
  return 0;
}