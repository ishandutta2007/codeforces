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
  lli n; cin >> n;
  string s; cin >> s;
  lli L[2][3] = {{0, 0, 0}, {0, 0, 0}};
  lli mx = 0;
  for(char c : s){
    bool b = c == '1';
    lli L_[2][3]; FOR(i, 2) FOR(j, 3) L_[i][j] = L[i][j];
    L[b][0]   = max(L_[b][0], 1+L_[1-b][0]);
    L[1-b][0] = L_[1-b][0];
    L[1-b][1] = max(1+L_[b][0], max(L_[1-b][1], 1+L_[b][1]));
    L[b][1]   = 0;
    L[b][2]   = max(max(L_[b][1], 1+L_[1-b][1]), max(L_[b][2], 1+L_[1-b][2]));
    L[1-b][2] = max(L_[1-b][1], L_[1-b][2]);
  }
  FOR(i, 2) FOR(j, 3) mx = max(mx, L[i][j]);
  cout << mx << endl;
  return 0;
}