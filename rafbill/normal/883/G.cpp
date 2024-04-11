#include <bits/stdc++.h>

#define FOR(i,n) for(lli i=0;i<(n);++i)
#define FORU(i,j,k) for(lli i=(j);i<=(k);++i)
#define FORD(i,j,k) for(lli i=(j);i>=(k);--i)

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
  int n,m,s; cin>>n>>m>>s; --s;
  vvi G0(n);
  vvii G1(n);
  vi from;
  int f = 0;
  FOR(i,m) {
    int t,u,v; cin>>t>>u>>v;
    --u; --v;
    if(t == 1) {
      G0[u].pb(v);
    }else{
      from.pb(u);
      G1[u].pb(mp(v,f));
      G1[v].pb(mp(u,f));
      f++;
    }
  }

  lli cnt0=0,cnt1=0;
  vector<int> ans0(f),ans1(f);
  vi E0(f),E1(f);
  vi E(n);
  function<void(int)> dfs0 = [&](int i) {
    if(E[i]) return;
    cnt0++;
    E[i]=1;
    for(int j : G0[i]) dfs0(j);
    for(auto p : G1[i]) {
      int j,e; tie(j,e) = p;
      if(E0[e]) continue;
      E0[e] = 1;
      if(from[e] == i) ans0[e] = 1; else ans0[e] = 0;
      dfs0(j);
    }
  };
  dfs0(s);
  E.assign(n,0);
  function<void(int)> dfs1 = [&](int i) {
    if(E[i]) return;
    cnt1++;
    E[i]=1;
    for(int j : G0[i]) dfs1(j);
    for(auto p : G1[i]) {
      int j,e; tie(j,e) = p;
      if(E1[e]) continue;
      E1[e] = 1;
      if(from[e] == i) ans1[e] = 0; else ans1[e] = 1;
    }
  };
  dfs1(s);

  cout << cnt0 << endl;
  FOR(i,f) cout << (ans0[i]?'+':'-'); cout << endl;

  cout << cnt1 << endl;
  FOR(i,f) cout << (ans1[i]?'+':'-'); cout << endl;
  return 0;
}