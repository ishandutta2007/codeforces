#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

void shuffle(vecint& v, const vecint& d) {
  int n = v.size();
  vecint ans(n);
  int sum = 0;
  int last = n;
  for(auto&&e: d) {
    last -= e;
    REP(i,e) {
      ans[last + i] = v[sum + i];
    }
    sum += e;
  }
  swap(v, ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vecint c(n);
  REP(i,n) cin>>c[i];
  vector<vecint> ans;
  while (!is_sorted(ALL(c))) {
    deque<tuple<int,int>> vt;
    vt.emplace_back(n+1,1);
    REP(i,n) {
      auto& [s,l] = vt.back();
      if (s + l == c[i]) {
        ++l;
      } else {
        vt.emplace_back(c[i], 1);
      }
    }
    vt.pop_front();
    int m = size(vt);
    bool ok = false;
    REP(j,m)REP(i,j) {
      if (ok) break;
      auto[si,li] = vt[i];
      auto[sj,lj] = vt[j];
      if (si == sj + lj) {
        vecint d(4);
        REP(k,i) {
          auto[sk,lk] = vt[k];
          d[0] += lk;
        }
        d[1] = li;
        FOR(k,i+1,j+1) {
          auto[sk,lk] = vt[k];
          d[2] += lk;
        }
        FOR(k,j+1,m) {
          auto[sk,lk] = vt[k];
          d[3] += lk;
        }
        d.erase(remove(ALL(d), 0), end(d));
        shuffle(c, d);
        ans.push_back(d);
        ok = true;
      }
    }
  }
  cout<<ans.size()<<"\n";
  for(auto&&d:ans) {
    int m = size(d);
    cout<<m;
    for(auto&&e:d) {
      cout<<" "<<e;
    }
    cout<<"\n";
  }
  return 0;
}