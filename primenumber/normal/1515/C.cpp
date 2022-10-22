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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,m,x;
    cin>>n>>m>>x;
    using T = pair<i32,i32>;
    priority_queue<T, vector<T>, greater<T>> q;
    rep(i,m) {
      q.emplace(0, i);
    }
    vi32 tid(n);
    rep(i,n) {
      i32 h;
      cin>>h;
      auto [th, ti] = q.top();
      q.pop();
      tid[i] = ti;
      q.emplace(th + h, ti);
    }
    cout<<"YES\n";
    rep(i,n) {
      if(i)cout<<" ";
      cout<<(tid[i]+1);
    }
    cout<<"\n";
  }
  return 0;
}