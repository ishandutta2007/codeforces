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

vi32 ones(i32 bits) {
  vi32 ans;
  while (bits) {
    i32 bit = bits & -bits;
    ans.push_back(bit);
    bits ^= bit;
  }
  reverse(all(ans));
  return ans;
}

bool solve_naive(i32 u, i32 v) {
  if (u > v) return false;
  set<i32> s;
  priority_queue<i32,vector<i32>,greater<i32>> q;
  q.push(u);
  s.insert(u);
  while (!q.empty()) {
    i32 t = q.top();
    q.pop();
    if (t == v) return true;
    rep2(i,1,t+1) {
      if ((t&i) == i) {
        i32 nx = t+i;
        if (s.count(nx)) continue;
        if (nx > v) continue;
        s.insert(nx);
        q.push(nx);
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 q;
  cin>>q;
  rep(cnt,q) {
    i32 u,v;
    cin>>u>>v;
    auto bu = ones(u);
    auto bv = ones(v);
    //bool ex = solve_naive(u, v);
    if (size(bu) < size(bv)) {
      //if (ex) {
      //  dump<<"NG: "<<u<<" "<<v<<endl;
      //}
      cout<<"NO\n";
      continue;
    }
    bool can_reduce = false;
    i32 lv = size(bv);
    i32 lu = size(bu);
    bool ok = true;
    rep(i,lv) {
      if (can_reduce) {
        if (bu[lu-lv+i] > bv[i]) ok = false;
      } else {
        if (bu[i] > bv[i]) ok = false;
        else if (bu[i] < bv[i]) can_reduce = true;
      }
    }
    if (!can_reduce && lu > lv) ok = false;
    //if (ok != ex) {
    //  dump<<"NG: "<<u<<" "<<v<<endl;
    //}
    if (ok) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  return 0;
}