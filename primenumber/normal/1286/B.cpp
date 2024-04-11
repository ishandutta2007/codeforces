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

//using namespace harudake;

map<i32,i32> solve(const vector<vi32>& g, const vi32& c, i32 i) {
  map<i32,i32> ans;
  i32 cnt = 0;
  for(auto&&to:g[i]) {
    auto tmp = solve(g, c, to);
    if (tmp.empty()) return {};
    for(auto&&[idx,a]:tmp) {
      a += cnt;
      if (a >= c[i]) ++a;
    }
    cnt += size(tmp);
    ans.insert(all(tmp));
  }
  if (cnt < c[i]) {
    return {};
  } else {
    ans[i] = c[i];
    return ans;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n;
  cin>>n;
  vector<vi32> g(n);
  vi32 c(n);
  i32 r = -1;
  rep(i,n) {
    i32 p;
    cin>>p>>c[i];
    if (p == 0) {
      r = i;
      continue;
    }
    --p;
    g[p].push_back(i);
  }
  auto ans = solve(g, c, r);
  if (ans.empty()) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
    rep(i,n) {
      if(i)cout<<" ";
      cout<<(ans.at(i)+1);
    }
    cout<<endl;
  }
  return 0;
}