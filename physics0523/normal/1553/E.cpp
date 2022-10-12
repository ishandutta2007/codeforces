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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> p(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
      cin >> p[i];
      int delta=i-p[i];
      while(delta<0){delta+=n;}
      mp[delta]++;
    }

    vector<int> res;
    for(auto &nx : mp){
      int ad=nx.first;
      int ac=nx.second;
      if((ac+2*m)<n){continue;}
      UnionFind uf(n+1);
      for(int i=1;i<=n;i++){
        int orv=i-ad;
        while(orv<=0){orv+=n;}
        uf.unionSet(orv,p[i]);
      }
      int nh=0;
      for(int i=1;i<=n;i++){
        if(uf.root(i)==i){
          nh+=(uf.size(i)-1);
        }
      }
      if(nh<=m){res.push_back(ad);}
    }
    sort(res.begin(),res.end());
    cout << res.size();
    for(auto &nx : res){
      cout << ' ' << nx;
    }
    cout << '\n';
  }
  return 0;
}