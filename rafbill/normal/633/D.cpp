#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

#define all(x) begin(x),end(x)

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
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }


//------------------------------------------------------------------------------

lli A[1000];
lli F[1002];

int main(int, char**){
  F[0] = 1; F[1] = 1;
  FOR(i, 1000) F[2+i]=F[1+i]+F[i];

  ios::sync_with_stdio(false);
  lli n; cin >> n;
  FOR(i, n) cin >> A[i];

  unordered_map<lli, lli> B;
  FOR(i, n) B[A[i]] += 1;

  lli best = 2;
  if(B.count(0)) best = max(best, B[0]);
  FOR(i, n) FOR(j, n) if(i != j) {
    if(best == n) break;
    if(A[i] == 0 && A[j] == 0) continue;
    if(B.count(F[best-2]*A[i]+F[best-1]*A[j])) {
      vi C; C.pb(A[i]); C.pb(A[j]); B[A[i]] -= 1; B[A[j]] -= 1;
      lli x = A[i]; lli y = A[j]; lli cur = 2;
      while(cur < n && B.count(x+y) && B[x+y]>0) {
        C.pb(x+y);
        B[x+y] -= 1;
        y = x+y;
        x = y-x;
        cur += 1;
      }
      best = max(best, cur);
      for(auto x : C) B[x] += 1;
    }
  }
  cout << best << endl;
  return 0;
}