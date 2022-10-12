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
    int n;
    string s;
    cin >> n >> s;
    UnionFind uf(2*n);
    vector<vector<int>> mem(n+1);
    int h=0;
    mem[0].push_back(0);
    for(int i=0;i<2*n;i++){
      if(s[i]=='('){
        h++;
        mem[h].push_back(i+1);
      }
      else{
        mem[h].clear();
        h--;
        for(auto &nx : mem[h]){
          // cout << nx << "," << i << " ";
          uf.unionSet(nx,i);
        }
        while(mem[h].size()>1){mem[h].pop_back();}
        mem[h].push_back(i+1);
      }
    }

    int res=0;
    for(int i=0;i<2*n;i++){
      if(uf.root(i)==i){res++;}
    }
    cout << res << "\n";
  }
  return 0;
}