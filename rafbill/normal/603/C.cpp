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

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n, k; cin >> n >> k;
  vi A(n); FOR(i, n) cin >> A[i];
  lli r = 0;
  if(k % 2 == 0){
    for(auto a : A){
      lli x;
      if(a == 0) x = 0;
      else if(a == 1) x = 1;
      else if(a == 2) x = 2;
      else x = (a+1)%2;
      r ^= x;
    }
  }else{
    for(auto a : A){
      function<lli(lli)> f = [&](lli a){
        if(a == 0) return 0;
        else if(a == 1) return 1;
        else if(a == 2) return 0;
        else if(a == 3) return 1;
        else if(a % 2 == 1) return 0;
        else {
          lli x = f(a/2);
          lli y = f(a-1);
          if(x == 0 && y == 1) return 2;
          if(y == 0 && x == 1) return 2;
          return 1;
        }
      };
      r ^= f(a);
    }
  }
  if(r != 0) cout << "Kevin"; else cout << "Nicky";
  cout << endl;
  return 0;
}