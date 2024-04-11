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

const int N = 5e5;
int E[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli k,n; cin>>n>>k;
  vi A(n); FOR(i,n) cin>>A[i]; sort(all(A));
  auto ok = [&](lli x){
    FOR(i,n+1) E[i] = 0;
    E[0] = 1;
    int i0 = 0;
    int cnt0 = 0, cnt1 = 0;
    FOR(j,n) {
      while(A[j]-A[i0] > x) { if(E[i0]) cnt0 += 1; i0 += 1; }
      if(j>=(k-1)) { if(E[j-k+1]) cnt1 += 1; }
      if(cnt1>cnt0) {
        E[1+j] = 1;
      }
    }
    return E[n];
  };
  lli lo = 0, hi = 1e9;
  while(lo != hi) {
    lli mi = (lo+hi)/2;
    if(ok(mi)) {
      hi = mi;
    }else{
      lo = mi+1;
    }
  }
  cout << lo << endl;
  return 0;
}