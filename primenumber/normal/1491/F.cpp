#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

i32 query(const vi32& l, const vi32& r) {
  i32 sl = size(l);
  i32 sr = size(r);
  cout<<"? "<<size(l)<<" "<<size(r)<<"\n";
  rep(i,sl){
    if(i)cout<<" ";
    cout<<l[i];
  }
  cout<<"\n";
  rep(i,sr){
    if(i)cout<<" ";
    cout<<r[i];
  }
  cout<<endl;
  i32 ans;
  cin>>ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vi32 l;
    l.push_back(1);
    i32 secm = -1;
    rep2(i,1,n) {
      i32 res = query(l, {i+1});
      if (res != 0) {
        secm = i+1;
        break;
      }
      l.push_back(i+1);
    }
    vi32 ans;
    ans.push_back(secm);
    rep2(i,secm+1,n+1) {
      if (query({secm},{i}) != 0) {
        ans.push_back(i);
      }
    }
    i32 lt = 0;
    i32 ge = secm;
    while (ge - lt > 1) {
      i32 mid = (ge + lt) / 2;
      vi32 v;
      rep2(i,1,mid+1) {
        v.push_back(i);
      }
      if (query(v, {secm}) != 0) {
        ge = mid;
      } else {
        lt = mid;
      }
    }
    ans.push_back(ge);
    cout<<"! " << (n-size(ans));
    vi32 ok(n+1,1);
    for(auto&&e:ans){
      ok[e] = 0;
    }
    rep2(i,1,n+1) {
      if (ok[i]) cout<<" "<<i;
    }
    cout<<endl;
  }
  return 0;
}