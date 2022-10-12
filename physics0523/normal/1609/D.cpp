#include<bits/stdc++.h>

using namespace std;

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
  int n,q;
  cin >> n >> q;
  UnionFind uf(n);

  int ts=1,res=1;
  multiset<int> tp,gy;
  tp.insert(1);
  for(int i=1;i<n;i++){gy.insert(1);}

  for(int i=1;i<=q;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    if(uf.findSet(u,v)){ts++;}
    else{
      int us=uf.size(u);
      int vs=uf.size(v);
      if(tp.find(us)!=tp.end()){tp.erase(tp.find(us));res-=us;}
      else{gy.erase(gy.find(us));}
      if(tp.find(vs)!=tp.end()){tp.erase(tp.find(vs));res-=vs;}
      else{gy.erase(gy.find(vs));}

      uf.unionSet(u,v);
      gy.insert(uf.size(u));
    }
    while(tp.size()<ts && !gy.empty()){
      auto it=gy.end();it--;
      int send=(*it);
      res+=send;
      gy.erase(gy.find(send));
      tp.insert(send);
    }
    while(!tp.empty() && !gy.empty()){
      int tb=(*tp.begin());
      auto it=gy.end();it--;
      int ge=(*it);
      if(tb<ge){
        res-=tb;res+=ge;
        tp.erase(tp.find(tb));
        tp.insert(ge);
        gy.erase(gy.find(ge));
        gy.insert(tb);
      }
      else{break;}
    }
    cout << res-1 << '\n';
  }
  return 0;
}