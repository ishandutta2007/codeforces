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

const int N = 100001;
lli A[N],B[N],P[N];

template<class T>
using min_queue = priority_queue<T,vector<T>,greater<T>>;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin>>n>>m;
  FOR(i,n) cin>>A[i];
  FOR(j,m) cin>>B[j];
  FOR(j,m) cin>>P[j];
  min_queue<pii> Q;
  FOR(i,m) Q.push(mp(B[i],i));
  vvi R(n);
  FORD(i,n-1,0) {
    while(!Q.empty() && X(Q.top()) <= A[i]) {
      int j = Y(Q.top());
      R[i].pb(P[j]);
      Q.pop();
    }
    sort(all(R[i])); reverse(all(R[i]));
  }
  lli v = 0;

  multiset<lli> O;
  FOR(i,n) {
    v += A[i];
    while(!R[i].empty()) {
      if(R[i].back() <= v) {
        v -= R[i].back();
        O.insert(R[i].back());
        R[i].pop_back();
      }else if(!O.empty() && *rbegin(O) > R[i].back()){
        v += *rbegin(O); v -= R[i].back();
        O.erase(prev(end(O)));
        O.insert(R[i].back());
        R[i].pop_back();
      }else{
        break;
      }
    }
  }
  cout << O.size() << endl;
  return 0;
}