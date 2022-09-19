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

const lli N = 3e5;
lli S0[N];
lli S[N];

template<class T>
using min_queue = priority_queue<T,vector<T>,greater<T>>;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  min_queue<pii> Q;
  FOR(i,n) {
    lli a,b; cin>>a>>b;
    S0[i] = a;
    S[i]=a+b;
    Q.push(mp(S[i],i));
  }
  while(!Q.empty()) {
    lli s,i; tie(s,i) = Q.top(); Q.pop();
    if(s != S[i]) continue;
    if(i && s+1 < S[i-1]) {
      S[i-1] = s+1;
      Q.push(mp(s+1,i-1));
    }
    if(i+1 < n && s+1 < S[i+1]) {
      S[i+1] = s+1;
      Q.push(mp(s+1,i+1));
    }
  }
  lli ans=0;
  FOR(i,n) if(S[i]<S0[i]) {
    cout << -1 << endl;
    return 0;
  }else{
    ans += S[i]-S0[i];
  }
  cout << ans << endl;
  FOR(i,n) cout << S[i] << ' '; cout << endl;
  return 0;
}