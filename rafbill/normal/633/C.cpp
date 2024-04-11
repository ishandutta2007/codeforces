#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)

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

//------------------------------------------------------------------------------

// void occurences(vector<node>& T, vi const& A) {
//   int S = 0;
//   FOR(i, A.size()){
//     S = aho_next(T, S, A[i]);
//     for(auto p : T[S].ends){
//       cout << i << " " << p << endl;
//     }
//   }
// }

int main(int, char**){
  ios::sync_with_stdio(false);
  lli n; cin >> n; 
  string s; cin >> s;
  string t = s; reverse(all(t));
  lli m; cin >> m; 
  vector<string> ws(m); FOR(i, m) { cin >> ws[i]; }
  vvi W(m);
  FOR(i, m) {
    for(char c : ws[i]) W[i].pb(tolower(c));
  }
  auto aut = aho_build(W);
  vi E(t.size()+1, -1);
  lli st = 0;
  FOR(i, t.size()) {
    st = aho_next(aut, st, t[i]);
    for(auto j : aut[st].ends) {
      if(E[i+1 - ws[j].size()] != -1 || i+1-ws[j].size() == 0) {
        E[i+1] = j;
        break;
      }
    }
  }
  lli i = t.size();
  while(i != 0) {
    cout << ws[E[i]] << " ";
    i -= ws[E[i]].size();
  }
  cout << endl;

  return 0;
}