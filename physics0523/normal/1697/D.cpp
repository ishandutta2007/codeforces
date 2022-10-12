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

char ask1(int x){
  cout << "? 1 " << x+1 << '\n';
  fflush(stdout);
  string res;
  cin >> res;
  return res[0];
}

map<pair<int,int>,int> mem;
int ask2(int l,int r){
  if(mem.find({l,r})!=mem.end()){
    return mem[{l,r}];
  }

  cout << "? 2 " << l+1 << ' ' << r+1 << '\n';
  fflush(stdout);
  cin >> mem[{l,r}];
  return mem[{l,r}];
}

void ans(string s){
  cout << "! " << s << '\n';
  fflush(stdout);
}

int main(){
  int n;
  cin >> n;
  set<int> uq;
  uq.insert(0);
  UnionFind uf(n);
  for(int i=1;i<n;i++){
    int rv=ask2((*uq.begin()),i);
    if(rv>uq.size()){uq.insert(i);continue;}
    vector<int> arr;
    for(auto &nx : uq){arr.push_back(nx);}
    int sz=uq.size();

    int st=1,fi=sz-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(ask2(arr[te],i)==(sz-te)){st=te+1;}
      else{fi=te-1;}
    }
    // cout << fi << ':' << arr[fi] << '\n';
    uf.unionSet(arr[fi],i);
    uq.erase(arr[fi]);
    uq.insert(i);
    // for(auto &nx : uq){cout << nx << ' ';}cout << '\n';
  }
  map<int,char> res;
  for(int i=0;i<n;i++){
    if(i==uf.root(i)){
      res[i]=ask1(i);
    }
    // cout << uf.root(i) << '\n';
  }
  string r;
  for(int i=0;i<n;i++){
    r.push_back(res[uf.root(i)]);
  }
  ans(r);
  return 0;
}