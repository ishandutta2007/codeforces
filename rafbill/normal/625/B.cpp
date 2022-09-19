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

// vi kmp_build(string const& A){
//   vi T; T.pb(-1);
//   FOR(i, A.size()){
//     lli b = T[i];
//     while(b != -1 && A[b] != A[i]) b = T[b];
//     T.pb(b+1);
//   }
//   return T;
// }

// lli kmp_next(vi const& T, lli i, lli x){
//   while(i != -1 && x != T[i]) i = T[i];
//   return i+1;
// }

struct node {
  unordered_map<lli, lli> nexts;
  lli back;
  unordered_set<lli> ends;
};

vector<node> aho_build(vvi const& W){
  vector<node> T; T.pb(node());
  FOR(i, W.size()){
    lli n = 0;
    for(lli c : W[i]){
      if(T[n].nexts.count(c) == 0){
        T[n].nexts[c] = T.size();
        T.pb(node());
      }
      n = T[n].nexts[c];
    }
    T[n].ends.insert(i);
  }
  // ---
  queue<lli> q; q.push(0);
  T[0].back = -1;
  while(!q.empty()){
    lli n = q.front(); q.pop();
    // Remove this line if only the largest match at each position is needed
    if(T[n].back != -1) for(auto i : T[T[n].back].ends) T[n].ends.insert(i);
    // ---
    for(auto p : T[n].nexts){
      lli b = T[n].back;
      while(b != -1 && T[b].nexts.count(p.first) == 0)
        b = T[b].back;
      T[p.second].back = (b==-1)?0:T[b].nexts[p.first];
      q.push(p.second);
    }
  }
  return T;
}

lli aho_next(vector<node>& T, lli S, lli x){
  while(S != -1 && T[S].nexts.count(x) == 0) S = T[S].back;
  return (S==-1)?0:T[S].nexts[x];
}



int main(int, char**){
  ios::sync_with_stdio(false);

  string a, b; cin >> a >> b;
  vvi b_(1); for(auto c : b) b_[0].pb(c);

  auto aut = aho_build(b_);
  lli s = 0;
  lli r = 0;
  for(auto c : a) {
    lli s_ = aho_next(aut, s, c);
    if(aut[s_].ends.size()) {
      r += 1;
      s_ = aho_next(aut, s, '#');
    }
    s = s_;
  }
  cout << r << endl;

  return 0;
}