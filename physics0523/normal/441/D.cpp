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
  int n;
  cin >> n;
  vector<int> p(n+5);
  UnionFind uf(n+5);
  for(int i=1;i<=n;i++){
    cin >> p[i];
    uf.unionSet(i,p[i]);
  }
  int tg;
  cin >> tg;
  tg=n-tg;
  int ord=0;
  for(int i=1;i<=n;i++){
    if(uf.root(i)==i){ord++;}
  }
  bool sp=false;
  if(tg<=ord){
    cout << ord-tg << '\n';
    for(int i=1;(i<=n && tg<ord);i++){
      if(uf.findSet(1,i)){continue;}
      uf.unionSet(1,i);
      ord--;
      if(sp){cout << ' ';}
      cout << 1 << ' ' << i;
      sp=true;
    }cout << '\n';
  }
  else{
    cout << tg-ord << '\n';
    vector<vector<int>> act(n+5);
    vector<pi> cand;
    vector<bool> fl(n+5,false);
    for(int i=1;i<=n;i++){
      if(fl[i]){continue;}
      vector<int> cyc;
      int pt=i;
      while(!fl[pt]){
        cyc.push_back(pt);
        fl[pt]=true;
        pt=p[pt];
      }
      //for(auto &nx : cyc){cerr << nx << ',';}cerr << '\n';
      int sz=cyc.size();
      priority_queue<int> pq;
      for(int j=0;j<2*sz;j++){
        while(!pq.empty() && cyc[j%sz]<pq.top()){
          cand.push_back({cyc[j%sz],pq.top()});
          pq.pop();
        }
        if(j<sz){pq.push(cyc[j]);}
      }
    }
    sort(cand.begin(),cand.end());
    for(int i=0;i<(tg-ord);i++){
      if(sp){cout << ' ';}
      cout << cand[i].first << ' ' << cand[i].second;
      sp=true;
    }cout << '\n';
  }
  return 0;
}