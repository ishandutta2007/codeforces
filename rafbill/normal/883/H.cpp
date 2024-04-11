#include <bits/stdc++.h>

#define FOR(i,n) for(lli i=0;i<(lli)(n);++i)

#define X(a) get<0>(a)
#define Y(a) get<1>(a)
#define Z(a) get<2>(a)
#define W(a) get<3>(a)

#define all(x) begin(x),end(x)
#define pb push_back
#define mt make_tuple
#define mp make_pair

using namespace std;
using lli = long long int;
using vi = vector<lli>;
using pii = pair<lli,lli>;
using vvi = vector<vi>;
using vii = vector<pii>;
using vvii = vector<vii>;

template<class A,class B>
ostream& operator<<(ostream& s, pair<A,B> const& v){
  return s << '(' << X(v) << ',' << Y(v) << ')';
}

template<class A,class B>
ostream& operator<<(ostream& s, tuple<A,B> const& v){
  return s << '(' << X(v) << ',' << Y(v) << ')';
}

template<class A,class B,class C>
ostream& operator<<(ostream& s, tuple<A,B,C> const& v){
  return s << '(' << X(v) << ',' << Y(v) << ',' << Z(v) << ')';
}

template<class A>
ostream& print_col(ostream& s, A const& v);

template<class A>
ostream& operator<<(ostream& s, vector<A> const& v){ return print_col(s,v); }
template<class A>
ostream& operator<<(ostream& s, set<A> const& v){ return print_col(s,v); }
template<class A,class B>
ostream& operator<<(ostream& s, map<A,B> const& v){ return print_col(s,v); }


template<class A>
ostream& print_col(ostream& s, A const& v){
  s << '[';
  for(auto const& x : v) s << x << ' ';
  return s << ']';
}

//------------------------------------------------------------------------------

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  string s; cin>>s;
  assert((int)s.size() == n);

  map<char,int> A;
  FOR(i,n) A[s[i]] += 1;
  vector<list<char>> B;
  vector<char> Q;
  for(auto const& p : A) {
    if(p.second&1) { B.pb({p.first}); }
    FOR(j,p.second/2) Q.pb(p.first);
  }
  assert(Q.size() < 200002);
  if(B.empty()) {
    cout << 1 << endl;
    for(char c : Q) cout << c;
    reverse(all(Q));
    for(char c : Q) cout << c;
    cout << endl;
  }else{
    while(Q.size() % B.size() != 0) {
      B.pb({Q.back()});
      B.pb({Q.back()});
      Q.pop_back();
    }
    lli x = Q.size()/B.size();
    FOR(i,B.size()) {
      FOR(j,x) {
        B[i].push_front(Q.back());
        B[i].push_back(Q.back());
        Q.pop_back();
      }
    }
    cout << B.size() << endl;
    FOR(i,B.size()) {
      for(char c : B[i]) cout << c;
      cout << ' ';
    }
    cout << endl;
  }


  // map<char,int> A;
  // FOR(i,n) {
  //   char c; cin>>c;
  //   A[c] += 1;
  // }

  // lli nodd=0;
  // for(auto& p : A) if(p.second&1) nodd += 1;

  // if(nodd) {
  //   vector<deque<char>> ans;
  //   for(auto& p : A) if(p.second&1) {
  //     ans.emplace_back();
  //     ans.back().pb(p.first);
  //   }

  //   vector<char> Q;
  //   for(auto& p:A) FOR(j,p.second/2) Q.pb(p.first);

  //   while((lli)Q.size()%nodd!=0) {
  //     nodd += 2;
  //     ans.emplace_back(); ans.back().pb(Q.back());
  //     ans.emplace_back(); ans.back().pb(Q.back());
  //     Q.pop_back();
  //   }

  //   lli sz = 1+2*(Q.size()/nodd);
  //   FOR(i,nodd) while((lli)ans[i].size() < sz) {
  //     ans[i].push_back(Q.back());
  //     ans[i].push_front(Q.back());
  //     Q.pop_back();
  //   }

  //   assert(Q.empty());

  //   cout << ans.size() << endl;
  //   for(auto const& v : ans) {
  //     for(char c : v) cout << c;
  //     cout << ' ';
  //   }
  //   cout << endl;
  // }else{
  //   cout << 1 << endl;
  //   deque<char> ans;
  //   for(auto& p:A) FOR(j,p.second/2) {
  //     ans.push_front(p.first);
  //     ans.pb(p.first);
  //   }
  //   for(char c : ans) cout << c; cout << endl;
  // }
  return 0;
}