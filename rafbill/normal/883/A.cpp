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
  lli n,m,a,d; cin>>n>>m>>a>>d;
  vi A(m); FOR(i,m) cin>>A[i];

#ifdef LOCAL
  lli ans0 = 0;
  { vi A2 = A;
    FOR(i,n) A2.pb(i*a+a);
    sort(all(A2));
    lli to = -1;
    FOR(j,(lli)A2.size()) {
      if(A2[j]<=to) continue;
      ans0++;
      to = A2[j]+d;
    }
    cout << A2 << endl;
  }
#endif

  lli i = 1;
  lli to = -1;
  lli ans = 0;
  lli niSingle = 1+d/a;



  FOR(j,m) {
    if(A[j] <= to) continue;
  l1:;
    if(i <= n) {
      if(A[j] <= i*a) {
        ans += 1;
        to = A[j] + d;
        i = to/a+1;
      }else if(A[j] <= i*a+d){
        ans += 1;
        to = i*a+d;
        i = to/a+1;
      }else{
        auto ok = [&](lli k) {
          return A[j] <= (i+k*niSingle)*a + d;
        };
        lli lo = 1;
        lli hi = 1; while(!ok(hi)) hi=hi+hi;
        while(lo != hi) {
          lli mi = (lo+hi)/2;
          if(ok(mi)) hi = mi;
          else lo = mi+1;
        }
        if(i + niSingle * lo > n) {
          ans += (n-i+1+niSingle-1)/niSingle;
          i = n+1;
        }else{
          ans += lo;
          i += niSingle * lo;
        }
        goto l1;
      }
    } else {
      ans += 1;
      to = A[j] + d;
    }
  }
  if(i <= n) {
    ans += (n-i+1+niSingle-1)/niSingle;
  }
  cout << ans << endl;

#ifdef LOCAL
  cout << ans0 << endl;
  assert(ans == ans0);
#endif
  return 0;
}