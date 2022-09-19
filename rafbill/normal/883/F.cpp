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

string red(string s) {
  string t;
  for(char c : s) {
    if(c == 'u') t += "oo";
    else t += c;
  }
  string r;
  int i = 0;
  while(i < (int)t.size()) {
    if(t[i] == 'h') {
      while(!r.empty() && r.back() == 'k') r.pop_back();
      r += 'h';
      i += 1;
    }else{
      r += t[i];
      i += 1;
    }
  }
  return r;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  set<string> S;
  FOR(i,n) {
    string s;cin>>s;
    S.insert(red(s));
  }
  cout << S.size() << endl;
  return 0;
}