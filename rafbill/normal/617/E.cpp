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

template<class T, class U>
ostream& operator<<(ostream& s, unordered_map<T, U> const& a){
  s << '[';
  auto it = a.begin();
  FOR(i, a.size()){
    s << *it;
    if(i != (lli)a.size()-1) s << " ";
    ++it;
  }
  return s << ']';
}


//------------------------------------------------------------------------------

int main(int, char**){
  ios::sync_with_stdio(false);

  lli n, m, k; cin >> n >> m >> k;
  vi B(n+1);
  FOR(i, n) cin >> B[i+1];
  FOR(i, n) B[i+1] ^= B[i];

  vii Q(m); FOR(i, m) cin >> X(Q[i]) >> Y(Q[i]);
  vi I(m); FOR(i, m) I[i] = i;
  lli sqn = sqrt(n);
  sort(begin(I), end(I), [&](lli a, lli b) {
      return mt(X(Q[a])/sqn, Y(Q[a])) < mt(X(Q[b])/sqn, Y(Q[b]));
    });

  vi R(m);

  lli curl = 0;
  lli curr = -1;
  unordered_map<lli, lli> cnt;
  lli s = 0;
  FOR(i, m) {
    lli l = X(Q[I[i]])-1;
    lli r = Y(Q[I[i]]);
    while(curr < r){
      curr += 1;
      s += cnt[k ^ B[curr]];
      cnt[B[curr]] += 1;
    }
    while(curr > r){
      cnt[B[curr]] -= 1;
      s -= cnt[k ^ B[curr]];
      curr -= 1;
    }
    while(curl < l){
      cnt[B[curl]] -= 1;
      s -= cnt[k ^ B[curl]];
      curl += 1;
    }
    while(curl > l){
      curl -= 1;
      s += cnt[k ^ B[curl]];
      cnt[B[curl]] += 1;
    }
    R[I[i]] = s;
  }

  FOR(i, m) cout << R[i] << "\n";
  cout << flush;

  return 0;
}