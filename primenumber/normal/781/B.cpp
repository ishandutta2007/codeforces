#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vector<pair<string,string>> vp;
  REP(i,n) {
    string a,b;
    cin>>a>>b;
    vp.emplace_back(a.substr(0, 3), a.substr(0, 2) + b.substr(0, 1));
  }
  map<string,int> cnt1, cnt2;
  set<string> s;
  for(auto&&[x,y] : vp) {
    ++cnt1[x];
    ++cnt2[y];
    s.insert(x);
    s.insert(x);
  }
  vecint sel(n, 0);
  set<string> used;
  REP(i,n) {
    auto&&[x,y] = vp[i];
    if (cnt1.at(x) > 1) {
      if (sel[i] == 1) {
        cout << "NO\n";
        return 0;
      }
      sel[i] = 2;
      if (used.count(y)) {
        cout<<"NO\n";
        return 0;
      }
      used.insert(y);
    }
  }
  while (true) {
    bool updated = false;
    int none = -1;
    REP(i,n) {
      if (sel[i] > 0) continue;
      auto&&[x,y] = vp[i];
      if (used.count(x)) {
        if (used.count(y)) {
          cout<<"NO\n";
          return 0;
        } else {
          sel[i] = 2;
          used.insert(y);
          updated = true;
        }
      } else {
        if (used.count(y)) {
          sel[i] = 1;
          used.insert(x);
          updated = true;
        } else {
          none = i;
        }
      }
    }
    if (!updated) {
      if (none >= 0) {
        int i = none;
        sel[i] = 1;
        auto&&[x,y] = vp[i];
        used.insert(x);
      } else {
        break;
      }
    }
  }
  cout << "YES" << endl;
  REP(i,n) {
    if (sel[i] == 1) {
      cout<<vp[i].first<<"\n";
    } else {
      cout<<vp[i].second<<"\n";
    }
  }
  return 0;
}