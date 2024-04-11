#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> x(n),y(n),tim(n);
    map<int,vector<pi>> mx;
    map<int,vector<pi>> my;
    for(int i=0;i<n;i++){
      cin >> x[i] >> y[i] >> tim[i];
      mx[x[i]].push_back({y[i],i});
      my[y[i]].push_back({x[i],i});
    }
    UnionFind uf(n);
    for(auto &nx : mx){
      vector<pi> cur=nx.second;
      sort(cur.begin(),cur.end());
      for(int i=1;i<cur.size();i++){
        if(cur[i].first-cur[i-1].first<=k){
          uf.unionSet(cur[i].second,cur[i-1].second);
        }
      }
    }
    for(auto &nx : my){
      vector<pi> cur=nx.second;
      sort(cur.begin(),cur.end());
      for(int i=1;i<cur.size();i++){
        if(cur[i].first-cur[i-1].first<=k){
          uf.unionSet(cur[i].second,cur[i-1].second);
        }
      }
    }
    vector<int> bt(n,2000000000);
    for(int i=0;i<n;i++){
      int rt=uf.root(i);
      bt[rt]=min(bt[rt],tim[i]);
    }
    vector<int> m1,m2;
    for(int i=0;i<n;i++){
      if(bt[i]<1500000000){
        m2.push_back(m1.size());
        m1.push_back(bt[i]);
      }
    }
    sort(m1.begin(),m1.end());
    reverse(m1.begin(),m1.end());
    int res=0;
    for(int i=0;i<m1.size();i++){
      res=max(res,min(m1[i],m2[i]));
    }
    cout << res << '\n';
  }
  return 0;
}