// Complete solution (I hope)
#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

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
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> u(m),v(m);
    for(int i=0;i<m;i++){
      cin >> u[i] >> v[i];
      u[i]--;v[i]--;
    }
    int rv=1e9;
    vector<vector<int>> res;

    vector<int> p;
    for(int i=0;i<m;i++){p.push_back(i);}
    for(int tr=0;tr<2;tr++){
      UnionFind u1(n),u2(n);
      vector<vector<int>> cres(2);
      for(int i=0;i<m;i++){
        if((tr>=1 && i<=1) || u1.findSet(u[p[i]],v[p[i]])){
          u2.unionSet(u[p[i]],v[p[i]]);
          cres[1].push_back(p[i]);
        }
        else{
          u1.unionSet(u[p[i]],v[p[i]]);
          cres[0].push_back(p[i]);
        }
      }
      int crv=0;
      for(int i=0;i<n;i++){
        if(u1.root(i)==i){crv++;}
        if(u2.root(i)==i){crv++;}
      }
      if(rv>crv){
        rv=crv;
        res=cres;
      }
      p.clear();
      for(auto &nx : cres[1]){p.push_back(nx);}
      for(auto &nx : cres[0]){p.push_back(nx);}
    }
    string s;
    for(int i=0;i<m;i++){s.push_back('0');}
    for(auto &nx : res[1]){s[nx]='1';}
    cout << s << "\n";
  }
  return 0;
}