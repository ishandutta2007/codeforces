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

bool A[500][500];

int main(int, char**){
  ios::sync_with_stdio(false);

  lli n, m; cin >> n >> m;
  FOR(i, m) {
    lli x, y; cin >> x >> y; x -= 1; y -= 1;
    A[x][y] = 1;
    A[y][x] = 1;
  }

  char B[500]; FOR(i, n) B[i] = 0;

  char na = 'a';
  function<void(lli, lli, char, bool)> dfs = [&](lli i, lli p, char a, bool ad) {
    if(a > 'c') {
      cout << "No" << endl;
      exit(0);
    }
    if(B[i] != 0) {
      if(abs(a-B[i]) > 1) {
        cout << "No" << endl;
        exit(0);
      }
    }
    bool diff = 0;
    FOR(j, n) if(p != j && A[i][j] && p != -1 && !A[p][j]) diff = 1;
    if(diff && !ad) a += 1;
    if(a > 'c') {
      cout << "No" << endl;
      exit(0);
    }
    B[i] = a;
    na = max<char>(na, a+2);
    FOR(j, n) if(p != j && A[i][j] && (p == -1 || (p != -1 && !A[p][j]))) {
      if(p != -1) dfs(j, i, a+1, diff || ad);
      else dfs(j, i, a, false);
    }
  };

  FOR(i, n) if(B[i] == 0) {
    FOR(j, n) if(i != j && A[i][j]) FOR(k, n) if(i != k && A[i][k] && j != k && !A[j][k]) goto l_end;
    dfs(i, -1, na, false);
  l_end:;
  }

  FOR(i, n) if(B[i] == 0) {
    cout << "No" << endl;
    return 0;
  }

  FOR(i, n) FOR(j, n) if(i != j) {
    if((A[i][j] && abs(B[i]-B[j]) > 1)
       || (!A[i][j] && abs(B[i]-B[j]) <= 1)){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  FOR(i, n) cout << B[i]; cout << endl;

  return 0;
}