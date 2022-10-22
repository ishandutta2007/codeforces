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

i32 n;

vi32 query(i32 r) {
  cout<<"? "<<(r+1)<<endl;
  vi32 ans(n);
  rep(i,n)cin>>ans[i];
  return ans;
}

set<pair<i32,i32>> solve(const vi32& vv, i32 v1, const vi32& d1) {
  i32 v2 = -1;
  i32 dmx = -1;
  for (auto&& idx : vv) {
    if (d1[idx] > dmx) {
      v2 = idx;
      dmx = d1[idx];
    }
  }
  auto d2 = query(v2);
  auto diam = d1[v2];
  vector<vi32> pos(diam+1);
  vi32 diam_path(diam+1, -1);
  for (auto&& i : vv) {
    i32 x = (d1[i] - d2[i] + diam) / 2;
    pos[x].push_back(i);
    if (d1[i] + d2[i] == diam) {
      diam_path[d1[i]] = i;
    }
  }
  set<pair<i32,i32>> g;
  rep(i,diam) {
    g.emplace(diam_path[i], diam_path[i+1]);
  }
  rep(i,diam+1) {
    i32 m = size(pos[i]);
    vi32 nxvv;
    vi32 d(n);
    i32 mxd = -1;
    rep(j,m) {
      i32 idx = pos[i][j];
      nxvv.push_back(idx);
      d[idx] = d1[idx] - i;
      mxd = max(mxd, d[idx]);
    }
    if (mxd > 1) {
      auto ch = solve(nxvv, diam_path[i], d);
      for (auto&& p : ch) {
        g.insert(p);
      }
    } else {
      rep(j,m) {
        i32 idx = pos[i][j];
        if (d1[idx] > i) {
          g.emplace(diam_path[i], idx);
        }
      }
    }
  }
  return g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  if (n == 2) {
    cout<<"! \n";
    cout<<"1 2"<<endl;
    return 0;
  }
  auto d0 = query(0);
  auto v1 = max_element(all(d0)) - begin(d0);
  if (n == 3) {
    cout<<"! \n";
    if (d0[v1] == 2) {
      i32 idx2 = 4 - v1;
      i32 idx3 = v1 + 1;
      cout<<"1 "<<idx2<<endl;
      cout<<idx2<<" "<<idx3<<endl;
    } else {
      cout<<"1 2"<<endl;
      cout<<"1 3"<<endl;
    }
    return 0;
  }
  auto d1 = query(v1);
  if (n <= 4) {
    auto v2 = max_element(all(d1)) - begin(d1);
    cout<<"! \n";
    if (d1[v2] == 3) {
      // path graph
      vi32 path(n);
      rep(i,n) {
        path[d1[i]] = i;
      }
      rep(i,n-1) {
        cout<<(path[i]+1)<<" "<<(path[i+1]+1)<<endl;
      }
    } else {
      i32 mid = -1;
      rep(i,n) {
        if (d1[i] == 1) mid = i;
      }
      cout<<(v1+1)<<" "<<(mid+1)<<endl;
      rep(i,n) {
        if (d1[i] == 2) {
          cout<<(mid+1)<<" "<<(i+1)<<endl;
        }
      }
    }
    return 0;
  }
  vi32 vv(n);
  rep(i,n) vv.push_back(i);
  auto g = solve(vv, v1, d1);
  vector<pair<i32,i32>> vg(all(g));
  for (auto&& [u,v] : vg) {
    if (u > v) swap(u, v);
  }
  sort(all(vg));
  cout<<"!\n";
  for (auto&& [u,v] : vg) {
    ++u;++v;
    cout<<u<<" "<<v<<"\n";
  }
  cout<<flush;
  return 0;
}