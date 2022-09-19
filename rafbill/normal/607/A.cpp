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

// double INF = 1e100;
// double EPS = 1e-12;

// struct pt {
//   double x, y;
//   pt() {}
//   pt(double x, double y) : x(x), y(y) {}
//   pt(const pt &p) : x(p.x), y(p.y)    {}
//   pt operator + (const pt &p)  const { return pt(x+p.x, y+p.y); }
//   pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
//   pt operator * (double c)     const { return pt(x*c,   y*c  ); }
//   pt operator / (double c)     const { return pt(x/c,   y/c  ); }
// };

// ostream& operator<<(ostream& s, pt const& a){
//   return s << mt(a.x, a.y);
// }

// double dot(pt p, pt q)   { return p.x*q.x+p.y*q.y; }
// double dist2(pt p, pt q) { return dot(p-q,p-q); }
// double cross(pt p, pt q) { return p.x*q.y-p.y*q.x; }

// using vpt = vector<pt>;

//------------------------------------------------------------------------------

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n; cin >> n;
  vii A(n); FOR(i, n) cin >> X(A[i]) >> Y(A[i]);
  sort(begin(A), end(A));

  vi R(n+1);
  R[0] = 0;
  lli bst = 1e9;
  FOR(i, n){
    auto it = lower_bound(begin(A), end(A), mt(X(A[i])-Y(A[i]), -1e9));
    lli j = distance(begin(A), it);
    R[i+1] = R[j] + (i-j);
    bst = min(bst, R[i+1] + n-1-i);
  }
  cout << bst << endl;

  return 0;
}